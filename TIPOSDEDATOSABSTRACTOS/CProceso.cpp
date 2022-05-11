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

CProceso CProceso::racional(CProceso obj1, CProceso obj2) {
    int a = obj1.getNumerador();
    int b = obj1.getDenominador();
    int c = obj2.getNumerador();
    int d = obj2.getDenominador();
    this->setNumerador((a*d) + (c*b));
    this->setDenominador(b*d);
    return *this;
}

