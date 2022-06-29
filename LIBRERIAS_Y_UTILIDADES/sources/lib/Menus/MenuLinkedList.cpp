#include "MenuLinkedList.hpp"
#include "..\Collection\LinkedList.hpp"
#include "..\Tools\Input.hpp"
#include <iostream>
#include <conio.h>

LinkedList<int> linkedList;
Iterator<int> iteratorLinkedList;

void MenuLinkedList::printOptions() {
    system("clear");
    std::cout << "-------LINKED LIST MENU-------\n"
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
              << "e. Iterator\n"
              << "f. Descending iterator\n"
              << "0. Exit\n";
}

void MenuLinkedList::start() {
    bool exit{false};
    do {
        printOptions();
        exit = switchOption(getch());
    } while (!exit);
}

bool MenuLinkedList::switchOption(char option) {
    switch(option) {
        case '1':
            verifyLinkedListEmpty();
            break;

        case '2':
            sizeOfLinkedList();
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

void MenuLinkedList::verifyLinkedListEmpty() {
    std::cout << "\n\n"
              << ((linkedList.isEmpty()) ? "No tiene elementos" : "Tiene elementos");
}

void MenuLinkedList::sizeOfLinkedList() {
    printf("\n\nTama%co: %d", 164, linkedList.size());
}

void MenuLinkedList::deleteElements() {
    std::cout << "\n\n";
    if (linkedList.isEmpty()) {
        std::cout << "No hay elementos para eliminar";
    } else {
        linkedList.clear();
        std::cout << "Elementos eliminados";
    }
}

void MenuLinkedList::insertToBegin() {
    std::cout << "\n\nEscriba un numero para ingresar: ";
    linkedList.addFirst(Input::integerNumber(1, 4));
}

void MenuLinkedList::insertToEnd() {
    std::cout << "\n\nEscriba un numero para ingresar: ";
    linkedList.addLast(Input::integerNumber(1, 4));
}

void MenuLinkedList::insertByIndex() {
    std::cout << "\n\nIngrese la posicion donde desea insertar: ";
    int index{Input::unsignedIntegerNumber(1, 3)};
    std::cout << "Ingrese el elemento a insertar: ";
    int value{Input::integerNumber(1, 4)};

    std::cout << "\n\n"
              << ((linkedList.add(index, value)) ? "Elemento ingresado" : "Elemento no pudo ser ingresado");
}

void MenuLinkedList::printElementByIndex() {
    try  {
        std::cout << "\n\nIngrese la posicion que desea imprimir: ";
        int element = linkedList.get(Input::unsignedIntegerNumber(1, 3));
        std::cout << "\nElemento encontrado: " << element;
    } catch (const char *exception) {
        std::cout << exception;
    }
}

void MenuLinkedList::indexOfFirstOcurrenceOfElement() {
    std::cout << "\n\nIngrese elemento a buscar: ";
    int index = linkedList.indexOf(Input::integerNumber(1, 4));
    const int ELEMENT_NOT_FOUND{-1};

    std::cout << std::endl;
    if (index != ELEMENT_NOT_FOUND)
        std::cout << "Posicion = " << index;
    else
        std::cout << "Elemento no encontrado.";
}

void MenuLinkedList::indexOfLastOcurrenceOfElement() {
    std::cout << "\n\nIngrese elemento a buscar: ";
    int index = linkedList.lastIndexOf(Input::integerNumber(1, 4));
    const int ELEMENT_NOT_FOUND{-1};

    std::cout << std::endl;
    if (index != ELEMENT_NOT_FOUND)
        std::cout << "Posicion = " << index;
    else
        std::cout << "Elemento no encontrado.";
}

void MenuLinkedList::removeElementByIndex() {
    try {
        std::cout << "Ingrese posicion de la lista a eliminar: ";
        int elementErased = linkedList.remove(Input::unsignedIntegerNumber(1, 3));
        std::cout << "\nElemento eliminado = " << elementErased;
    } catch (const char *exception) {
        std::cout << exception;
    }
}

void MenuLinkedList::removeFirstOcurrenceOfElement() {
    std::cout << "Ingrese elemento a eliminar (se elimina primera ocurrencia): ";
    std::cout << (linkedList.removeFirstOcurrence(Input::integerNumber(1, 4)) ? "\n\nElemento eliminado" : "\n\nNo se encontro el elemento");
}

void MenuLinkedList::removeLastOcurrenceOfElement() {
    std::cout << "Ingrese elemento a eliminar (se elimina la ultima ocurrencia): ";
    std::cout << (linkedList.removeLastOcurrence(Input::integerNumber(1, 4)) ? "\n\nElemento eliminado" : "\n\nNo se encontro el elemento");
}

void MenuLinkedList::modifyElementByIndex() {
    try {
        std::cout << "\n\nIngrese posicion del elemento a eliminar: ";
        int index = Input::unsignedIntegerNumber(1, 3);
        std::cout << "Ingrese nuevo valor: ";
        int newElement = Input::integerNumber(1, 4);
        std::cout << "\nElemento modificado = " << linkedList.set(index, newElement);
    } catch (const char *exception) {
        std::cout << exception;
    }
}

void MenuLinkedList::printOnForwardOrder() {
    iteratorLinkedList = linkedList.iterator();
 
    std::cout << "\n\n";
    while (iteratorLinkedList.hasNext()) {
        std::cout << '[' << iteratorLinkedList.next() << "] ";
    }
}

void MenuLinkedList::printOnReverseOrder() {
    iteratorLinkedList = linkedList.descendingIterator();

    std::cout << "\n\n";
    while (iteratorLinkedList.hasNext()) {
        std::cout << '[' << iteratorLinkedList.next() << "] ";
    }
}