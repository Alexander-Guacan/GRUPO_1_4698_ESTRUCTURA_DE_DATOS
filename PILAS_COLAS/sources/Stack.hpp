#ifndef STACK_HPP
#define STACK_HPP

#include "DataStructure.hpp"

template <typename T>
class Stack : public DataStructure<T> {

    public:
        // Agrega un nuevo elemento al principio de la lista
        void push(T *newData);
        // Retorna el elemento que se encuentra en la cabeza de la lista y lo elimina de la misma
        T *pop();
        // Retorna el elemento que se encuentra al principio de la lista
        T *top();
        // Destructor
        ~Stack();
};

template <typename T>
void Stack<T>::push(T *newData) {
    SimpleNode<T> *newNode = new SimpleNode<T>(newData);

    if (!this->isEmpty()) {
        newNode->setNextNode(this->head);
    }

    this->head = newNode;
}

template <typename T>
T *Stack<T>::pop() {
    if (!this->isEmpty()) {
        SimpleNode<T> *auxiliar{this->head};
        T *data = this->head->getData();

        this->head = this->head->getNextNode();
        delete auxiliar;

        return data;
    } else {
        return nullptr;
    }
}

template <typename T>
T *Stack<T>::top() {
    if (!this->isEmpty()) {
        return this->head->getData();
    } else {
        return nullptr;
    }
}

template <typename T>
Stack<T>::~Stack() {
    while (!this->isEmpty()) {
        SimpleNode<T> *auxiliar{this->head};
        this->head = this->head->getNextNode();
        delete auxiliar;
    }
}

#endif