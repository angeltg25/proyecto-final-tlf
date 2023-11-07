#include <iostream>
#include "headers/Ejemplo.h"

int main() {
    Ejemplo ejemplo(1, "Hola");
    std::cout << ejemplo.getTexto() <<std::endl;
    return 0;
}
