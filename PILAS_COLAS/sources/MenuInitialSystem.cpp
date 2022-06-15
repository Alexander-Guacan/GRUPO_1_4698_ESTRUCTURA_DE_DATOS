#include "MenuInitialSystem.hpp"

void MenuInitialSystem::start() {
    typedef int T;
    Stack<DATA_TYPE> *stack = new Stack<DATA_TYPE>();
    Queue<DATA_TYPE> *queue = new Queue<DATA_TYPE>();

    MenuInitialGUI menu;
    bool exit{false};

    while (!exit) {
        switch (menu.printScreen()) {
            case static_cast<int>(MenuInitialGUI::Options::STACK):
                exit = operationsWithStack(stack);
                break;

            case static_cast<int>(MenuInitialGUI::Options::QUEUE):
                exit = operationsWithQueue(queue);
                break;

            case static_cast<int>(MenuInitialGUI::Options::EXIT):
                exit = true;
                break;
        }
    }
}

bool MenuInitialSystem::operationsWithStack(Stack<DATA_TYPE> *&stack) {
    return OperatorWithStack::start(stack);
}

bool MenuInitialSystem::operationsWithQueue(Queue<DATA_TYPE> *&queue) {
    return OperatorWithQueue::start(queue);
}