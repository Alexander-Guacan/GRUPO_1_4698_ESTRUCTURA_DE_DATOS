#include "MenuHashString.hpp"
#include "MenuHash.hpp"
#include "..\Tools\Input.hpp"
#include <iostream>
#include <conio.h>
#include <string>

HashString MenuHashString::hashTable;

void MenuHashString::start() {
    bool exit{false};
    while (!exit) {
        MenuHash::printTitles();
        exit = switchOption(getch());
    }
}

bool MenuHashString::switchOption(char option) {
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

void MenuHashString::insertValue() {
    std::cout << "Ingrese una palabra para insertar: ";
    std::string value{Input::word(1, 10)};
    hashTable.insert(value);
}

void MenuHashString::deleteValue() {
    std::cout << "Ingrese una palabra para eliminar: ";
    std::string value{Input::word(1, 10)};

    std::cout << "\n\n";
    if (hashTable.deleteElement(value))
        std::cout << "Elemento eliminado";
    else
        std::cout << "Elemento no pudo ser eliminado";
}

void MenuHashString::searchValue() {
    std::cout << "Ingrese una palabra para buscar: ";
    std::string value{Input::word(1, 10)};
    const int ELEMENT_NOT_FOUND{-1};
    int position{hashTable.search(value)};

    std::cout << "\n\n";
    if (position != ELEMENT_NOT_FOUND)
        std::cout << "Elemento es encuentra en la posicion: " << position;
    else
        std::cout << "Elemento no pudo ser encontrado";

}

void MenuHashString::printHash() {
    system("clear");
    hashTable.print();
}