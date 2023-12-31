//
// Created by luisi on 9/11/2023.
//

#ifndef PROYECTO_FINAL_TLF_ANALIZADOR_H
#define PROYECTO_FINAL_TLF_ANALIZADOR_H


#include "Token.h"

class Analizador {
private:
    //Atributos
    std::vector<Token> operadoresAritmeticos;
    std::vector<Token> operadoresRelacionales;
    std::vector<Token> operadoresLogicos;
    std::vector<Token> operadoresAsignacion;
    std::vector<Token> simbolosAperturaCierre;
    std::vector<Token> separadoresSentencia;
    std::vector<Token> palabrasReservadas;
    std::vector<Token> nombresFunciones;

    //Metodos
    std::vector<Token> tokenizar(std::string fragmento);
    void analizarTokensCodigoFuente(std::vector<Token> tokensCodigoFuente);

    bool verificarOperadoresAritmeticos(Token token);
    bool verificarOperadoresRelacionales(Token token);
    bool verificarOperadoresLogicos(Token token);
    bool verificarOperadoresAsignacion(Token token);
    bool verificarSimbolosAperturaCierre(Token token);
    bool verificarSeparadoresSentencia(Token token);
    bool verificarPalabrasReservadas(Token token);
    bool verificarNombresFunciones(std::vector<Token> tokensCodigoFuente, int i);
    bool verificarIdentificador(Token token);
    bool validarIdentificador(std::string cadena, int i);
    bool verificarNumeroEntero(Token token);
    bool verificarValorCadenaCaracter(std::vector<Token> tokensCodigoFuente, int i);

public:
    //Constructor
    Analizador();

    //Metodos
    void analizar(std::string ruta);

};


#endif //PROYECTO_FINAL_TLF_ANALIZADOR_H
