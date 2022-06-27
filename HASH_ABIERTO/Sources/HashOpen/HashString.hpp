#ifndef HASH_STRING_HPP
#define HASH_STRING_HPP

#include "Hash.hpp"
#include <string>

class HashString : public Hash<std::string> {

    private:
        short hashCode(const std::string &element);
    public:
        bool isEmpty();
        void insert(const std::string &element);
        short search(const std::string &element);
        bool deleteElement(const std::string &element);
        void print();
};

#endif