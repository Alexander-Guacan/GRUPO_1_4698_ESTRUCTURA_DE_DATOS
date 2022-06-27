#include "MenuHashInt.hpp"
#include "MenuHash.hpp"
#include "..\Tools\Input.hpp"
#include <iostream>
#include <conio.h>

HashInt MenuHashInt::hashTable;

void MenuHashInt::start() {
    bool exit{false};
    while (!exit) {
        MenuHash::printTitles();
        exit = switchOption(getch());
    }
}

bool MenuHashInt::switchOption(char option) {
    std::cout << "\n\n";
    switch (option) {
        case '1':
            insertValue();
            break;

        case '2':
            deleteValue();
            break;

        case '3':
            searchValue();
            break;

        case '4':
            printHash();
            break;

        case '5':
            return true;
            break;

        case '6':
            exit(0);
            break;
    }
    std::cout << "\n\n";
    system("pause");
    return false;
}

void MenuHashInt::insertValue() {
    std::cout << "Ingrese un numero para insertar: ";
    int value{Input::unsignedIntegerNumber(1, 4)};
    hashTable.insert(value);
}

void MenuHashInt::deleteValue() {
    std::cout << "Ingrese un numero para eliminar: ";
    int value{Input::unsignedIntegerNumber(1, 4)};

    std::cout << "\n\n";
    if (hashTable.deleteElement(value))
        std::cout << "Elemento eliminado";
    else
        std::cout << "Elemento no pudo ser eliminado";
}

void MenuHashInt::searchValue() {
    std::cout << "Ingrese un numero para buscar: ";
    int value{Input::unsignedIntegerNumber(1, 4)};
    const int ELEMENT_NOT_FOUND{-1};
    int position{hashTable.search(value)};

    std::cout << "\n\n";
    if (position != ELEMENT_NOT_FOUND)
        std::cout << "Elemento es encuentra en la posicion: " << position;
    else
        std::cout << "Elemento no pudo ser encontrado";

}

void MenuHashInt::printHash() {
    system("clear");
    hashTable.print();
}