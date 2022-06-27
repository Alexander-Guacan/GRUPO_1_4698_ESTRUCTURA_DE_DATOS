#include "HashInt.hpp"
#include <iostream>

short HashInt::hashCode(const int &element) {
    return element % this->MAX_CAPACITY;
}

void HashInt::insert(const int &element) {
    short key{hashCode(element)};
    Node<int> *newNode = new Node<int>(element);

    if (this->array[key] == nullptr) {
        array[key] = newNode;
        return;
    }

    Node<int> *iterator{this->array[key]};
    while (iterator->getNextNode() != nullptr) {
        iterator = iterator->getNextNode();
    }

    iterator->setNextNode(newNode);
}

short HashInt::search(const int &element) {
    return 0;
}
bool HashInt::deleteElement(const int &element) {
    return false;
}

void HashInt::print() {
    for (int i{}; i < this->MAX_CAPACITY; i++) {
        Node<int> *iterator{this->array[i]};
        std::cout << i + 1 << "->";
        while (iterator != nullptr) {
            std::cout << iterator->getData() << "->";
            iterator = iterator->getNextNode();
        }
        std::cout << "nullptr\n";
    }
}