#ifndef DOUBLE_NODE_HPP
#define DOUBLE_NODE_HPP

#include "Node.hpp"

template <typename T>
class DoubleNode : public Node<T> {
    DoubleNode<T> *previousNode{nullptr};
    DoubleNode<T> *nextNode{nullptr};

    public:
        DoubleNode(T *initialData);
        DoubleNode<T> *getPreviousNode();
        DoubleNode<T> *getNextNode();
        void setPreviousNode(DoubleNode<T> *newPreviousNode);
        void setNextNode(DoubleNode<T> *newNextNode);
};

template <typename T>
DoubleNode<T>::DoubleNode(T *initialData) :
    Node<T>(initialData) 
{}

template <typename T>
DoubleNode<T> *DoubleNode<T>::getPreviousNode() {
    return this->previousNode;
}

template <typename T>
DoubleNode<T> *DoubleNode<T>::getNextNode() {
    return this->nextNode;
}

template <typename T>
void DoubleNode<T>::setPreviousNode(DoubleNode<T> *newPreviousNode) {
    this->previousNode = newPreviousNode;
}

template <typename T>
void DoubleNode<T>::setNextNode(DoubleNode<T> *newNextNode) {
    this->nextNode = newNextNode;
}

#endif