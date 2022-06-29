#include "MenuStack.hpp"
#include "..\Collection\Stack.hpp"
#include "..\Tools\Input.hpp"
#include <iostream>
#include <conio.h>

Stack<int> numeros;
Iterator<int> iteratorStack;

void MenuStack::printStackTitles() {
    system("cls");
    std::cout << "-----MENU STACK-----\n"
              << "1 isEmpty\n"
              << "2. size\n"
              << "3. clear\n"
              << "4. push\n"
              << "5. pop\n"
              << "6. top\n"
              << "7. modificar top\n"
              << "8. iterator\n"
              << "9. reverse iterator\n"
              << "0. salir\n";
}

void MenuStack::start() {
    bool exit{false};

    do {
        printStackTitles();

        switch (getch()) {
            case '1':
                verifyStackEmpty();

                break;

            case '2':
                sizeOfStack();

                break;
                
            case '3':
                cleanStack();

                break;

            case '4':
                insertElementOnStack();

                break;

            case '5':
                deleteLastElementInsertedOnStack();

                break;

            case '6':
                printLastElementInsertedOnStack();

                break;

            case '7':
                modifyLastElementInsertedOnStack();

                break;

            case '8':
                printStackOnNaturalOrder();

                break;

            case '9':
                printStackOnReverseOrder();

                break;

            case '0':
                exit = true;
                break;

        }

        system("pause");
    } while (!exit);
}

void MenuStack::verifyStackEmpty() {
    std::cout << ((numeros.isEmpty()) ? "\n\nEsta vacio\n" : "\n\nTiene elementos\n");
}

void MenuStack::sizeOfStack() {
    std::cout << "\n\nCantidad: " << numeros.size() << '\n';
}

void MenuStack::cleanStack() {
    if (!numeros.isEmpty()) {
        numeros.clear();
        std::cout << "\n\nDatos eliminados\n";
    } else {
        std::cout << "\n\nNo hay datos por limpiar\n";
    }
}

void MenuStack::insertElementOnStack() {
    std::cout << "\n\nIngrese un numero: ";
    numeros.push(Input::integerNumber(1, 4));
}

void MenuStack::deleteLastElementInsertedOnStack() {
    try {
        std::cout << "\n\nDato eliminado: " << numeros.pop() << '\n';
    } catch (const char* exception) {
        std::cout << exception << '\n';
    }
}

void MenuStack::printLastElementInsertedOnStack() {
    try {
        std::cout << "\n\nDato en la cima: " << numeros.top() << '\n';
    } catch (const char *exception) {
        std::cout << exception;
    }
}

void MenuStack::modifyLastElementInsertedOnStack() {
    try {
        std::cout << "\n\nIngrese un numero para modificar la cima: ";
        numeros.top() = Input::integerNumber(1, 4);
    } catch (const char *exception) {
        std::cout << exception;
    }
}

void MenuStack::printStackOnNaturalOrder() {
    iteratorStack = numeros.iterator();

    std::cout << "\n\n";
    while (iteratorStack.hasNext()) {
        std::cout << '[' << iteratorStack.next() << "] ";
    }
    std::cout << std::endl;
}

void MenuStack::printStackOnReverseOrder() {
    iteratorStack = numeros.descendingIterator();

    std::cout << "\n\n";
    while (iteratorStack.hasNext()) {
        std::cout << '[' << iteratorStack.next() << "] ";
    }
    std::cout << std::endl;
}