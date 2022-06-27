#ifndef HASH_HPP
#define HASH_HPP

#include "Node.hpp"

template <typename T>
class Hash {
    protected:
        static constexpr short MAX_CAPACITY{29};
        Node<T> *array[MAX_CAPACITY]{};
        short elements{};

    private:
        virtual short hashCode(const T &element) = 0;

    public:
        short size() {
            return this->elements;
        }

        bool isEmpty() {
            return size() <= 0;
        }

        virtual void insert(const T &element) = 0;
        virtual short search(const T &element) = 0;
        virtual bool deleteElement(const T &element) = 0;
        virtual void print() = 0;
};

#endif