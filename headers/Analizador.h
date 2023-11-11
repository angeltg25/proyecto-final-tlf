//
// Created by luisi on 9/11/2023.
//

#ifndef PROYECTO_FINAL_TLF_ANALIZADOR_H
#define PROYECTO_FINAL_TLF_ANALIZADOR_H


#include "Token.h"

class Analizador {
private:
    std::vector<Token> palabrasReservadas;
    bool verificarIdentificador(Token token);
    std::vector<Token> obtenerTokens(std::string fragmento);
public:
    Analizador();
    void analizar(std::string ruta);
};


#endif //PROYECTO_FINAL_TLF_ANALIZADOR_H
