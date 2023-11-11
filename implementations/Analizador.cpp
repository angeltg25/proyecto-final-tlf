//
// Created by luisi on 9/11/2023.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "../headers/Analizador.h"

Analizador::Analizador() {
    //Inicializacion de los tokens
    palabrasReservadas.push_back(Token("for"));
    palabrasReservadas.push_back(Token("while"));
    palabrasReservadas.push_back(Token("TRUE"));
    palabrasReservadas.push_back(Token("FALSE"));
    palabrasReservadas.push_back(Token("NULL"));
    palabrasReservadas.push_back(Token("next"));
    palabrasReservadas.push_back(Token("break"));
    palabrasReservadas.push_back(Token("in"));
}

/**
 * Metodo para analizar el codigo fuente de la ruta especificada
 * @param ruta
 */
void Analizador::analizar(std::string ruta) {
    std::ifstream archivo(ruta); // Abre el archivo en modo de lectura

    if (archivo.is_open()) {
        std::vector<Token> tokensCodigoFuente;
        std::string linea; //Linea actual
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string fragmento;

            //lee cada fragmento de la linea separado por espacio y lo guarda en fragmento
            while(iss >> fragmento) {
                std::cout << "Fragmento: " << fragmento << std::endl; // Imprime cada línea del archivo
                //IMPORTANTE: para le correcta ejecucion de la funcion tokenizar()
                fragmento += " ";
                //obtenemos los tokens
                std::vector<Token> tokensLexema = tokenizar(fragmento);
                //concatenamos listas
                tokensCodigoFuente.insert(tokensCodigoFuente.end(), tokensLexema.begin(), tokensLexema.end());
            }

        }
        archivo.close(); // Cierra el archivo después de leerlo

        //Imprimimos los tokens
        std::cout << std::endl;
        for (int i = 0; i < tokensCodigoFuente.size(); ++i) {
            Token token = tokensCodigoFuente.at(i);
            std::cout << "Token identificado: "<< token.getElemento() << std::endl;
        }
        std::cout << std::endl;
        analizarTokensCodigoFuente(tokensCodigoFuente);

    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

/**
 * Metodo para obtener los tokens de un fragmento (linea del codigo fuente separado por espacio).
 * IMPORTANTE: el fragmento debe ingresar con un espacio al final de la cadena.
 * @param fragmento fragmento de la linea del codigo fuente
 * @return tokens
 */
std::vector<Token> Analizador::tokenizar(std::string fragmento) {
    std::vector<Token> tokens;
    std::string lexema;

    //Validar si hay mas de 2 caracteres
    if(fragmento.size() > 2) {
        lexema.push_back(fragmento.at(0));

        for (int i = 1; i < fragmento.size(); ++i) {
            char caracter = fragmento.at(i);

            //verificar si el caracter anterior del lexema es una letra o digito
            if (isalpha(lexema.at(lexema.size() - 1)) || isdigit(lexema.at(lexema.size() - 1))) {
                //verificar si el caracter actual tambien es una letra o digito
                if ((isalpha(caracter) || isdigit(caracter))) {
                    lexema.push_back(caracter);
                } else {
                    //lexema actual diferente a caracter o digito, es un caracter especial, se crea token
                    Token token(lexema);
                    tokens.push_back(token);
                    lexema = "";
                    lexema.push_back(caracter);
                }
            } else {
                //Verificar si el caracter actual tambien es un caracter especial
                if (!(isalpha(caracter) || isdigit(caracter))) {
                    //verifica si el caracter es un espacio (final), se crea token
                    if (std::isspace(caracter)) {
                        Token token(lexema);
                        tokens.push_back(token);
                    } else {
                        lexema.push_back(caracter);
                    }
                } else {
                    //caracter actual diferente a caracter especial, es una letra o digito, se crea token
                    Token token(lexema);
                    tokens.push_back(token);
                    lexema = "";
                    lexema.push_back(caracter);
                }
            }

        }
    } else {
        //Al solo haber un caracter, se le crea un token automaticamente
        if (fragmento.size() == 2) {
            lexema.push_back(fragmento.at(0));
            Token token(lexema);
            tokens.push_back(token);
        }
    }

    return tokens;
}

/**
 * Metodo el cual realiza el analisis de los tokens del codigo fuente y concluye
 * que es cada token.
 * @param tokensCodigoFuente
 */
void Analizador::analizarTokensCodigoFuente(std::vector<Token> tokensCodigoFuente) {
    for (int i = 0; i < tokensCodigoFuente.size(); ++i) {
        Token token = tokensCodigoFuente.at(i);

        if (verificarPalabrasReservadas(token)) {
            //imprimir que es una palabra reservada
            std::cout << "Palabra Reservada: "<< token.getElemento() << std::endl;
        } else {
            if(verificarOperadoresAritmeticos(token)) {
                //imprimir que es operador aritmetico
            }
        }
    }

}

//----------------------------UTILIDADES

/**
 * Metodo usado para verificar si el token dado es una palabra reservada
 * @param token
 * @return true si lo es, de lo contrario false
 */
bool Analizador::verificarPalabrasReservadas(Token token) {
    std::string elementoPalabraReservada;
    std::string elementoToken;

    for (int i = 0; i < palabrasReservadas.size(); ++i) {
        Token tokenPalabraReservada = palabrasReservadas.at(i);
        elementoPalabraReservada = tokenPalabraReservada.getElemento();
        elementoToken = token.getElemento();

        if (elementoPalabraReservada == elementoToken)
            return true;
    }
    return false;
}

/**
 * Metodo usado para verificar si el token dado es un operador aritmetico
 * @param token
 * @return true si lo es, de lo contrario false
 */
bool Analizador::verificarOperadoresAritmeticos(Token token) {
    return false;
}

/**
 * Metodo usado para verificar si el token dado es un identificador
 * @param token
 * @return true si lo es, de lo contrario false
 */
bool Analizador::verificarIdentificador(Token token) {
    return false;
}

