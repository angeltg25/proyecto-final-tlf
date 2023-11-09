#include <iostream>
#include "headers/Ejemplo.h"

int main() {
    Ejemplo ejemplo(1, "Hola");
    std::cout << ejemplo.getTexto() <<std::endl;

    std::string cadena1 = "for";

    if (cadena1 == "for")
        std::cout <<"Son iguales"<<std::endl;

    

    return 0;
}
