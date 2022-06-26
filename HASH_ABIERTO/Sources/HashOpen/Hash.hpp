#ifndef HASH_HPP
#define HASH_HPP

#include "Node.hpp"

template <typename T>
class Hash {
    protected:
        constexpr short MAX_CAPACITY{29};
        Node<T> *array[MAX_CAPACITY]{};

    private:
        virtual short hashCode(const &T element) = 0;

    public:
        virtual void insert(const &T element) = 0;
        virtual int search(const &T element) = 0;
        virtual bool deleteElement(const &T element) = 0;
        virtual void print() = 0;
};

#endif