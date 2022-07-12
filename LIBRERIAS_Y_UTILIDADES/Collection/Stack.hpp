#ifndef STACK_HPP
#define STACK_HPP

#include "Collection.hpp"
#include "Iterable.hpp"

template <typename E>
class Stack : public Collection<E>, public Iterable<E> {

    public:
        // Returns an iterator over a set of elements of type E
        Iterator<E> iterator();
        // Returns an iterator over a set of elements of type E in reverse sequential order
        Iterator<E> descendingIterator();
        // Returns true if this collection contains no elements
        bool isEmpty() const;
        // Returns the number of elements in this collection
        size_t size() const;
        // Removes all elements from this collection
        void clear();
        // Pushes an item onto the top of this stack
        void push(const E &newData);
        // Removes the element at the top of this stack and returns it. Throw: EmptyStackException
        E pop();
        // Returns the element at the top of this stack without removing it from the stack. Throw: EmptyStackException
        E &top();
        // Destructor
        ~Stack();
};

template <typename E>
Iterator<E> Stack<E>::iterator() {
    return Iterator<E>(this->head);
}

template <typename E>
Iterator<E> Stack<E>::descendingIterator() {
    return Iterator<E>(this->tail, true);
}

template <typename E>
bool Stack<E>::isEmpty() const {
    return this->head == nullptr;
}

template <typename E>
size_t Stack<E>::size() const {
    size_t amountOfElements{};
    Node<E> *iterator{this->head};

    while (iterator != nullptr) {
        amountOfElements++;
        iterator = iterator->getNextNode();
    }

    return amountOfElements;
}

template<typename E>
void Stack<E>::clear() {
    while (!isEmpty()) {
        Node<E> *auxiliar{this->head};
        this->head = this->head->getNextNode();
        delete auxiliar;
    }

    this->tail = nullptr;
}

template <typename E>
void Stack<E>::push(const E &newData) {
    Node<E> *newNode = new Node<E>(newData);

    if (!isEmpty()) {
        newNode->setNextNode(this->head);
        this->head->setPreviousNode(newNode);
    } else {
        this->tail = newNode;
    }

    this->head = newNode;
}

template <typename E>
E Stack<E>::pop() {
    if (isEmpty())
        throw "EmptyStackException.";

    E dataErased = this->head->getData();

    Node<E> *auxiliar{this->head};
    this->head = this->head->getNextNode();

    delete auxiliar;
    auxiliar = nullptr;

    if (isEmpty())
        this->tail = nullptr;

    return dataErased;
}

template <typename E>
E &Stack<E>::top() {
    if (isEmpty())
        throw "EmptyStackException.";

    return this->head->getData();
}

template <typename E>
Stack<E>::~Stack() {
    clear();
}

#endif