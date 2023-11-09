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
        std::string linea; //Linea actual
        while (std::getline(archivo, linea)) {
            //obtiene la linea
            std::istringstream iss(linea);
            std::string lexema;

            // Leer el primer elemento de la línea (separado por espacio)
            iss >> lexema;
            std::cout << lexema << std::endl; // Imprime cada línea del archivo



            //hola
        }
        archivo.close(); // Cierra el archivo después de leerlo
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

bool Analizador::verificarIdentificador(Token token) {
    return false;
}
