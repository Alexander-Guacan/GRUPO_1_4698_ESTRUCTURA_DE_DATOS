#ifndef LIST_INTEGER_H
#define LIST_INTEGER_H

#include "List.h"
#include "Node.h"

class ListInteger : public List {
    Node *firstNode{nullptr};

    public:
        int size();
        bool isEmpty();
        void insertBack(int value);
        void insertTop(int value);
        void printFromStart();
        void printFromEnd();
        void search(int value);
        bool deleteFromHead(int value);
        bool deleteFromTail(int value);
    
};

#endif