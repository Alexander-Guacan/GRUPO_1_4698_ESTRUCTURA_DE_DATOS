#ifndef LIST_HPP
#define LIST_HPP

#include "Collection.hpp"

template <typename E>
class List : public Collection<E> {

    public:
        // Inserts the specified element at the beginning of this list
        virtual void addFirst(const E &element) = 0;
        // Appends the specified element to the end of the list
        virtual void addLast(const E &element) = 0;
        // Inserts the specified element at the specified position in this list.
        virtual bool add(size_t index, const E &element) = 0;
        // Returns the element at the specifid position in this list.
        virtual E &get(size_t index) = 0;
        // Returns the index of the first ocurrence of the specified element in this list, or -1 if this list does not contain the element
        virtual ssize_t indexOf(const E &element) const = 0;
        // Returns the index of the last ocurrence of the specified element in this list, or -1 if this list does not contain the element
        virtual ssize_t lastIndexOf(const E &element) const = 0;
        // Removes the element at the specified position in this list and returns it. Throws: IndexOutOfBoundsException
        virtual E remove(size_t index) = 0;
        // Removes the first ocurrence of the specified element from this list, if it is present
        virtual bool removeFirstOcurrence(const E &element) = 0;
        // Removes the last ocurrence of the specified element from this list, if it is present
        virtual bool removeLastOcurrence(const E &element) = 0;
        // Replace the element at the specified position in this list with the specified element, and returns the element removed. Throws: IndexOutOfBoundsException
        virtual E set(size_t index, const E &element) = 0;
};

#endif