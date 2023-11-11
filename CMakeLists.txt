cmake_minimum_required(VERSION 3.26)
project(proyecto_final_tlf)

set(CMAKE_CXX_STANDARD 17)

add_executable(proyecto_final_tlf main.cpp
        implementations/Token.cpp
        headers/Token.h
        implementations/Analizador.cpp
        headers/Analizador.h)
