#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "List.h"
#include "Node.h"
#include <iostream>

template <typename T>
class DoublyLinkedList : public List<T> {
    Node<T> *firstNode{nullptr};
    Node<T> *lastNode{nullptr};

    public:
        Node<T> *getFirstNode();
        void setFirstNode(Node<T> *newFirstNode);
        Node<T> *getLastNode();
        void setLastNode(Node<T> *newLastNode);
        bool isEmpty();
        int size();
        void insertAtBegin(T data);
        void insertAtEnd(T data);
        void insertAt(T data, int positionToInsert);
        bool searchFromBegin(T data);
        bool searchFromEnd(T data);
        bool deleteAtBegin();
        bool deleteAtEnd();
        bool deleteAt(int positionToDelete);
        void print();
        Node<T> *first();
        Node<T> *last();
};

template <typename T>
Node<T> *DoublyLinkedList<T>::getFirstNode() {
    return firstNode;
}

template <typename T>
void DoublyLinkedList<T>::setFirstNode(Node<T> *newFirstNode) {
    firstNode = newFirstNode;
}

template <typename T>
Node<T> *DoublyLinkedList<T>::getLastNode() {
    return lastNode;
}

template <typename T>
void DoublyLinkedList<T>::setLastNode(Node<T> *newLastNode) {
    lastNode = newLastNode;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() {
    return this->firstNode == nullptr;
}

template <typename T>
int DoublyLinkedList<T>::size() {
    int size{};
    Node<T> *iterator{firstNode};

    while (iterator != nullptr) {
        size++;
        iterator = iterator->getNextNode();
    }

    return size;
}

template <typename T>
void DoublyLinkedList<T>::insertAtBegin(T data) {
    Node<T> *newNode = new Node<T>(data);

    if (!isEmpty()) {
        newNode->setNextNode(firstNode);
        firstNode->setPreviousNode(newNode);
    } else {
        lastNode = newNode;
    }

    firstNode = newNode;
}

template <typename T>
void DoublyLinkedList<T>::insertAtEnd(T data) {
    Node<T> *newNode = new Node<T>(data);

    if (!isEmpty()) {
        lastNode->setNextNode(newNode);
        newNode->setPreviousNode(lastNode);
    } else {
        firstNode = newNode;
    }

    lastNode = newNode;
}

template <typename T>
void DoublyLinkedList<T>::insertAt(T data, int positionToInsert) {
    int sizeOfList = size();

    if (!isEmpty()) {

        if (positionToInsert == 1) {
            insertAtBegin(data);
            
        } else if (positionToInsert > 0 && positionToInsert <= sizeOfList) {
            Node<T> *newNode = new Node<T>(data);
            Node<T> *iterator{firstNode};
            int listPosition{};

            while (++listPosition < positionToInsert) {
                iterator = iterator->getNextNode();
            }

            newNode->setPreviousNode(iterator->getPreviousNode());
            iterator->getPreviousNode()->setNextNode(newNode);
            iterator->setPreviousNode(newNode);
            newNode->setNextNode(iterator);
        } else {
            printf("\nERROR: No se puede insertar en la posicion indicada\n");
        }

    } else {
        printf("\nERROR: No se puede insertar porque la lista esta vacia\n");
    }
}

template <typename T>
bool DoublyLinkedList<T>::searchFromBegin(T data) {
    bool hasFoundData{false};

    if (!isEmpty()) {
        Node<T> *iterator{firstNode};
        int positionInList{1};

        while (iterator != nullptr && !(hasFoundData = iterator->getData() == data)) {
            positionInList++;
            iterator = iterator->getNextNode();
        }

        if (iterator != nullptr) {
            printf("\nTu valor se encuentra en la posicion %d\n", positionInList);
        } else {
            printf("\nTu valor no se encuentra en la lista\n");
        }

    } else {
        printf("\nLista vacia\n");
    }

    return hasFoundData;
}

template <typename T>
bool DoublyLinkedList<T>::searchFromEnd(T data) {
    bool hasFoundData{false};

    if (!isEmpty()) {
        Node<T> *iterator{lastNode};
        int positionInList{1};

        while (iterator != nullptr && !(hasFoundData = iterator->getData() == data)) {
            positionInList++;
            iterator = iterator->getPreviousNode();
        }

        if (iterator != nullptr) {
            printf("\nTu valor se encuentra en la posicion %d\n", positionInList);
        } else {
            printf("\nTu valor no se encuentra en la lista\n");
        }

    } else {
        printf("\nLista vacia\n");
    }

    return hasFoundData;
}

template <typename T>
bool DoublyLinkedList<T>::deleteAtBegin() {

    if (!isEmpty()) {
        Node<T> *nodeToDelete{firstNode};

        firstNode = firstNode->getNextNode();

        if (firstNode != nullptr) {
            firstNode->setPreviousNode(nullptr);
        } else {
            lastNode = nullptr;
        }

        delete nodeToDelete;

    } else {
        printf("\nERROR: No se puede eliminar porque la lista esta vacia\n");
    }

    return !isEmpty();
}

template <typename T>
bool DoublyLinkedList<T>::deleteAtEnd() {
    if (!isEmpty()) {
        Node<T> *nodeToDelete{lastNode};
        lastNode = lastNode->getPreviousNode();

        if (lastNode != nullptr) {
            lastNode->setNextNode(nullptr);

        } else {
            firstNode = nullptr;
        }

        delete nodeToDelete;

    } else {
        printf("\nERROR: No se puede eliminar porque la lista esta vacia\n");
    }

    return !isEmpty();
}

template <typename T>
bool DoublyLinkedList<T>::deleteAt(int positionToDelete) {
    int sizeOfList{size()};
    int listPosition{};

    if (!isEmpty() && positionToDelete > 0 && positionToDelete <= sizeOfList) {

        if (positionToDelete == 1) {
            deleteAtBegin();
        } else if (positionToDelete == sizeOfList) {
            deleteAtEnd();
        } else {
            Node<T> *iterator{firstNode};

            while (++listPosition < positionToDelete) {
                iterator = iterator->getNextNode();
            }

            iterator->getPreviousNode()->setNextNode(iterator->getNextNode());
            iterator->getNextNode()->setPreviousNode(iterator->getPreviousNode());

            delete iterator;
        }
    } else if (isEmpty()) {
        printf("\nERROR: No se puede eliminar porque la lista esta vacia\n");

    } else if (positionToDelete > sizeOfList || positionToDelete <= 0) {
        
        printf("\nERROR: No se puede eliminar en la posicion indicada\n");
    }

    return !isEmpty() && positionToDelete > 0 && positionToDelete <= sizeOfList;
}

template <typename T>
void DoublyLinkedList<T>::print() {

    if (!isEmpty()) {
        Node<T> *iterator{firstNode};

        std::cout << '\n';

        while (iterator != nullptr) {
            std::cout << "[ " << iterator->getData() << " ] ";
            iterator = iterator->getNextNode();
        }

        std::cout << '\n';

    } else {
        printf("\nLista vacia\n");
    }
}

template <typename T>
Node<T> *DoublyLinkedList<T>::first() {
    return this->getFirstNode();
}

template <typename T>
Node<T> *DoublyLinkedList<T>::last() {
    return this->getLastNode();
}

#endif