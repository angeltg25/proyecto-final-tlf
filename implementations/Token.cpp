//
// Created by luisi on 9/11/2023.
//

#include "../headers/Token.h"

Token::Token(std::string elemento) {
    this->elemento = elemento;
}

const std::string &Token::getElemento() const {
    return elemento;
}

void Token::setElemento(const std::string &elemento) {
    Token::elemento = elemento;
}


