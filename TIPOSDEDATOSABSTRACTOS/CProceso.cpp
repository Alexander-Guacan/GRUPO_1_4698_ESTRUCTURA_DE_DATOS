#include "CProceso.h"
#include <iostream>

CProceso::CProceso(int numerador, int denominador) {
    this->numerador = numerador;
    this->denominador = denominador;
}

void CProceso::setNumerador(int numerador) {
    this->numerador = numerador;
}

void CProceso::setDenominador(int denominador) {
    this->denominador = denominador;
}

int CProceso::getNumerador() {
    return numerador;
}

int CProceso::getDenominador() {
    return denominador;
}