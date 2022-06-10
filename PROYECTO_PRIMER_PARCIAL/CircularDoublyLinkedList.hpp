#ifndef CIRCULAR_DOUBLY_LINKED_LIST_HPP
#define CIRCULAR_DOUBLY_LINKED_LIST_HPP

#include "List.hpp"
#include "DoubleNode.hpp"
#include <iostream>

template <typename T>
class CircularDoublyLinkedList : public List<T> {
    DoubleNode<T> *firstNode{nullptr};
    DoubleNode<T> *lastNode{nullptr};
    bool dataRepeat{true};

    private:
        DoubleNode<T> *insertNewNode(T *data);

    public:
        CircularDoublyLinkedList(bool _dataRepeat);
        bool dataExist(T *dataToInsert);
        bool isEmpty();
        short size();
        bool insertAtBegin(T *data);
        bool insertAtEnd(T *data);
        bool insertAt(T *data, short positionToInsert);
        bool deleteAtBegin();
        bool deleteAtEnd();
        bool deleteAt(short positionToDelete);
        void print();
        void print(short positionToPrint);
        IteratorLinkedList<T> *getIterator();
};

template <typename T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList(bool _dataRepeat) {
    this->dataRepeat = _dataRepeat;
}

template <typename T>
bool CircularDoublyLinkedList<T>::dataExist(T *dataToInsert) {
    if (!isEmpty()) {
        DoubleNode<T> *iterator{this->firstNode};
        bool isRepeat{false};

        do {
            isRepeat = *(dataToInsert) == *(iterator->getData());
            iterator = iterator->getNextNode();
        } while (iterator != this->firstNode && !isRepeat);

        return isRepeat;
    }

    return false;
}

template <typename T>
DoubleNode<T> *CircularDoublyLinkedList<T>::insertNewNode(T *data) {
    DoubleNode<T> *newNode = new DoubleNode<T>(data);

    if (!dataRepeat) {
        
        if (dataExist(data)) {
            delete newNode;
            newNode = nullptr;
        }
    }

    if (newNode != nullptr) {

        if (!isEmpty()) {
            newNode->setNextNode(this->firstNode);
            newNode->setPreviousNode(this->lastNode);
        } else {
            this->firstNode = newNode;
            this->lastNode = newNode;
        }

        this->firstNode->setPreviousNode(newNode);
        this->lastNode->setNextNode(newNode);
    }    

    return newNode;
}

template <typename T>
bool CircularDoublyLinkedList<T>::isEmpty() {
    return this->firstNode == nullptr;
}

template <typename T>
short CircularDoublyLinkedList<T>::size() {
    if (!isEmpty()) {
        short sizeOfList{1};

        DoubleNode<T> *iterator{this->firstNode};

        while (iterator != this->lastNode) {
            sizeOfList++;
            iterator = iterator->getNextNode();
        }

        return sizeOfList;
        
    } else {
        return 0;
    }
}

template <typename T>
bool CircularDoublyLinkedList<T>::insertAtBegin(T *data) {
    DoubleNode<T> *newfirstNode = insertNewNode(data);

    if (newfirstNode != nullptr) {
        this->firstNode = newfirstNode;
        return true;
    }
    
    return false;
}

template <typename T>
bool CircularDoublyLinkedList<T>::insertAtEnd(T *data) {
    DoubleNode<T> *newLastNode = insertNewNode(data);

    if (newLastNode != nullptr) {
        this->lastNode = newLastNode;
        return true;
    }

    return false;
}

template <typename T>
bool CircularDoublyLinkedList<T>::insertAt(T *data, short positionToInsert) {
    DoubleNode<T> *newNode = new DoubleNode<T>(data);

    if (!isEmpty() && (positionToInsert > 0 && positionToInsert <= size())) {

        if (positionToInsert == 1)
            return insertAtBegin(data);

        else if (positionToInsert == size())
            return insertAtEnd(data);

        else if (!dataExist(data)) {
            short positionInList{2};
            DoubleNode<T> *iterator{this->firstNode->getNextNode()};

            while (positionInList < positionToInsert) {
                iterator = iterator->getNextNode();
                positionInList++;
            }

            DoubleNode<T> *newNode = new DoubleNode<T>(data);

            newNode->setPreviousNode(iterator->getPreviousNode());
            newNode->setNextNode(iterator);

            iterator->getPreviousNode()->setNextNode(newNode);
            iterator->setPreviousNode(newNode);

            return true;
        }

    }
    
    return false;
}

template <typename T>
bool CircularDoublyLinkedList<T>::deleteAtBegin() {
    if (!isEmpty()) {
        DoubleNode<T> *nodeToDelete{this->firstNode};

        if (size() == 1) {
            this->firstNode = nullptr;
            this->lastNode = nullptr;
        } else {
            this->firstNode = this->firstNode->getNextNode();
            this->firstNode->setPreviousNode(this->lastNode);
            this->lastNode->setNextNode(this->firstNode);
        }

        delete nodeToDelete;

        return true;
    } else {
        return false;
    }
}

template <typename T>
bool CircularDoublyLinkedList<T>::deleteAtEnd() {
    if (!isEmpty()) {
        DoubleNode<T> *nodeToDelete{this->lastNode};

        if (size() == 1) {
            this->firstNode = nullptr;
            this->lastNode = nullptr;
        } else {
            this->lastNode = this->lastNode->getPreviousNode();
            this->lastNode->setNextNode(this->firstNode);
            this->firstNode->setPreviousNode(this->lastNode);
        }

        delete nodeToDelete;

        return true;
    } else {
        return false;
    }
}

template <typename T>
bool CircularDoublyLinkedList<T>::deleteAt(short positionToDelete) {
    if (!isEmpty() && (positionToDelete > 0 && positionToDelete <= size())) {
        if (positionToDelete == 1)
            deleteAtBegin();

        else if (positionToDelete == size())
            deleteAtEnd();

        else {
            short positionInList{2};
            DoubleNode<T> *nodeToDelete{firstNode->getNextNode()};

            while (positionInList < positionToDelete) {
                positionInList++;
                nodeToDelete = nodeToDelete->getNextNode();
            }

            nodeToDelete->getPreviousNode()->setNextNode(nodeToDelete->getNextNode());
            nodeToDelete->getNextNode()->setPreviousNode(nodeToDelete->getPreviousNode());

            delete nodeToDelete;
        }

        return true;
    } else {
        return false;
    }
}

template <typename T>
void CircularDoublyLinkedList<T>::print() {
    if (!isEmpty()) {
        DoubleNode<T> *iterator{this->firstNode};

        do {
            std::cout << *(iterator->getData()) << ' ';
            iterator = iterator->getNextNode();
        } while (iterator != this->firstNode);
    } else {
        std::cout << "\nInformacion no disponible\n";
    }
}

template <typename T>
void CircularDoublyLinkedList<T>::print(short positionToPrint) {
    if (!isEmpty() && (positionToPrint > 0 && positionToPrint <= size())) {
        DoubleNode<T> *iterator{this->firstNode};

        short positionInList{1};

        while (positionInList < positionToPrint) {
            positionInList++;
            iterator = iterator->getNextNode();
        }

        std::cout << *(iterator->getData()) << ' ';
    } else {
        std::cout << "\nInformacion no disponible\n";
    }
}

template <typename T>
IteratorLinkedList<T> *CircularDoublyLinkedList<T>::getIterator() {
    return new IteratorLinkedList<T>(this->firstNode, this->lastNode);
}

#endif