//
// Created by luisi on 9/11/2023.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "../headers/Analizador.h"

Analizador::Analizador() {
    //Inicializacion de los tokens

    //Operadores aritmeticos
    operadoresAritmeticos.push_back(Token("+"));
    operadoresAritmeticos.push_back(Token("-"));
    operadoresAritmeticos.push_back(Token("*"));
    operadoresAritmeticos.push_back(Token("/"));
    operadoresAritmeticos.push_back(Token("^"));
    operadoresAritmeticos.push_back(Token("**"));
    operadoresAritmeticos.push_back(Token("%%"));
    operadoresAritmeticos.push_back(Token("%/%"));
    operadoresAritmeticos.push_back(Token("%*%"));

    //Operadores relacionales
    operadoresRelacionales.push_back(Token(">"));
    operadoresRelacionales.push_back(Token("<"));
    operadoresRelacionales.push_back(Token(">="));
    operadoresRelacionales.push_back(Token("<="));
    operadoresRelacionales.push_back(Token("=="));
    operadoresRelacionales.push_back(Token("!="));

    //Operadores logicos
    operadoresLogicos.push_back(Token("&"));
    operadoresLogicos.push_back(Token("&&"));
    operadoresLogicos.push_back(Token("|"));
    operadoresLogicos.push_back(Token("||"));
    operadoresLogicos.push_back(Token("!"));

    //Operadores de asignacion
    operadoresAsignacion.push_back(Token("<-"));
    operadoresAsignacion.push_back(Token("->"));
    operadoresAsignacion.push_back(Token("="));
    operadoresAsignacion.push_back(Token("->>"));
    operadoresAsignacion.push_back(Token("<<-"));

    //Simbolos de apertura y cierrre
    simbolosAperturaCierre.push_back(Token("{"));
    simbolosAperturaCierre.push_back(Token("}"));
    simbolosAperturaCierre.push_back(Token("("));
    simbolosAperturaCierre.push_back(Token(")"));
    simbolosAperturaCierre.push_back(Token("["));
    simbolosAperturaCierre.push_back(Token("]"));
    simbolosAperturaCierre.push_back(Token("\""));
    simbolosAperturaCierre.push_back(Token("\'"));

    //Separadores de sentencia
    separadoresSentencia.push_back(Token("."));
    separadoresSentencia.push_back(Token(","));

    //Palabras reservadas
    palabrasReservadas.push_back(Token("for"));
    palabrasReservadas.push_back(Token("while"));
    palabrasReservadas.push_back(Token("repeat"));
    palabrasReservadas.push_back(Token("if"));
    palabrasReservadas.push_back(Token("else"));
    palabrasReservadas.push_back(Token("ifelse"));
    palabrasReservadas.push_back(Token("switch"));
    palabrasReservadas.push_back(Token("case"));
    palabrasReservadas.push_back(Token("function"));
    palabrasReservadas.push_back(Token("TRUE"));
    palabrasReservadas.push_back(Token("FALSE"));
    palabrasReservadas.push_back(Token("NULL"));
    palabrasReservadas.push_back(Token("next"));
    palabrasReservadas.push_back(Token("break"));
    palabrasReservadas.push_back(Token("inf"));
    palabrasReservadas.push_back(Token("in"));
    palabrasReservadas.push_back(Token("function"));

    //Nombres de funciones
    nombresFunciones.push_back(Token("print"));
    nombresFunciones.push_back(Token("matrix"));
    nombresFunciones.push_back(Token("lenght"));
    nombresFunciones.push_back(Token("plot"));
    nombresFunciones.push_back(Token("barplot"));
    nombresFunciones.push_back(Token("plogis"));
    nombresFunciones.push_back(Token("abs"));
    nombresFunciones.push_back(Token("sqrt"));
    nombresFunciones.push_back(Token("data"));

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

            //verificar si el caracter anterior del fragmento es una letra o digito
            if (isalpha(lexema.at(lexema.size() - 1)) || isdigit(lexema.at(lexema.size() - 1))) {
                //verificar si el caracter actual tambien es una letra o digito
                if ((isalpha(caracter) || isdigit(caracter))) {
                    lexema.push_back(caracter);
                } else {
                    //caracter actual diferente a caracter o digito, es un caracter especial, se crea token
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

        if (verificarValorCadenaCaracter(tokensCodigoFuente, i)){
            //imprimir que es un valor de cadena o caracter
            std::cout << "Valor de cadena o caracter: " << token.getElemento() << std::endl;
        } else {
            if (verificarNumeroEntero(token)) {
                //imprimir que es un numero entero
                std::cout << "Numero entero: " << token.getElemento() << std::endl;
            } else {
                if (verificarPalabrasReservadas(token)) {
                    //imprimir que es una palabra reservada
                    std::cout << "Palabra Reservada: " << token.getElemento() << std::endl;
                } else {
                    if (verificarNombresFunciones(tokensCodigoFuente, i)) {
                        //imprimir que es un nombre de una funcion
                        std::cout << "Nombre de funcion: " << token.getElemento() << std::endl;
                    } else {
                        if (verificarOperadoresAritmeticos(token)) {
                            //imprimir que es operador aritmetico
                            std::cout << "Operador aritmetico: " << token.getElemento() << std::endl;
                        } else {
                            if (verificarOperadoresRelacionales(token)) {
                                //imprimir que es operador relacional
                                std::cout << "Operador relacional: " << token.getElemento() << std::endl;
                            } else {
                                if (verificarOperadoresLogicos(token)) {
                                    //imprimir que es operador logico
                                    std::cout << "Operador logico: " << token.getElemento() << std::endl;
                                } else {
                                    if (verificarOperadoresAsignacion(token)) {
                                        //imprimir que es operador de asignacion
                                        std::cout << "Operador de asignacion: " << token.getElemento() << std::endl;
                                    } else {
                                        if (verificarSimbolosAperturaCierre(token)) {
                                            //imprimir que es un simbolo de apertura o cierre
                                            std::cout << "Simbolo de apertura o cierre: " << token.getElemento()
                                                      << std::endl;
                                        } else {
                                            if (verificarSeparadoresSentencia(token)) {
                                                //imprimir que es un separador de sentencia
                                                std::cout << "Separador de sentencia: " << token.getElemento()
                                                          << std::endl;
                                            } else {
                                                if (verificarIdentificador(token)) {
                                                    //imprimir que es un identificador
                                                    std::cout << "Identificador: " << token.getElemento() << std::endl;
                                                } else {
                                                    std::cout << "TOKEN NO IDENTIFICADO: " << token.getElemento()
                                                              << std::endl;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}

//----------------------------UTILIDADES


/**
 * Metodo usado para verificar si el token dado es un operador aritmetico
 * @param token
 * @return true si lo es, de lo contrario false
 */
bool Analizador::verificarOperadoresAritmeticos(Token token) {
    std::string operadorAritmetico;
    std::string elementoToken;

    for (int i = 0; i < operadoresAritmeticos.size(); ++i) {
        Token tokenOperadorAritmetico = operadoresAritmeticos.at(i);
        operadorAritmetico = tokenOperadorAritmetico.getElemento();
        elementoToken = token.getElemento();

        if (operadorAritmetico == elementoToken)
            return true;
    }
    return false;
}

/**
 * Metodo usado para verificar si el token dado es un operador relacional
 * @param token
 * @return true si lo es, de lo contrario false
 */
bool Analizador::verificarOperadoresRelacionales(Token token) {
    std::string operadorRelacional;
    std::string elementoToken;

    for (int i = 0; i < operadoresRelacionales.size(); ++i) {
        Token tokenOperadorRelacional = operadoresRelacionales.at(i);
        operadorRelacional = tokenOperadorRelacional.getElemento();
        elementoToken = token.getElemento();

        if (operadorRelacional == elementoToken)
            return true;
    }
    return false;
}

/**
 * Metodo usado para verificar si el token dado es un operador logico
 * @param token
 * @return true si lo es, de lo contrario false
 */
bool Analizador::verificarOperadoresLogicos(Token token) {
    std::string operadorLogico;
    std::string elementoToken;

    for (int i = 0; i < operadoresLogicos.size(); ++i) {
        Token tokenOperadorLogico = operadoresLogicos.at(i);
        operadorLogico = tokenOperadorLogico.getElemento();
        elementoToken = token.getElemento();

        if (operadorLogico == elementoToken)
            return true;
    }
    return false;
}

/**
 * Metodo usado para verificar si el token dado es un operador de asignacion
 * @param token
 * @return true si lo es, de lo contrario false
 */
bool Analizador::verificarOperadoresAsignacion(Token token) {
    std::string operadorAsignacion;
    std::string elementoToken;

    for (int i = 0; i < operadoresAsignacion.size(); ++i) {
        Token tokenOperadorAsignacion = operadoresAsignacion.at(i);
        operadorAsignacion = tokenOperadorAsignacion.getElemento();
        elementoToken = token.getElemento();

        if (operadorAsignacion == elementoToken)
            return true;
    }
    return false;
}

/**
 * Metodo usado para verificar si el token dado es un simbolo de apertura o cierre
 * @param token
 * @return true si lo es, de lo contrario false
 */
bool Analizador::verificarSimbolosAperturaCierre(Token token) {
    std::string simboloAperturaCierre;
    std::string elementoToken;

    for (int i = 0; i < simbolosAperturaCierre.size(); ++i) {
        Token tokenSimboloAperturaCierre = simbolosAperturaCierre.at(i);
        simboloAperturaCierre = tokenSimboloAperturaCierre.getElemento();
        elementoToken = token.getElemento();

        if (simboloAperturaCierre == elementoToken)
            return true;
    }
    return false;
}

/**
 * Metodo usado para verificar si el token dado es un separador de sentencia
 * @param token
 * @return true si lo es, de lo contrario false
 */
bool Analizador::verificarSeparadoresSentencia(Token token) {
    std::string separadorSentencia;
    std::string elementoToken;

    for (int i = 0; i < separadoresSentencia.size(); ++i) {
        Token tokenSeparadorSentencia = separadoresSentencia.at(i);
        separadorSentencia = tokenSeparadorSentencia.getElemento();
        elementoToken = token.getElemento();

        if (separadorSentencia == elementoToken)
            return true;
    }
    return false;
}


/**
 * Metodo usado para verificar si el token dado es una palabra reservada
 * @param token
 * @return true si lo es, de lo contrario false
 */
bool Analizador::verificarPalabrasReservadas(Token token) {
    std::string palabraReservada;
    std::string elementoToken;

    for (int i = 0; i < palabrasReservadas.size(); ++i) {
        Token tokenPalabraReservada = palabrasReservadas.at(i);
        palabraReservada = tokenPalabraReservada.getElemento();
        elementoToken = token.getElemento();

        if (palabraReservada == elementoToken)
            return true;
    }
    return false;
}


bool Analizador::verificarNombresFunciones(std::vector<Token> tokensCodigoFuente, int i) {
    std::string nombreFuncion;
    std::string elementoToken;

    if ((i+1) < tokensCodigoFuente.size()) {
        Token tokenActual = tokensCodigoFuente.at(i);
        Token tokenSiguiente = tokensCodigoFuente.at(i+1);

        if (tokenSiguiente.getElemento() == "(") {
            for (int k = 0; k < nombresFunciones.size(); ++k) {
                Token tokenNombreFuncion = nombresFunciones.at(k);
                nombreFuncion = tokenNombreFuncion.getElemento();
                elementoToken = tokenActual.getElemento();

                if (nombreFuncion == elementoToken)
                    return true;
            }
            return false;
        } else {
            return false;
        }
    }
    return false;
}


/**
 * Llama al metodo valdiarIdentificador y verifica si el token es un identificador
 * @param token
 * @return true si lo es, de lo contrario false
 */
bool Analizador::verificarIdentificador(Token token) {
    return validarIdentificador(token.getElemento(), 0);
}


/**
 * Metodo usado para verificar y validar si la cadena dada tiene un patron de identificador
 * @param cadena
 * @param i
 * @return true si es un identificador, de lo contrario false
 */
bool Analizador::validarIdentificador(std::string cadena, int i) {
    if (i > cadena.length()-1)
        return true;
    char c = cadena.at(i);

    if (i == 0 && c != '.') {
        if (isdigit(c) || !isalpha(c))
            return false;
    }
    if (c != '_' && !isalpha(c))
        return false;
    return validarIdentificador(cadena, i+1);
}


/**
 * Metodo usado para verificar si el token dado es un numero entero
 * @param token
 * @return true si lo es, de lo contrario false
 */
bool Analizador::verificarNumeroEntero(Token token) {
    std::string cadena = token.getElemento();

    try {
        std::stoi(cadena);
        return true;
    } catch (const std::invalid_argument &) {
        return false;
    } catch (const std::out_of_range &) {
        return false;
    }
}

/**
 * Verifica si un entre comillas dobles o simples hay un valor de cadena, no aplica si
 * lo que hay entre estos caracteres esta separado por espacio
 * @param tokensCodigoFuente
 * @param i pos del vector tokensCodigoFuente
 * @return true si el valor entre las comillas simples o dobles es cadena o caracter, de lo contrario false
 */
bool Analizador::verificarValorCadenaCaracter(std::vector<Token> tokensCodigoFuente, int i) {
    if(i > 0 && (i+1) < tokensCodigoFuente.size()){
        Token tokenAnterior = tokensCodigoFuente.at(i-1);
        Token tokenSiguiente = tokensCodigoFuente.at(i+1);

        if ((tokenAnterior.getElemento() == "\"" || tokenAnterior.getElemento() == "\'") &&
            (tokenSiguiente.getElemento() == "\"" || tokenSiguiente.getElemento() == "\'"))
            return true;
        return false;
    }
    return false;
}
