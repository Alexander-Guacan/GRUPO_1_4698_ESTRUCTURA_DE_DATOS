#include "OperatorWithQueue.hpp"
#include "MenuOperationsGUI.hpp"
#include "HandleConsole.hpp"
#include "QueueVarianceCalculator.hpp"
#include "Input.hpp"
#include <iostream>
#include <conio.h>

COORD OperatorWithQueue::subtitlePosition{40, 18};
COORD OperatorWithQueue::textPosition{40, 20};

bool OperatorWithQueue::start(Queue<DATA_TYPE> *&queue) {
    MenuOperationsGUI menu;

    bool exit{false};

    while (!exit) {
        switch (menu.printScreen()) {

            case static_cast<int>(MenuOperationsGUI::Options::ADD):
                add(queue);
                break;

            case static_cast<int>(MenuOperationsGUI::Options::DELETE_ELEMENT):
                deleteElement(queue);
                break;

            case static_cast<int>(MenuOperationsGUI::Options::SHOW_WITHOUT_DELETE):
                showWithoutDelete(queue);
                break;

            case static_cast<int>(MenuOperationsGUI::Options::SHOW_WITH_DELETE):
                showWithDelete(queue);
                break;

            case static_cast<int>(MenuOperationsGUI::Options::CALCULATE_VARIANCE):
                calculateVariance(queue);
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


void OperatorWithQueue::add(Queue<DATA_TYPE> *&queue) {
    HandleConsole console;
    
    console.setCursorPosition(subtitlePosition);
    int value = Input::integerNumber("Ingrese un valor: ", 1, 4);

    queue->add(new int{value});
}


void OperatorWithQueue::deleteElement(Queue<DATA_TYPE> *&queue) {
    HandleConsole console;
    console.setCursorPosition(subtitlePosition);

    DATA_TYPE *value = queue->poll();

    if (value != nullptr) {
        std::cout << "Elemento eliminado [" << *(value) << "]";
    } else {
        std::cout << "No quedan elementos por eliminar en la cola";
    }

    getch();
}


void OperatorWithQueue::showWithoutDelete(Queue<DATA_TYPE> *&queue) {
    HandleConsole console;
    
    console.setCursorPosition(subtitlePosition);
    std::cout << "Listado completo de queue:";

    console.setCursorPosition(textPosition);

    Iterator<DATA_TYPE> *iterator = queue->getIterator();

    while (iterator->hasNext()) {
        std::cout << "[" << *(iterator->next()) << "] ";
    }

    getch();
}


void OperatorWithQueue::showWithDelete(Queue<DATA_TYPE> *&queue) {
    HandleConsole console;
    
    console.setCursorPosition(subtitlePosition);
    std::cout << "Cola:";

    console.setCursorPosition(textPosition);

    while (!queue->isEmpty()) {
        std::cout << "[" << *(queue->poll()) << "] ";
    }

    getch();
}

void OperatorWithQueue::calculateVariance(Queue<int> *&queue) {
    HandleConsole console;
    
    console.setCursorPosition(subtitlePosition);
    std::cout << "Calculo de varianza:";

    console.setCursorPosition(textPosition);

    std::cout << "Varianza = " << QueueVarianceCalculator::calculate(queue);

    getch();
}