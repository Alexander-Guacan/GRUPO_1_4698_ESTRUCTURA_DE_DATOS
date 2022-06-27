#include "HashString.hpp"
#include <iostream>

short HashString::hashCode(const std::string &element) {
    int sumAscii{0};
    for (int i{}; i < element.length(); i++) {
        sumAscii += element[i];
    }

    return sumAscii % this->MAX_CAPACITY;
}

bool HashString::isEmpty() {
    return size() == 0;
}

void HashString::insert(const std::string &element) {
    short key{hashCode(element)};
    Node<std::string> *newNode = new Node<std::string>(element);

    if (this->array[key] == nullptr) {
        this->array[key] = newNode;
    } else {
        Node<std::string> *iterator{this->array[key]};
        while (iterator->getNextNode() != nullptr) {
            iterator = iterator->getNextNode();
        }

        iterator->setNextNode(newNode);
        newNode->setPreviousNode(iterator);
    }

    this->elements++;
}

short HashString::search(const std::string &element) {
    const int ELEMENT_NOT_FOUND{-1};

    if (isEmpty())
        return ELEMENT_NOT_FOUND;

    short key{hashCode(element)};

    if (this->array[key] == nullptr)
        return ELEMENT_NOT_FOUND;

    bool hasFoundElement{false};
    Node<std::string> *iterator{this->array[key]};
    while (iterator != nullptr && !(hasFoundElement = iterator->getData() == element))
        iterator = iterator->getNextNode();

    return (hasFoundElement) ? key : ELEMENT_NOT_FOUND;
}

bool HashString::deleteElement(const std::string &element) {
    short key{hashCode(element)};

    if (this->array[key] == nullptr)
        return false;

    Node<std::string> *iterator{this->array[key]};

    bool hasFoundElement{false};
    while (iterator != nullptr && !(hasFoundElement = iterator->getData() == element))
        iterator = iterator->getNextNode();

    if (hasFoundElement) {
        if (iterator->getNextNode() != nullptr)
            iterator->getNextNode()->setPreviousNode(iterator->getPreviousNode());

        if (iterator == this->array[key]) {
            this->array[key] = iterator->getNextNode();
        } else {
            iterator->getPreviousNode()->setNextNode(iterator->getNextNode());
        }

        delete iterator;
        this->elements--;
        return true;
    }

    return false;
}

void HashString::print() {
    for (int i{}; i < this->MAX_CAPACITY; i++) {
        Node<std::string> *iterator{this->array[i]};
        std::cout << i << ".- [";
        while (iterator != nullptr) {
            std::cout << iterator->getData() << "->";
            iterator = iterator->getNextNode();
        }
        std::cout << "nullptr]\n";
    }
}