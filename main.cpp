#include <iostream>
#include <fstream>
#include "headers/Ejemplo.h"
#include "headers/Analizador.h"

int main() {
    std::string rutaArchivo = "C:\\td\\datosPrueba\\codigoFuente.txt";
    Analizador analizador;
    analizador.analizar(rutaArchivo);

    return 0;
}
