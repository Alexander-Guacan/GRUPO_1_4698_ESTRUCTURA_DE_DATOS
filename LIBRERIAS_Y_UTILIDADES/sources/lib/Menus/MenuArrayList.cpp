#include "MenuArrayList.hpp"
#include "..\Collection\ArrayList.hpp"
#include "..\Tools\Input.hpp"
#include <iostream>
#include <conio.h>

ArrayList<int> arrayList;

void MenuArrayList::printOptions() {
    system("clear");
    std::cout << "-------ARRAY LIST MENU-------\n"
              << "1. isEmpty\n"
              << "2. size\n"
              << "3. clear\n"
              << "4. addFirst\n"
              << "5. addLast\n"
              << "6. add\n"
              << "7. get\n"
              << "8. indexOf\n"
              << "9. lastIndexOf\n"
              << "a. remove\n"
              << "b. removeFirstOcurrence\n"
              << "c. removeLastOcurrence\n"
              << "d. set\n"
              << "e. Imprimir de inicio a fin\n"
              << "f. Imprimir del final al principio\n"
              << "0. Exit\n";
}

void MenuArrayList::start() {
    bool exit{false};
    do {
        printOptions();
        exit = switchOption(getch());
    } while (!exit);
}

bool MenuArrayList::switchOption(char option) {
    switch(option) {
        case '1':
            verifyArrayListEmpty();
            break;

        case '2':
            sizeOfArrayList();
            break;

        case '3':
            deleteElements();
            break;

        case '4':
            insertToBegin();
            break;

        case '5':
            insertToEnd();
            break;

        case '6':
            insertByIndex();
            break;

        case '7':
            printElementByIndex();
            break;

        case '8':
            indexOfFirstOcurrenceOfElement();
            break;

        case '9':
            indexOfLastOcurrenceOfElement();
            break;

        case 'a':
            removeElementByIndex();
            break;

        case 'b':
            removeFirstOcurrenceOfElement();
            break;

        case 'c':
            removeLastOcurrenceOfElement();
            break;

        case 'd':
            modifyElementByIndex();
            break;

        case 'e':
            printOnForwardOrder();
            break;

        case 'f':
            printOnReverseOrder();
            break;

        case '0':
            return true;
            break;
    }
    std::cout << std::endl;
    system("pause");
    return false;
}

void MenuArrayList::verifyArrayListEmpty() {
    std::cout << "\n\n"
              << ((arrayList.isEmpty()) ? "No tiene elementos" : "Tiene elementos");
}

void MenuArrayList::sizeOfArrayList() {
    printf("\n\nTama%co: %d", 164, arrayList.size());
}

void MenuArrayList::deleteElements() {
    std::cout << "\n\n";
    if (arrayList.isEmpty()) {
        std::cout << "No hay elementos para eliminar";
    } else {
        arrayList.clear();
        std::cout << "Elementos eliminados";
    }
}

void MenuArrayList::insertToBegin() {
    std::cout << "\n\nEscriba un numero para ingresar: ";
    arrayList.addFirst(Input::integerNumber(1, 4));
}

void MenuArrayList::insertToEnd() {
    std::cout << "\n\nEscriba un numero para ingresar: ";
    arrayList.addLast(Input::integerNumber(1, 4));
}

void MenuArrayList::insertByIndex() {
    std::cout << "\n\nIngrese la posicion donde desea insertar: ";
    int index{Input::unsignedIntegerNumber(1, 3)};
    std::cout << "Ingrese el elemento a insertar: ";
    int value{Input::integerNumber(1, 4)};

    std::cout << "\n\n"
              << ((arrayList.add(index, value)) ? "Elemento ingresado" : "Elemento no pudo ser ingresado");
}

void MenuArrayList::printElementByIndex() {
    try  {
        std::cout << "\n\nIngrese la posicion que desea imprimir: ";
        int element = arrayList.get(Input::unsignedIntegerNumber(1, 3));
        std::cout << "\nElemento encontrado: " << element;
    } catch (const char *exception) {
        std::cout << exception;
    }
}

void MenuArrayList::indexOfFirstOcurrenceOfElement() {
    std::cout << "\n\nIngrese elemento a buscar: ";
    int index = arrayList.indexOf(Input::integerNumber(1, 4));
    const int ELEMENT_NOT_FOUND{-1};

    std::cout << std::endl;
    if (index != ELEMENT_NOT_FOUND)
        std::cout << "Posicion = " << index;
    else
        std::cout << "Elemento no encontrado.";
}

void MenuArrayList::indexOfLastOcurrenceOfElement() {
    std::cout << "\n\nIngrese elemento a buscar: ";
    int index = arrayList.lastIndexOf(Input::integerNumber(1, 4));
    const int ELEMENT_NOT_FOUND{-1};

    std::cout << std::endl;
    if (index != ELEMENT_NOT_FOUND)
        std::cout << "Posicion = " << index;
    else
        std::cout << "Elemento no encontrado.";
}

void MenuArrayList::removeElementByIndex() {
    try {
        std::cout << "Ingrese posicion de la lista a eliminar: ";
        int elementErased = arrayList.remove(Input::unsignedIntegerNumber(1, 3));
        std::cout << "\nElemento eliminado = " << elementErased;
    } catch (const char *exception) {
        std::cout << exception;
    }
}

void MenuArrayList::removeFirstOcurrenceOfElement() {
    std::cout << "Ingrese elemento a eliminar (se elimina primera ocurrencia): ";
    std::cout << (arrayList.removeFirstOcurrence(Input::integerNumber(1, 4)) ? "\n\nElemento eliminado" : "\n\nNo se encontro el elemento");
}

void MenuArrayList::removeLastOcurrenceOfElement() {
    std::cout << "Ingrese elemento a eliminar (se elimina la ultima ocurrencia): ";
    std::cout << (arrayList.removeLastOcurrence(Input::integerNumber(1, 4)) ? "\n\nElemento eliminado" : "\n\nNo se encontro el elemento");
}

void MenuArrayList::modifyElementByIndex() {
    try {
        std::cout << "\n\nIngrese posicion del elemento a eliminar: ";
        int index = Input::unsignedIntegerNumber(1, 3);
        std::cout << "Ingrese nuevo valor: ";
        int newElement = Input::integerNumber(1, 4);
        std::cout << "\nElemento modificado = " << arrayList.set(index, newElement);
    } catch (const char *exception) {
        std::cout << exception;
    }
}

void MenuArrayList::printOnForwardOrder() {
    std::cout << "\n\n";
    for (int i{}; i < arrayList.size(); i++) {
        std::cout << '[' << arrayList[i] << "] ";
    }
}

void MenuArrayList::printOnReverseOrder() {
    std::cout << "\n\n";
    for (int i{arrayList.size() - 1}; i >= 0 ; i--) {
        std::cout << '[' << arrayList[i] << "] ";
    }
}