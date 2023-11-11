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

void Analizador::analizar(std::string ruta) {
    std::ifstream archivo(ruta); // Abre el archivo en modo de lectura

    if (archivo.is_open()) {
        std::vector<Token> tokensCodigoFuente;
        std::string linea; //Linea actual
        while (std::getline(archivo, linea)) {
            //obtiene la linea
            std::istringstream iss(linea);
            std::string lexema;

            //lee cada elemento de la linea separado por espacio y lo guarda en lexema
            while(iss >> lexema) {
                std::cout << "Lexema: "<< lexema << std::endl; // Imprime cada línea del archivo
                //IMPORTANTE: para le correcta ejecucion de la funcion obtenerTokens()
                lexema += " ";
                //obtenemos los tokens
                std::vector<Token> tokensLexema = obtenerTokens(lexema);
                //concatenamos listas
                tokensCodigoFuente.insert(tokensCodigoFuente.end(), tokensLexema.begin(), tokensLexema.end());
            }

        }
        archivo.close(); // Cierra el archivo después de leerlo

        //Imprimimos los tokens
        for (int i = 0; i < tokensCodigoFuente.size(); ++i) {
            Token token = tokensCodigoFuente.at(i);
            std::cout << "Token identificado: "<< token.getElemento() << std::endl;
        }

    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

bool Analizador::verificarIdentificador(Token token) {
    return false;
}

std::vector<Token> Analizador::obtenerTokens(std::string lexema) {
    std::vector<Token> tokens;
    std::string elemento;

    //Validar si hay mas de 2 caracteres
    if(lexema.size() > 2) {
        elemento.push_back(lexema.at(0));

        for (int i = 1; i < lexema.size(); ++i) {
            char caracter = lexema.at(i);

            //verificar si el elemento anterior es una letra o digito
            if (isalpha(elemento.at(elemento.size()-1)) || isdigit(elemento.at(elemento.size()-1))) {
                //verificar si el elemento actual tambien es una letra o digito
                if ((isalpha(caracter) || isdigit(caracter))){
                    elemento.push_back(caracter);
                } else {
                    //elemento actual diferente a caracter o digito, es un caracter especial, se crea token
                    Token token(elemento);
                    tokens.push_back(token);
                    elemento = "";
                    elemento.push_back(caracter);
                }

            } else {
                //Verificar si el caracter actual tambien es un caracter especial
                if (!(isalpha(caracter) || isdigit(caracter))){
                    if (std::isspace(caracter)){
                        Token token(elemento);
                        tokens.push_back(token);
                    } else {
                        elemento.push_back(caracter);
                    }
                } else {
                    //elemento actual diferente a caracter especial, es una letra o digito, se crea token
                    Token token(elemento);
                    tokens.push_back(token);
                    elemento = "";
                    elemento.push_back(caracter);
                }
            }

        }
    } else {
        //Al solo haber un caracter, se le crea un token automaticamente
        if (lexema.size() == 2){
            elemento.push_back(lexema.at(0));
            Token token(elemento);
            tokens.push_back(token);
        }
    }

    return tokens;
}


