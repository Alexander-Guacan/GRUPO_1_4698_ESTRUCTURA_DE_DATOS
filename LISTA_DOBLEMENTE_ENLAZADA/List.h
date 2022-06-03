#ifndef LIST_H
#define LIST_H

#include "Node.h"

template <typename T>
class List {

    public:
        virtual bool isEmpty() = 0;
        virtual int size() = 0;
        virtual void insertAtBegin(T data) = 0;
        virtual void insertAtEnd(T data) = 0;
        virtual void insertAt(T data, int position) = 0;
        virtual bool searchFromBegin(T data) = 0;
        virtual bool searchFromEnd(T data) = 0;
        virtual bool deleteAtBegin() = 0;
        virtual bool deleteAtEnd() = 0;
        virtual bool deleteAt(int position) = 0;
        virtual void print() = 0;
        virtual Node<T> *first() = 0;
        virtual Node<T> *last() = 0;
};

#endif