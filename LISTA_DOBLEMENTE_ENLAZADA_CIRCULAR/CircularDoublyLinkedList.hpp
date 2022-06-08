#ifndef CIRCULAR_DOUBLY_LINKED_LIST_HPP
#define CIRCULAR_DOUBLY_LINKED_LIST_HPP

#include "List.hpp"
#include "NodeDouble.hpp"
#include <iostream>

template <typename T>
class CircularDoublyLinkedList : public List<T> {
    NodeDouble<T> *firstNode{nullptr};
    NodeDouble<T> *lastNode{nullptr};

    public:
        // Retorna verdadero si la lista esta vacia, caso contrario retorna falso
        bool isEmpty();
        // Retorna el numero de elementos guardados en la lista
        short size();
        // Retorna un puntero que apunta al primer elemento de la lista, si la lista esta vacia retornara nullptr
        NodeDouble<T> *begin();
        // Retorna un puntero que apunta al ultimo elemento de la lista, si la lista esta vacia retornara nullptr
        NodeDouble<T> *end();
        // Inserta un dato al inicio de la lista
        void insertAtBegin(T data);
        // Inserta un dato al final de la lista
        void insertAtEnd(T data);
        // Inserta un dato en una posicion determinada de la lista, si se ha ingresado correctamente en la lista retornara true, si la lista esta vacia o la posicion indicada no existe retornara false
        bool insertAt(T data, short positionToInsert);
        // Elimina el primer elemento de la lista, si la lista esta vacia retorna nullptr
        const T* deleteAtBegin();
        // Elimina el ultimo elemento de la lista, si la lista esta vacia retorna nullptr
        const T* deleteAtEnd();
        // Elimina el elemento en la posicion especificada la lista, si la lista esta vacia o no existe la posicion indicada retorna nullptr
        const T* deleteAt(short positionToDelete);
        // Busca la primera coincidencia desde inicio a fin de la lista
        void search(short positionToSearch);
        // Imprime la lista completa
        void printAll();
        // Imprime un unico elemento en la posicion indicada
        void printOf(short positionToPrint);
};

template <typename T>
bool CircularDoublyLinkedList<T>::isEmpty() {
    return firstNode == nullptr;
}

template <typename T>
short CircularDoublyLinkedList<T>::size() {
    short sizeOfList{};
    NodeDouble<T> *iterator{firstNode};

    if (!isEmpty()) {
        sizeOfList++;
        iterator = iterator->getNextNode();
        
        while (iterator != firstNode && iterator != nullptr) {
            sizeOfList++;
            iterator = iterator->getNextNode();
        }
    }

    return sizeOfList;
}

template <typename T>
NodeDouble<T> *CircularDoublyLinkedList<T>::begin() {
    return firstNode;
}

template <typename T>
NodeDouble<T> *CircularDoublyLinkedList<T>::end() {
    return lastNode;
}

template <typename T>
void CircularDoublyLinkedList<T>::insertAtBegin(T data) {
    NodeDouble<T> *newNode = new NodeDouble<T>(data);

    if (!isEmpty()) {
        newNode->setPreviousNode(lastNode);
        newNode->setNextNode(firstNode);
        firstNode->setPreviousNode(newNode);
        lastNode->setNextNode(newNode);
        firstNode = newNode;

    } else {
        firstNode = newNode;
        lastNode = newNode;
        newNode->setNextNode(firstNode);
        newNode->setPreviousNode(lastNode);
    }

}

template <typename T>
void CircularDoublyLinkedList<T>::insertAtEnd(T data) {
    NodeDouble<T> *newNode = new NodeDouble<T>(data);

    if (!isEmpty()) {
        newNode->setPreviousNode(lastNode);
        newNode->setNextNode(firstNode);
        firstNode->setPreviousNode(newNode);
        lastNode->setNextNode(newNode);
        lastNode = newNode;
    } else {
        firstNode = newNode;
        lastNode = newNode;
        newNode->setPreviousNode(lastNode);
        newNode->setNextNode(firstNode);
    }

}

template <typename T>
bool CircularDoublyLinkedList<T>::insertAt(T data, short positionToInsert) {
    bool hasSavedData{false};
    short sizeOfList{size()};

    if (!isEmpty() && (positionToInsert > 0 && positionToInsert <= sizeOfList)) {
        if (positionToInsert == 1)
            insertAtBegin(data);

        else if (positionToInsert == sizeOfList)
            insertAtEnd(data);

        else {
            NodeDouble<T> *iterator{firstNode->getNextNode()};
            short positionOfList{2};

            while (positionOfList++ < positionToInsert)
                iterator = iterator->getNextNode();

            NodeDouble<T> *newNode = new NodeDouble<T>(data);
            newNode->setPreviousNode(iterator->getPreviousNode());
            newNode->setNextNode(iterator);
            iterator->getPreviousNode()->setNextNode(newNode);
            iterator->setPreviousNode(newNode);
        }

        hasSavedData = true;
    }

    return hasSavedData;
}

