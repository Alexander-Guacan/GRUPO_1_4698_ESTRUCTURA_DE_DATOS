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

    hashTable.deleteElement(8);

    std::cout << std::endl;
    hashTable.print();
    return 0;
}