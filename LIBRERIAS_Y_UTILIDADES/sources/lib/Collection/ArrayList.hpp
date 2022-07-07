#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include "List.hpp"

template <typename E>
class ArrayList : public List<E> {
    private:
        E *array{nullptr};
        size_t positionToInsert{};
        size_t elementsInserted{};
        size_t capacity{10};
        const size_t CAPACITY_INCREMENT{10};

        // Returns true if number of elements inserted greather than capacity
        bool isFull();
        // Copys all elements of actual array to new array with size of actual array plus capacity increment
        void resize();

    public:
        // Constructs an empty list with an initial capacity of ten.
        ArrayList();
        // Constructs an empty list with the specified initial capacity.
        ArrayList(size_t initialCapacity);
        // Returns true if this Array contains no elements
        bool isEmpty() const;
        // Returns the number of elements in this Array
        size_t size() const;
        // Removes all elements from this Array
        void clear();
        // Inserts the specified element at the beginning of this list
        void addFirst(const E &element);
        // Appends the specified element to the end of the list
        void addLast(const E &element);
        // Inserts the specified element at the specified position in this list
        bool add(size_t index, const E &element);
        // Returns the element at the specified position in this list. Throws: IndexOutOfBoundsException
        E &get(size_t index);
        // Returns the element at the specified position in this list. Throws: IndexOutOfBoundsException
        E &operator[](size_t index);
        // Returns the index of the first ocurrence of the specified element in this list, or -1 if this list does not contain the element
        ssize_t indexOf(const E &element) const;
        // Returns the index of the last ocurrence of the specified element in this list, or -1 if this list does not contain the element
        ssize_t lastIndexOf(const E &element) const;
        // Removes the element at the specified position in this list and returns it. Throws: IndexOutOfBoundsException
        E remove(size_t index);
        // Removes the first ocurrence of the specified element from this list, if it is present
        bool removeFirstOcurrence(const E &element);
        // Removes the last ocurrence of the specified element from this list, if it is present
        bool removeLastOcurrence(const E &element);
        // Replace the element at the specified position in this list with the specified element, and returns the element removed. Throws: IndexOutOfBoundsException
        E set(size_t index, const E &element);
        // Destructor
        ~ArrayList();
};

template <typename E>
bool ArrayList<E>::isFull(){
    return size() >= this->capacity;
}

template <typename E>
void ArrayList<E>::resize() {
    this->capacity = this->elementsInserted + this->CAPACITY_INCREMENT;
    E *newArray = new E[this->capacity]{};

    for (size_t i{}; i < size(); i++) {
        newArray[i] = this->array[i];
    }

    delete[] this->array;
    this->array = newArray;
    newArray = nullptr;
}

template <typename E>
ArrayList<E>::ArrayList() {
    this->array = new E[this->capacity]{};
}

template <typename E>
ArrayList<E>::ArrayList(size_t initialCapacity) {
    this->capacity = initialCapacity;
    this->array = new E[this->capacity]{};
}

template <typename E>
bool ArrayList<E>::isEmpty() const {
    return size() <= 0 || this->array == nullptr;
}

template <typename E>
size_t ArrayList<E>::size() const {
    return this->elementsInserted;
}

template <typename E>
void ArrayList<E>::clear() {

    delete[] this->array;
    this->capacity = 10;
    this->array = new E[this->capacity]{};

    this->elementsInserted = 0;
    this->positionToInsert = 0;
}

template <typename E>
void ArrayList<E>::addFirst(const E &element) {
    if (isEmpty()) {
        this->array[this->positionToInsert] = element;

    } else {
        for (size_t i{this->positionToInsert}; i > 0; i--) {
            this->array[i] = this->array[i - 1];
        }

        this->array[0] = element;
    }

    this->elementsInserted++;
    this->positionToInsert++;

    if (isFull())
        resize();
}

template <typename E>
void ArrayList<E>::addLast(const E &element) {
    this->array[this->positionToInsert] = element;

    this->positionToInsert++;
    this->elementsInserted++;

    if (isFull())
        resize();
}

template <typename E>
bool ArrayList<E>::add(size_t index, const E &element) {
    if (index < 0 || index >= size())
        return false;

    if (index == 0) {
        addFirst(element);
        return true;
    }

    if (index == size() - 1) {
        addLast(element);
        return true;
    }

    for (size_t i{this->positionToInsert}; i > index; i--) {
        this->array[i] = this->array[i - 1];
    }

    this->array[index] = element;

    this->positionToInsert++;
    this->elementsInserted++;

    if (isFull())
        resize();

    return true;
}

template <typename E> 
E &ArrayList<E>::get(size_t index) {
    if (index < 0 || index >= size())
        throw "IndexOutOfBoundsException.";

    return this->array[index];
}

template <typename E>
E &ArrayList<E>::operator[](size_t index) {
    return get(index);
}

template <typename E>
ssize_t ArrayList<E>::indexOf(const E &element) const {
    const ssize_t ELEMENT_NOT_FOUND{-1};

    if (isEmpty())
        return ELEMENT_NOT_FOUND;

    ssize_t index{ELEMENT_NOT_FOUND};
    bool hasFoundElement{false};

    while (index < size() - 1 && !hasFoundElement) {
        index++;
        hasFoundElement = this->array[index] == element;
    }

    return (hasFoundElement) ? index : ELEMENT_NOT_FOUND;
}

template <typename E>
ssize_t ArrayList<E>::lastIndexOf(const E &element) const {
    const ssize_t ELEMENT_NOT_FOUND{-1};
    
    if (isEmpty())
        return ELEMENT_NOT_FOUND;

    ssize_t lastMatchIndex{ELEMENT_NOT_FOUND};

    for (size_t i{}; i < size(); i++) {
        if (this->array[i] == element) {
            lastMatchIndex = i;
        }
    }

    return lastMatchIndex;
}

template <typename E>
E ArrayList<E>::remove(size_t index) {
    if (index < 0 || index >= size())
        throw "IndexOutOfBoundsException.";

    E elementErased = get(index);

    E *newArray = new E[this->capacity]{};

    size_t j{};
    for (size_t i{}; i < size(); i++) {
        if (i != index) {
            newArray[j] = this->array[i];
            j++;
        }
    }

    delete[] this->array;
    this->array = newArray;
    newArray = nullptr;

    this->elementsInserted--;
    this->positionToInsert--;

    return elementErased;
}

template <typename E>
bool ArrayList<E>::removeFirstOcurrence(const E &element) {
    if (isEmpty())
        return false;

    const ssize_t ELEMENT_NOT_FOUND{-1};
    ssize_t indexMatch = indexOf(element);

    if (indexMatch == ELEMENT_NOT_FOUND)
        return false;

    remove(indexMatch);
    return true;
}

template <typename E>
bool ArrayList<E>::removeLastOcurrence(const E &element) {
    if (isEmpty())
        return false;

    const ssize_t ELEMENT_NOT_FOUND{-1};
    ssize_t indexMatch = lastIndexOf(element);

    if (indexMatch == ELEMENT_NOT_FOUND)
        return false;

    remove(indexMatch);
    return true;
}

template <typename E>
E ArrayList<E>::set(size_t index, const E &element) {
    if (index < 0 || index >= size())
        throw "IndexOutOfBoundsException.";

    E elementErased = get(index);

    this->array[index] = element;

    return elementErased;
}

template <typename E>
ArrayList<E>::~ArrayList() {
    clear();
}

#endif