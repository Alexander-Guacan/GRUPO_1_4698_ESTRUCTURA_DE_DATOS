#ifndef ITERATOR_LINKED_LIST_HPP
#define ITERATOR_LINKED_LIST_HPP

#include "DoubleNode.hpp"

template <typename T>
class IteratorLinkedList {
    DoubleNode<T> *cursor{nullptr};
    DoubleNode<T> *endOfList{nullptr};
    bool hasMoreData{false};

    public:
        IteratorLinkedList(DoubleNode<T> *firstNode, DoubleNode<T> *lastNode);
        bool hasNext();
        T *getData();
};

template <typename T>
IteratorLinkedList<T>::IteratorLinkedList(DoubleNode<T> *firstNode, DoubleNode<T> *lastNode) {
    this->cursor = firstNode;
    this->endOfList = lastNode;
    hasMoreData = cursor != nullptr;
}

template <typename T>
bool IteratorLinkedList<T>::hasNext() {
    return this->cursor != nullptr;
}

template <typename T>
T *IteratorLinkedList<T>::getData() {
    T *data{nullptr};

    if (hasNext()) {
        data = this->cursor->getData();

        if (this->cursor == endOfList)
            this->cursor = nullptr;
        else
            this->cursor = this->cursor->getNextNode();
            
    }

    return data;
}

#endif