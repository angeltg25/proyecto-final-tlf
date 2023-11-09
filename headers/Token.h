//
// Created by luisi on 9/11/2023.
//

#ifndef PROYECTO_FINAL_TLF_TOKEN_H
#define PROYECTO_FINAL_TLF_TOKEN_H


#include <string>
#include <vector>

class Token {
private:
    std::string elemento;

public:
    Token(std::string elemento);

    const std::string &getElemento() const;

    void setElemento(const std::string &elemento);
};


#endif //PROYECTO_FINAL_TLF_TOKEN_H
