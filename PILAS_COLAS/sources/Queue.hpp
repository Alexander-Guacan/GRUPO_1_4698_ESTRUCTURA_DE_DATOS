#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "DataStructure.hpp"

template <typename T>
class Queue : public DataStructure<T> {
    private:
        SimpleNode<T> *tail{nullptr};

    public:
        // Agrega un nuevo elemento al final de la lista
        void add(T *newData);
        // Retorna el elemento en la cabeza de la lista y luego es eliminado
        T *poll();
        // Retorna el elemento en la cabeza de la lista
        T *peek();
        // destructor
        ~Queue();
};

template <typename T>
void Queue<T>::add(T *newData) {
    SimpleNode<T> *newNode = new SimpleNode<T>(newData);

    if (!this->isEmpty()) {
        tail->setNextNode(newNode);
    } else {
        this->head = newNode;
    }

    tail = newNode;
}

template <typename T>
T *Queue<T>::poll() {
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
T *Queue<T>::peek() {
    if (!this->isEmpty()) {

        return this->head->getData();
    } else {
        return nullptr;
    }
}

template <typename T>
Queue<T>::~Queue() {
    while (!this->isEmpty()) {
        SimpleNode<T> *auxiliar{this->head};
        this->head = this->head->getNextNode();
        delete auxiliar;
    }
}


#endif