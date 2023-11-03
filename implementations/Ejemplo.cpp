//
// Created by luisi on 3/11/2023.
//

#include <cstring>
#include "../headers/Ejemplo.h"

/**
 * Implementacion construtor definido en Ejemplo.h
 * @param a
 * @param texto
 */
Ejemplo::Ejemplo(int a, const char *texto) {
    //pasar el contenido de texto (parametro) a texto (array de la clase)
    strcpy(this->texto, texto);
    this->a = a;
}

//----GETTERS & SETTERS

int Ejemplo::getA() const {
    return a;
}

void Ejemplo::setA(int a) {
    Ejemplo::a = a;
}

const char *Ejemplo::getTexto() const {
    return texto;
}
