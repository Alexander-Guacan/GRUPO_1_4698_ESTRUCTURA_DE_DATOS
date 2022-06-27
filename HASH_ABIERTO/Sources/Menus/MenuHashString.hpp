#ifndef MENU_HASH_STRING_HPP
#define MENU_HASH_STRING_HPP

#include "..\HashOpen\HashString.hpp"

class MenuHashString {
    private:
        static HashString hashTable;

        static bool switchOption(char option);
        static void insertValue();
        static void deleteValue();
        static void searchValue();
        static void printHash();

    public:
        static void start();
};

#endif