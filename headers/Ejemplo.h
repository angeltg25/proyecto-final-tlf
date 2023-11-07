//
// Created by luisi on 3/11/2023.
//

#ifndef PROYECTO_FINAL_TLF_EJEMPLO_H
#define PROYECTO_FINAL_TLF_EJEMPLO_H

#include <string>

/**
 * Definicion de la clase, atributos y funciones, es como una interface en java
 */
class Ejemplo {
private:
    //Atributos private
    int a;
    std::string texto;
public:
    //Atributos o funciones public

    /**
     * Definicion del constructor
     * @param a
     * @param texto
     */
    Ejemplo(int a, const std::string texto);


    //----GETTERS & SETTERS

    int getA() const;

    void setA(int a);

    const std::string &getTexto() const;

    void setTexto(const std::string &texto);
};


#endif //PROYECTO_FINAL_TLF_EJEMPLO_H
