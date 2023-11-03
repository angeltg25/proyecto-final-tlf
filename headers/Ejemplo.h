//
// Created by luisi on 3/11/2023.
//

#ifndef PROYECTO_FINAL_TLF_EJEMPLO_H
#define PROYECTO_FINAL_TLF_EJEMPLO_H

/**
 * Definicion de la clase, atributos y funciones, es como una interface en java
 */
class Ejemplo {
private:
    //Atributos private
    int a;
    char texto[100];
public:
    //Atributos o funciones public

    /**
     * Definicion del constructor
     * @param a
     * @param texto
     */
    Ejemplo(int a, const char* texto);


    //----GETTERS & SETTERS

    int getA() const;

    void setA(int a);

    const char *getTexto() const;
};


#endif //PROYECTO_FINAL_TLF_EJEMPLO_H
