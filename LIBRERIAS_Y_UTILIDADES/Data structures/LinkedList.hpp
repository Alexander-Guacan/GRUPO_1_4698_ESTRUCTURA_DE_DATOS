#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "List.hpp"
#include "Iterable.hpp"

template <typename E>
class LinkedList : public List<E>, public Iterable<E> {

    public:
        // Returns an iterator over a set of elements of type E
        Iterator<E> iterator();
        // Returns an iterator over a set of elements of type E in reverse sequential order
        Iterator<E> descendingIterator();
        // Returns true if this LinkedList contains no elements
        bool isEmpty() const;
        // Returns the number of elements in this LinkedList
        size_t size() const;
        // Removes all elements from this LinkedList
        void clear();
        // Inserts the specified element at the beginning of this LinkedList
        void addFirst(const E &element);
        // Appends the specified element to the end of the LinkedList
        void addLast(const E &element);
        // Inserts the specified element at the specified position in this LinkedList.
        bool add(size_t index, const E &element);
        // Returns the element at the specifid position in this LinkedList. Throws: IndexOutOfBoundsException
        E &get(size_t index);
        // Returns the index of the first ocurrence of the specified element in this LinkedList, or -1 if this LinkedList does not contain the element
        ssize_t indexOf(const E &element) const;
        // Returns the index of the last ocurrence of the specified element in this LinkedList, or -1 if this LinkedList does not contain the element
        ssize_t lastIndexOf(const E &element) const;
        // Removes the element at the specified position in this LinkedList and returns it. Throws: IndexOutOfBoundsException
        E remove(size_t index);
        // Removes the first ocurrence of the specified element from this LinkedList, if it is present
        bool removeFirstOcurrence(const E &element);
        // Removes the last ocurrence of the specified element from this list, if it is present
        bool removeLastOcurrence(const E &element);
        // Replace the element at the specified position in this LinkedList with the specified element, and returns the element removed. Throws: IndexOutOfBoundsException
        E set(size_t index, const E &element);
        // Destructor
        ~LinkedList();
};

template <typename E>
Iterator<E> LinkedList<E>::iterator() {
    return Iterator<E>(this->head);
}

template <typename E>
Iterator<E> LinkedList<E>::descendingIterator() {
    return Iterator<E>(this->tail, true);
}

template <typename E>
bool LinkedList<E>::isEmpty() const {
    return this->head == nullptr;
}

template <typename E>
size_t LinkedList<E>::size() const {
    size_t amountOfElements{};
    Node<E> *iterator{this->head};

    while (iterator != nullptr) {
        amountOfElements++;
        iterator = iterator->getNextNode();
    }

    return amountOfElements;
}

template<typename E>
void LinkedList<E>::clear() {
    while (!isEmpty()) {
        Node<E> *auxiliar{this->head};
        this->head = this->head->getNextNode();
        delete auxiliar;
    }

    this->tail = nullptr;
}

template <typename E>
void LinkedList<E>::addFirst(const E &element) {
    Node<E> *newNode = new Node<E>(element);

    if (!isEmpty()) {
        newNode->setNextNode(this->head);
        this->head->setPreviousNode(newNode);
    } else {
        this->tail = newNode;
    }

    this->head = newNode;
}

template <typename E>
void LinkedList<E>::addLast(const E &element) {
    Node<E> *newNode = new Node<E>(element);

    if (!isEmpty()) {
        this->tail->setNextNode(newNode);
        newNode->setPreviousNode(this->tail);
    } else {
        this->head = newNode;
    }

    this->tail = newNode;
}

template <typename E>
bool LinkedList<E>::add(size_t index, const E &element) {
    if (index < 0 || index > size())
        return false;

    if (index == 0) {
        addFirst(element);
        return true;
    }
    
    if (index == size()) {
        addLast(element);
        return true;
    }

    Node<E> *iterator{this->head};
    size_t position{};

    while (position++ < index)
        iterator = iterator->getNextNode();

    Node<E> *newNode = new Node<E>(element);
    newNode->setPreviousNode(iterator->getPreviousNode());
    newNode->setNextNode(iterator);

    iterator->setPreviousNode(newNode);
    iterator->getPreviousNode()->setNextNode(newNode);

    return true;
}

