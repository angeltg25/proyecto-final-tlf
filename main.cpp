#include <iostream>
#include <fstream>
#include "headers/Ejemplo.h"
#include "headers/Analizador.h"

int main() {
    std::string rutaArchivo = "../codigo-fuente-prueba/codigoFuente.txt";
    Analizador analizador;
    analizador.analizar(rutaArchivo);

    return 0;
}
