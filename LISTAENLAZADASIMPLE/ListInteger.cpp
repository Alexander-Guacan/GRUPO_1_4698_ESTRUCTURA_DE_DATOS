#include "ListInteger.h"
#include <iostream>

int ListInteger::size() { //funcion retorna el tamaño de la lista
    int size{};
    Node *iterator{firstNode}; 
    while (iterator != nullptr) {
        size++;
        iterator = iterator->getNextNode();
    }

    return size;
}

bool ListInteger::isEmpty() { //funcion verifica si la lista esta vacia
    return firstNode == nullptr;
}

void ListInteger::insertBack(int value) {
    Node *newNode = new Node();
    newNode->setValue(value);
    
    if (isEmpty()) {

        firstNode = newNode;

    } else {
        Node *iterator{firstNode};
        Node *auxiliar{nullptr};

        while (iterator != nullptr) {
            auxiliar = iterator;
            iterator = iterator->getNextNode();
        }

        auxiliar->setNextNode(newNode);
    }
}

void ListInteger::insertTop(int value) {
    Node *newNode = new Node();
    newNode->setValue(value);

    if (isEmpty()) {
        firstNode = newNode;
    } else {
        newNode->setNextNode(firstNode);
        firstNode = newNode;
    }
}

void ListInteger::printFromStart() {
    Node *iterator = firstNode;
    
    if (!isEmpty()) {

        printf("\n");

        while (iterator != nullptr) {
            printf("[%d] ", iterator->getValue());
            iterator = iterator->getNextNode();
        }

        printf("\n");

    } else {

        printf("\nLista vacia\n");
    }
}

void ListInteger::printFromEnd() {
    Node *iterator = firstNode;

    if (!isEmpty()) {

        int *inverseList = new int[size()];

        for (int i{size() - 1}; i >= 0; i--) {
            *(inverseList + i) = iterator->getValue();
            iterator = iterator->getNextNode();
        }

        printf("\n");

        for (int i{}; i < size(); i++) {
            printf("[%d] ", *(inverseList + i));
        }

        printf("\n");

        delete[] inverseList;
    } else {

        printf("\nLista vacia\n");
    }
}

void ListInteger::search(int value) {
    int position{};
    bool hasFoundValue{false};
    Node *iterator{firstNode};
    
    while (iterator != nullptr && !hasFoundValue) {
        position++;
        hasFoundValue = iterator->getValue() == value;
        iterator = iterator->getNextNode();
    }

    if (!hasFoundValue){

        printf("\nNo se encontro el valor \n");

    } else {

        printf("\nEl valor se encuentra en la posicion: %d \n" , position);
    }
}

bool ListInteger::deleteFromHead(int value) {
    Node *iterator{firstNode};
    Node *auxiliar{nullptr};
    bool hasFoundValue{false};
    
    while (iterator != nullptr && !hasFoundValue) {
        hasFoundValue = iterator->getValue() == value;

        if (!hasFoundValue) {
            auxiliar = iterator;
            iterator = iterator->getNextNode();
        }
    }
    
    if (isEmpty() || !hasFoundValue) {
        printf("\nEl valor [%d] no se encuentra en la lista \n", value);

    } else if (iterator == firstNode && hasFoundValue) {

        auxiliar = iterator;
        iterator = iterator->getNextNode();
        firstNode = iterator;

        if (auxiliar != nullptr) {
            delete auxiliar;
        }
                        
    } else if (hasFoundValue && firstNode != iterator) {
        auxiliar->setNextNode(iterator->getNextNode());

        if (iterator != nullptr) {
            delete iterator;
        }
    }

    return hasFoundValue;
}

bool ListInteger::deleteFromTail(int value) {
    Node **iterator = new Node *[size()];
    Node *auxiliar{firstNode};

    for (int i{size() - 1}; i >= 0; i--) {
        *(iterator + i) = auxiliar;
        auxiliar = auxiliar->getNextNode();
    }

    bool hasFoundValue{false};
    int i{};

    while (i < size() && !hasFoundValue) {
        hasFoundValue = (*(*(iterator + i))).getValue() == value;

        if (*(iterator + i) != firstNode && hasFoundValue) {

            (*(*(iterator + i + 1))).setNextNode((*(*(iterator + i))).getNextNode());

            delete *(iterator + i);

        } else if (*(iterator + i) == firstNode && hasFoundValue) {
            firstNode = *(iterator + i - 1);

            delete *(iterator + i);
        }

        i++;
    }

    if (!hasFoundValue) {
        printf("\nEl valor [%d] no se encuentra en la lista \n", value);
    }

    return hasFoundValue;
}