template <typename E>
E &LinkedList<E>::get(size_t index) {
    if (index < 0 || index >= size())
        throw "IndexOutOfBoundsException";

    Node<E> *iterator{this->head};
    size_t position{};

    while (position++ < index)
        iterator = iterator->getNextNode();

    return iterator->getData();
}

template <typename E>
ssize_t LinkedList<E>::indexOf(const E &element) const {
    const ssize_t ELEMENT_NOT_FOUND{-1};

    if (isEmpty())
        return ELEMENT_NOT_FOUND;

    Node<E> *iterator{this->head};
    ssize_t index{ELEMENT_NOT_FOUND};
    bool hasFoundElement{false};

    while (iterator != nullptr && !hasFoundElement){
        index++;
        hasFoundElement = iterator->getData() == element;
        iterator = iterator->getNextNode();
    }

    return (hasFoundElement) ? index : ELEMENT_NOT_FOUND;
}

template <typename E>
ssize_t LinkedList<E>::lastIndexOf(const E &element) const {
    const ssize_t ELEMENT_NOT_FOUND{-1};

    if (isEmpty())
        return ELEMENT_NOT_FOUND;

    Node<E> *iterator{this->head};
    size_t index{};
    ssize_t lastMatchIndex{ELEMENT_NOT_FOUND};

    while (iterator != nullptr) {
        if (iterator->getData() == element) {
            lastMatchIndex = index;
        }

        index++;
        iterator = iterator->getNextNode();
    }

    return lastMatchIndex;
}

template <typename E>
E LinkedList<E>::remove(size_t index) {
    if (index < 0 || index >= size())
        throw "IndexOutOfBoundsException";

    if (index == 0) {
        E elementErased = this->head->getData();

        Node<E> *nodeToDelete{this->head};
        this->head = this->head->getNextNode();

        delete nodeToDelete;

        if (isEmpty())
            this->tail = nullptr;

        return elementErased;
    }

    if (index == size() - 1) {
        E elementErased = this->tail->getData();

        Node<E> *nodeToDelete{this->tail};
        this->tail = this->tail->getPreviousNode();

        delete nodeToDelete;

        if (isEmpty())
            this->tail = nullptr;
        
        return elementErased;
    }

    Node<E> *iterator{this->head};
    size_t position{};

    while (position++ < index)
        iterator = iterator->getNextNode();

    E elementErased = iterator->getData();

    iterator->getPreviousNode()->setNextNode(iterator->getNextNode());
    iterator->getNextNode()->setPreviousNode(iterator->getPreviousNode());

    delete iterator;

    return elementErased;
}

template <typename E>
bool LinkedList<E>::removeFirstOcurrence(const E &element) {
    if (isEmpty())
        return false;

    const ssize_t ELEMENT_NOT_FOUND{-1};
    ssize_t indexMatch{indexOf(element)};

    if (indexMatch == ELEMENT_NOT_FOUND)
        return false;

    remove(indexMatch);
    return true;
}

template <typename E>
bool LinkedList<E>::removeLastOcurrence(const E &element) {
    if (isEmpty())
        return false;

    const ssize_t ELEMENT_NOT_FOUND{-1};
    ssize_t indexMatch{lastIndexOf(element)};

    if (indexMatch == ELEMENT_NOT_FOUND)
        return false;

    remove(indexMatch);

    return true;
}

template <typename E>
E LinkedList<E>::set(size_t index, const E &element) {
    if (index < 0 || index >= size())
        throw "IndexOutOfBoundsException";

    Node<E> *iterator{this->head};
    size_t position{};

    while (position++ < index)
        iterator = iterator->getNextNode();

    E elementErased = iterator->getData();
    iterator->setData(element);

    return elementErased;
}

template<typename E>
LinkedList<E>::~LinkedList() {
    clear();
}

#endif