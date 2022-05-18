#include "Complejo.h"

Complejo::Complejo(float real, float imaginario) {
    this->parteReal = real;
    this->parteImaginaria = imaginario;
}

float Complejo::getParteReal() {
    return this->parteReal;
}

float Complejo::getParteImaginaria() {
    return this->parteImaginaria;
}

Complejo Complejo::operator+(Complejo objeto) {
    return Complejo(this->parteReal + objeto.getParteReal(), this->parteImaginaria + objeto.getParteImaginaria());
}

Complejo Complejo::operator-(Complejo objeto) {
    return Complejo(this->parteReal - objeto.getParteReal(), this->parteImaginaria - objeto.getParteImaginaria());
}