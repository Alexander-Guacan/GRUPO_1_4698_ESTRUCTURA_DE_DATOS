#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "Node.hpp"

template <typename E>
class Iterator {
    private:
        bool reverseOrder{false};
         Node<E> *cursor{nullptr};

    public:
        // Default constructor
        Iterator() = default;
        // Constructor
        Iterator(Node<E> *&begin);
        // Constructor for the descendingIterator method
        Iterator(Node<E> *&last, bool reverseOrder);
        // Returns the next element in the iteration
        E &next();
        // Returns the previous element in the iteration
        E &previous();
        // Return true if the iteration has more elements in the forward direction
        bool hasNext() const;
        // Return true if the iteration has more elements in the reverse direction
        bool hasPrevious() const;
        // Destructor
        ~Iterator();
};

template <typename E>
Iterator<E>::Iterator(Node<E> *&begin) {
    this->cursor = begin;
}

template <typename E>
Iterator<E>::Iterator(Node<E> *&last, bool reverseOrder) {
    this->cursor = last;
    this->reverseOrder = reverseOrder;
}

template <typename E>
E &Iterator<E>::next() {
    E &element = this->cursor->getData();
    this->cursor = (!reverseOrder) ? this->cursor->getNextNode() : this->cursor->getPreviousNode();

    return element;
}

template <typename E>
E &Iterator<E>::previous() {
    E &element = this->cursor->getData();
    this->cursor = (!reverseOrder) ? this->cursor->getPreviousNode() : this->cursor->getNextNode();

    return element;
}

template <typename E>
bool Iterator<E>::hasNext() const {
    return this->cursor != nullptr;
}

template <typename E>
bool Iterator<E>::hasPrevious() const {
    return this->cursor != nullptr;
}

template <typename E>
Iterator<E>::~Iterator() {
    this->cursor = nullptr;
}

#endif