template <typename T>
const T* CircularDoublyLinkedList<T>::deleteAtBegin() {

    if (!isEmpty()) {
        const T *dataErased = new T{firstNode->getData()};

        NodeDouble<T> *nodeToDelete{firstNode};

        if (size() == 1) {
            firstNode = nullptr;
            lastNode = nullptr;
        } else {
            firstNode->getNextNode()->setPreviousNode(lastNode);
            lastNode->setNextNode(firstNode->getNextNode());
            firstNode = firstNode->getNextNode();
        }

        delete nodeToDelete;
        return dataErased;

    } else {
        return nullptr;
    }
}

template <typename T>
const T* CircularDoublyLinkedList<T>::deleteAtEnd() {

    if (!isEmpty()) {
        const T *dataErased = new T{lastNode->getData()};

        NodeDouble<T> *nodeToDelete{lastNode};

        if (size() == 1) {
            firstNode = nullptr;
            lastNode = nullptr;
        } else {
            lastNode->getPreviousNode()->setNextNode(firstNode);
            firstNode->setPreviousNode(lastNode->getPreviousNode());
            lastNode = lastNode->getPreviousNode();
        }


        delete nodeToDelete;
        return dataErased;

    } else {
        return nullptr;
    }

}

template <typename T>
const T* CircularDoublyLinkedList<T>::deleteAt(short positionToDelete) {
    short sizeOfList{size()};

    if (!isEmpty() && (positionToDelete > 0 && positionToDelete <= sizeOfList)) {

        if (positionToDelete == 1)
            return deleteAtBegin();

        else if (positionToDelete == sizeOfList)
            return deleteAtEnd();

        else {
            NodeDouble<T> *iterator{firstNode->getNextNode()};
            int positionOfList{2};

            while (positionOfList++ < positionToDelete)
                iterator = iterator->getNextNode();

            NodeDouble<T> *nodeToDelete{iterator};
            const T *dataErased = new T{iterator->getData()};

            iterator->getPreviousNode()->setNextNode(iterator->getNextNode());
            iterator->getNextNode()->setPreviousNode(iterator->getPreviousNode());

            delete nodeToDelete;
            return dataErased;
        }

    } else {
        return nullptr;
    }

}

template <typename T>
void CircularDoublyLinkedList<T>::search(short positionToSearch) {
    short sizeOfList{size()};

    if (!isEmpty() && (positionToSearch > 0 && positionToSearch <= sizeOfList)) {

        if (positionToSearch == 1)
            std::cout << "\nValor encontrado es: " << firstNode->getData() << '\n';

        else if (positionToSearch == sizeOfList)
            std::cout << "\nValor encontrado es: " << lastNode->getData() << '\n';

        else {
            NodeDouble<T> *iterator{firstNode->getNextNode()};
            short positionOfList{2};

            while (positionOfList++ < positionToSearch)
                iterator = iterator->getNextNode();

            std::cout << "\nValor encontrado es: " << iterator->getData() << '\n';
        }
    } else {
        std::cout << "\nERROR: lista vacia o no se puede buscar en la posicion indicada\n";
    }
}

template <typename T>
void CircularDoublyLinkedList<T>::printAll() {

    std::cout << '\n';

    if (!isEmpty()) {
        NodeDouble<T> *iterator{firstNode};

        std::cout << iterator->getData() << ' ';
        iterator = iterator->getNextNode();

        while (iterator != firstNode && iterator != nullptr) {
            std::cout << iterator->getData() << ' ';
            iterator = iterator->getNextNode();
        }
    } else {
        std::cout << "Lista vacia";
    }

    std::cout << '\n';
}

template <typename T>
void CircularDoublyLinkedList<T>::printOf(short positionToPrint) {
    std::cout << '\n';
    
    short sizeOfList{size()};
    if (!isEmpty() && (positionToPrint > 0 && positionToPrint <= sizeOfList)) {
        NodeDouble<T> *iterator{firstNode};
        short positionOfList{1};

        while (positionOfList++ < positionToPrint)
            iterator = iterator->getNextNode();

        std::cout << iterator->getData();
    } else {
        std::cout << "ERROR: lista vacia o no se puede imprimir en la posicion indicada";
    }

    std::cout << '\n';
}

#endif