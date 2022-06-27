#include "HashOpen\HashInt.hpp"

int main() {
    HashInt hashTable;

    hashTable.insert(4);
    hashTable.insert(2);
    hashTable.insert(9);
    hashTable.insert(9);
    hashTable.insert(9);
    hashTable.insert(9);
    hashTable.insert(9);

    hashTable.print();

    return 0;
}