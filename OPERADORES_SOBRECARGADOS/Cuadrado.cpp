#include "Cuadrado.h"
#include <iostream>
#include <cstdio>
#include <conio.h>

void Cuadrado ::leer(void){
    std :: cout << "Ingrese Lado: " ;
    std :: cin >> this->lado;
    this->area = lado*lado;
    this->perimetro = lado * (float)4;
}

void Cuadrado ::imprimeArea (void){
    std ::cout << "Area: " << this->area << std::endl;
}

void Cuadrado ::imprimePerimetro (void){
    std :: cout << "Perimetro: " << this->perimetro << std::endl;
}

void Cuadrado ::imprimeAreaYPerimetro (void){
    imprimeArea();
    imprimePerimetro();
}


Cuadrado Cuadrado :: operator+  (Cuadrado D){
    Cuadrado aux;
    aux.setArea(this->getArea() + D.getArea());
    aux.setPerimetro(this->getPerimetro() + D.getPerimetro());

    return aux;
}

float Cuadrado::getArea() {
    return this->area;
}

float Cuadrado::getPerimetro() {
    return this->perimetro;
}

void Cuadrado::setArea(float area) {
    this->area = area;
}

void Cuadrado::setPerimetro(float perimetro) {
    this->perimetro = perimetro;
}