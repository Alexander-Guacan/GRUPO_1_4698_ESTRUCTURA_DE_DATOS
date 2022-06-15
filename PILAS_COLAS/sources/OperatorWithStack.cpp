#include "OperatorWithStack.hpp"
#include "MenuOperationsGUI.hpp"
#include "HandleConsole.hpp"
#include "StackVarianceCalculator.hpp"
#include "Input.hpp"
#include <iostream>
#include <conio.h>

COORD OperatorWithStack::subtitlePosition{40, 18};
COORD OperatorWithStack::textPosition{40, 20};

bool OperatorWithStack::start(Stack<DATA_TYPE> *&stack) {
    MenuOperationsGUI menu;

    bool exit{false};

    while (!exit) {
        switch (menu.printScreen()) {

            case static_cast<int>(MenuOperationsGUI::Options::ADD):
                add(stack);
                break;

            case static_cast<int>(MenuOperationsGUI::Options::DELETE_ELEMENT):
                deleteElement(stack);
                break;

            case static_cast<int>(MenuOperationsGUI::Options::SHOW_WITHOUT_DELETE):
                showWithoutDelete(stack);
                break;

            case static_cast<int>(MenuOperationsGUI::Options::SHOW_WITH_DELETE):
                showWithDelete(stack);
                break;

            case static_cast<int>(MenuOperationsGUI::Options::CALCULATE_VARIANCE):
                calculateVariance(stack);
                break;

            case static_cast<int>(MenuOperationsGUI::Options::RETURN):
                return false;
                break;

            case static_cast<int>(MenuOperationsGUI::Options::EXIT):
                exit = true;
                break;
        }
    }

    return true;
}


void OperatorWithStack::add(Stack<DATA_TYPE> *&stack) {
    HandleConsole console;
    
    console.setCursorPosition(subtitlePosition);
    int value = Input::integerNumber("Ingrese un valor: ", 1, 4);

    stack->push(new int{value});
}


void OperatorWithStack::deleteElement(Stack<DATA_TYPE> *&stack) {
    HandleConsole console;
    
    console.setCursorPosition(subtitlePosition);

    DATA_TYPE *value = stack->pop();

    if (value != nullptr) {
        std::cout << "Elemento eliminado [" << *(value) << "]";
    } else {
        std::cout << "No quedan elementos por eliminar";
    }

    getch();
}


void OperatorWithStack::showWithoutDelete(Stack<DATA_TYPE> *&stack) {
    HandleConsole console;
    
    console.setCursorPosition(subtitlePosition);
    std::cout << "Listado completo de stack:";

    console.setCursorPosition(textPosition);

    Iterator<DATA_TYPE> *iterator = stack->getIterator();

    while (iterator->hasNext()) {
        std::cout << "[" << *(iterator->next()) << "] ";
    }

    getch();
}


void OperatorWithStack::showWithDelete(Stack<DATA_TYPE> *&stack) {
    HandleConsole console;
    
    console.setCursorPosition(subtitlePosition);
    std::cout << "Pila:";

    console.setCursorPosition(textPosition);

    while (!stack->isEmpty()) {
        std::cout << "[" << *(stack->pop()) << "] ";
    }

    getch();
}

void OperatorWithStack::calculateVariance(Stack<int> *&stack) {
    HandleConsole console;
    
    console.setCursorPosition(subtitlePosition);
    std::cout << "Calculo de varianza:";

    console.setCursorPosition(textPosition);

    std::cout << "Varianza = " << StackVarianceCalculator::calculate(stack);

    getch();
}