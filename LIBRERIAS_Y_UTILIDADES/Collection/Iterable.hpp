#ifndef ITERABLE_HPP
#define ITERABLE_HPP

#include "Iterator.hpp"

template <typename T>
class Iterable {
    protected:
        Node<T> *head{nullptr};
        Node<T> *tail{nullptr};

    public:
        // Returns an iterator over a set of elements of type T
        virtual Iterator<T> iterator() = 0;
        // Returns an iterator over a set of elements of type T in reverse sequential order
        virtual Iterator<T> descendingIterator() = 0;
};

#endif