#include "Cuadrado.hpp"

Cuadrado::Cuadrado(int ladoInicial) {
    this->lado = ladoInicial;
}

float Cuadrado::area() {
    return this->lado * this->lado;
}

float Cuadrado::perimetro() {
    return this->lado * 4;
}