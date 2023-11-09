//
// Created by luisi on 9/11/2023.
//

#ifndef PROYECTO_FINAL_TLF_TOKEN_H
#define PROYECTO_FINAL_TLF_TOKEN_H


#include <string>
#include <vector>

class Token {
private:
    std::string tipo;
    std::vector<std::string> listaElementos;

public:
    Token();
    verificarElemento();
};


#endif //PROYECTO_FINAL_TLF_TOKEN_H
