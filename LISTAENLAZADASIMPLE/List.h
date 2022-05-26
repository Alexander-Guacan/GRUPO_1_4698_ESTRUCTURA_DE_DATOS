#ifndef LIST_H
#define LIST_H

class List {
    
    public:
        virtual void insertBack(int value) = 0;
        virtual void insertTop(int value) = 0;
        virtual void printFromEnd() = 0;
        virtual void printFromStart() = 0;
        virtual void search(int value) = 0;
        virtual bool deleteFromHead(int value) = 0;
        virtual bool deleteFromTail(int value) = 0;
};

#endif