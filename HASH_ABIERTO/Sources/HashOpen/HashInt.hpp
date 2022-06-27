#ifndef HASH_INT_HPP
#define HASH_INT_HPP

#include "Hash.hpp"

class HashInt : public Hash<int> {

    private:
        short hashCode(const int &element);
    public:
        void insert(const int &element);
        short search(const int &element);
        bool deleteElement(const int &element);
        void print();
};

#endif