#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template <typename T>
class Node {
    T *data;

    public:
        Node(T *initialData);
        T* getData();
        void setData(T *newData);
};

template <typename T>
Node<T>::Node(T *initialData) {
    this->data = initialData;
}

template <typename T>
T *Node<T>::getData() {
    return this->data;
}

template <typename T>
void Node<T>::setData(T *newData) {
    this->data = newData;
}

#endif