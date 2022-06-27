#include "HashInt.hpp"
#include <iostream>

short HashInt::hashCode(const int &element) {
    return element % this->MAX_CAPACITY;
}

bool HashInt::isEmpty() {
    return size() == 0;
}

void HashInt::insert(const int &element) {
    short key{hashCode(element)};
    Node<int> *newNode = new Node<int>(element);

    if (this->array[key] == nullptr) {
        this->array[key] = newNode;
    } else {
        Node<int> *iterator{this->array[key]};
        while (iterator->getNextNode() != nullptr) {
            iterator = iterator->getNextNode();
        }

        iterator->setNextNode(newNode);
    }


    this->elements++;
}

short HashInt::search(const int &element) {
    const int ELEMENT_NOT_FOUND{-1};

    if (isEmpty())
        return ELEMENT_NOT_FOUND;

    short key{hashCode(element)};

    if (this->array[key] == nullptr)
        return ELEMENT_NOT_FOUND;

    bool hasFoundElement{false};
    Node<int> *iterator{this->array[key]};
    while (iterator != nullptr && !(hasFoundElement = iterator->getData() == element))
        iterator = iterator->getNextNode();

    return (hasFoundElement) ? key : ELEMENT_NOT_FOUND;
}
bool HashInt::deleteElement(const int &element) {
    return false;
}

void HashInt::print() {
    for (int i{}; i < this->MAX_CAPACITY; i++) {
        Node<int> *iterator{this->array[i]};
        std::cout << i << ".- [";
        while (iterator != nullptr) {
            std::cout << iterator->getData() << "->";
            iterator = iterator->getNextNode();
        }
        std::cout << "nullptr]\n";
    }
}