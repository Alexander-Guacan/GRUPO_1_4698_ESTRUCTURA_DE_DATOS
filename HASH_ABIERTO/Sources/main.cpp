#include "HashOpen\HashInt.hpp"
#include <iostream>

int main() {
    HashInt hashTable;

    hashTable.insert(4);
    hashTable.insert(2);
    hashTable.insert(8);
    hashTable.insert(37);
    hashTable.insert(9);
    hashTable.insert(9);
    hashTable.insert(9);

    hashTable.print();

    std::cout << "\nPosition: " << hashTable.search(66);
    std::cout << "\nPosition: " << hashTable.search(37);
    std::cout << "\nPosition: " << hashTable.search(2);

    return 0;
}