#ifndef MENU_HASH_INT_HPP
#define MENU_HASH_INT_HPP

#include "..\HashOpen\HashInt.hpp"

class MenuHashInt {
    private:
        static HashInt hashTable;

        static bool switchOption(char option);
        static void insertValue();
        static void deleteValue();
        static void searchValue();
        static void printHash();

    public:
        static void start();
};

#endif