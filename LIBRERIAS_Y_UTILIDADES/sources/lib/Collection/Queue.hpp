#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Collection.hpp"
#include "Iterable.hpp"

template <typename E>
class Queue : public Collection<E>, public Iterable<E> {

    public:
        // Returns an iterator over a set of elements of type E
        Iterator<E> iterator() const;
        // Returns an iterator over a set of elements of type E in reverse sequential order
        Iterator<E> descendingIterator() const;
        // Returns true if this Queue contains no elements
        bool isEmpty() const;
        // Returns the number of elements in this Queue
        int size() const;
        // Removes all elements from this Queue
        void clear();
        // Inserts the element into this Queue
        void add(const E &element);
        // Return the element and remove the head of this Queue. Throw: EmptyQueueException
        E poll();
        // Returns the element, but does not remove, the head of this Queue. Throw: EmptyQueueException
        E &peek();
        // Destructor
        ~Queue();
};

template <typename E>
Iterator<E> Queue<E>::iterator() const {
    return Iterator<E>(this->head);
}

template <typename E>
Iterator<E> Queue<E>::descendingIterator() const {
    return Iterator<E>(this->tail, true);
}

template <typename E>
bool Queue<E>::isEmpty() const {
    return this->head == nullptr;
}

template <typename E>
int Queue<E>::size() const {
    int amountOfElements{};
    Node<E> *iterator{this->head};

    while (iterator != nullptr) {
        amountOfElements++;
        iterator = iterator->getNextNode();
    }

    return amountOfElements;
}

template<typename E>
void Queue<E>::clear() {
    while (!isEmpty()) {
        Node<E> *auxiliar{this->head};
        this->head = this->head->getNextNode();
        delete auxiliar;
    }

    this->tail = nullptr;
}

template <typename E>
void Queue<E>::add(const E &element) {
    Node<E> *newNode = new Node<E>(element);

    if (!isEmpty()) {
        newNode->setPreviousNode(this->tail);
        this->tail->setNextNode(newNode);
    } else {
        this->head = newNode;
    }

    this->tail = newNode;
}

template <typename E>
E Queue<E>::poll() {
    if (isEmpty())
        throw "EmptyQueueException.";

    E data = this->head->getData();
    
    Node<E> *auxiliar{this->head};
    this->head = this->head->getNextNode();

    delete auxiliar;
    auxiliar = nullptr;

    if (isEmpty())
        this->tail = nullptr;

    return data;
}

template <typename E>
E &Queue<E>::peek() {
    if (isEmpty())
        throw "EmptyQueueException.";

    return this->head->getData();
}

template <typename E>
Queue<E>::~Queue() {
    clear();
}


#endif