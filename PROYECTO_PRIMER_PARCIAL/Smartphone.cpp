#include "Smartphone.hpp"
#include "Input.hpp"
#include "HandleConsole.hpp"

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

int Smartphone::getAmount() {
    return this->amount;
}

void Smartphone::addSmartphoneAmount(int amountToAdd) {
    this->amount += amountToAdd;
}

void Smartphone::reduceSmartphoneAmount(int amountToRemove) {
    this->amount -= amountToRemove;
}

void Smartphone::setData() {
    const short LEFT_SPACING = 40;
    const short UP_SPACING = 5;

    Input input;
    HandleConsole console;

    console.setConsoleCursorPosition({LEFT_SPACING, UP_SPACING});
    this->mark = input.alphabetic("Ingrese la marca del celular: ", 3, 15);
    console.setConsoleCursorPosition({LEFT_SPACING, UP_SPACING + 1});
    this->model = input.alphanumeric("Ingrese el modelo del celular: ", 3, 10);
    console.setConsoleCursorPosition({LEFT_SPACING, UP_SPACING + 2});
    this->price = input.unsignedRealNumber("Ingrese el precio: ", 1, 6);
}