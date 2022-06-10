#include "Smartphone.hpp"
#include "Input.hpp"

Smartphone::Smartphone() {
    setData();
}

Smartphone::Smartphone(char *initialMark, char *initialModel, float initialPrice) {
    this->mark = initialMark;
    this->model = initialModel;
    this->price = initialPrice;
}

char *Smartphone::getMark() {
    return this->mark;
}

char *Smartphone::getModel() {
    return this->model;
}

float Smartphone::getPrice() {
    return this->price;
}

void Smartphone::setData() {
    Input input;

    this->mark = input.alphabetic("Ingrese la marca del celular: ", 10, 15);
    this->model = input.alphanumeric("Ingrese el modelo del celular: ", 10, 15);
    this->price = input.unsignedRealNumber("Ingrese el precio: ", 1, 5);
}