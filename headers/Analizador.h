//
// Created by luisi on 9/11/2023.
//

#ifndef PROYECTO_FINAL_TLF_ANALIZADOR_H
#define PROYECTO_FINAL_TLF_ANALIZADOR_H


#include "Token.h"

class Analizador {
private:
    //Atributos
    std::vector<Token> palabrasReservadas;

    //Metodos
    std::vector<Token> tokenizar(std::string fragmento);
    void analizarTokensCodigoFuente(std::vector<Token> tokensCodigoFuente);
    bool verificarPalabrasReservadas(Token token);
    bool verificarOperadoresAritmeticos(Token token);
    bool verificarIdentificador(Token token);
public:
    //Constructor
    Analizador();

    //Metodos
    void analizar(std::string ruta);

};


#endif //PROYECTO_FINAL_TLF_ANALIZADOR_H
