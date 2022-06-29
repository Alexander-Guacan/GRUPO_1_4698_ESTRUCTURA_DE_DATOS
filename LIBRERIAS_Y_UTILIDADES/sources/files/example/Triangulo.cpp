#include "Triangulo.hpp"

Triangulo::Triangulo(float baseInicial, float alturaInicial) {
    this->base = baseInicial;
    this->altura = alturaInicial;
}

float Triangulo::area() {
    return this->base * this->altura / 2;
}

float Triangulo::perimetro() {
    return this->base * 3;
}