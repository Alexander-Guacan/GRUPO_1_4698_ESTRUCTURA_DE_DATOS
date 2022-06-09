#ifndef LIST_HPP
#define LIST_HPP

#include "IteratorLinkedList.hpp"

template <typename T>
class List {
    public:
        virtual bool isEmpty() = 0;
        virtual short size() = 0;
        virtual bool insertAtBegin(T *data) = 0;
        virtual bool insertAtEnd(T *data) = 0;
        virtual bool insertAt(T *data, short positionToInsert) = 0;
        virtual bool deleteAtBegin() = 0;
        virtual bool deleteAtEnd() = 0;
        virtual bool deleteAt(short positionToDelete) = 0;
        virtual void print() = 0;
        virtual void print(short positionToPrint) = 0;
        virtual IteratorLinkedList<T> *getIterator() = 0;
};

#endif