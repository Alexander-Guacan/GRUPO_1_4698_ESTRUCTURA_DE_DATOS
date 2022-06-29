#include "MenuQueue.hpp"
#include "..\Collection\Queue.hpp"
#include "..\Tools\Input.hpp"
#include <iostream>
#include <conio.h>

Queue<int> queue;
Iterator<int> iteratorQueue;

void MenuQueue::printQueueTitles() {
    system("clear");
    std::cout << "-----QUEUE MENU-----\n"
              << "1. isEmpty\n"
              << "2. size\n"
              << "3. clean\n"
              << "4. add\n"
              << "5. poll\n"
              << "6. peek\n"
              << "7. modify\n"
              << "8. iterator\n"
              << "9. reverse iterator\n"
              << "0. exit\n";
}

void MenuQueue::start() {
    bool exit{false};

    do {
        printQueueTitles();

        switch (getch()) {
            case '1':
                verifyQueueEmpty();
                break;

            case '2':
                sizeOfQueue();
                break;

            case '3':
                cleanQueue();
                break;

            case '4':
                insertElementOnQueue();
                break;

            case '5':
                deleteLastElementInsertedOnQueue();
                break;

            case '6':
                printLastElementInsertedOnQueue();
                break;

            case '7':
                modifyLastElementInsertedOnQueue();
                break;

            case '8':
                printQueueOnNaturalOrder();
                break;

            case '9':
                printQueueOnReverseOrder();
                break;

            case '0':
                exit = true;
                break;

        }

        system("pause");
    } while (!exit);
}

void MenuQueue::verifyQueueEmpty() {
    std::cout << "\n\n";
    std::cout << ((queue.isEmpty() ? "Esta vacia" : "Tiene elementos"));
    std::cout << '\n';
}

void MenuQueue::sizeOfQueue() {
    printf("\n\nTama%co = %d\n", 164, queue.size());
}

void MenuQueue::cleanQueue() {
    std::cout << "\n\n";
    if (queue.isEmpty()) {
        std::cout << "Empty Queue";
    } else {
        queue.clear();
        std::cout << "Clear elements";
    }
    std::cout << '\n';
}

void MenuQueue::insertElementOnQueue() {
    std::cout << "\n\nIngrese valor a insertar en la queue: ";
    queue.add(Input::integerNumber(1, 4));
}

void MenuQueue::deleteLastElementInsertedOnQueue() {
    std::cout << "\n\n";
    try {
        std::cout << "Elemento eliminado: " << queue.poll();
    } catch (const char *exception) {
        std::cout << exception;
    }
    std::cout << '\n';
}

void MenuQueue::printLastElementInsertedOnQueue() {
    std::cout << "\n\n";
    if (queue.isEmpty()) {
        std::cout << "Empty queue";
    } else {
        std::cout << "Elemento en el top de la pila: " << queue.peek();
    }
    std::cout << '\n';
}

void MenuQueue::modifyLastElementInsertedOnQueue() {
    std::cout << "\n\n";
    if (queue.isEmpty()) {
        std::cout << "No hay datos para modificar: ";
    } else {
        std::cout << "Ingrese valor a insertar en la queue: ";
        queue.peek() = Input::integerNumber(1, 4);
    }
    std::cout << '\n';
}

void MenuQueue::printQueueOnNaturalOrder() {
    std::cout << "\n\n";
    
    iteratorQueue = queue.iterator();
    while (iteratorQueue.hasNext()) {
        std::cout << '[' << iteratorQueue.next() << "] ";
    }

    std::cout << '\n';
}

void MenuQueue::printQueueOnReverseOrder() {
    std::cout << "\n\n";
    
    iteratorQueue = queue.descendingIterator();
    while (iteratorQueue.hasNext()) {
        std::cout << '[' << iteratorQueue.next() << "] ";
    }

    std::cout << '\n';
}
