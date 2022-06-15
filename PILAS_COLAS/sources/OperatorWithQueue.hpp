#ifndef OPERATOR_WITH_QUEUE_CPP
#define OPERATOR_WITH_QUEUE_CPP

#include "Queue.hpp"
#include <windows.h>

typedef int DATA_TYPE;

class OperatorWithQueue {
    private:
        static COORD subtitlePosition;
        static COORD textPosition;

        static void add(Queue<DATA_TYPE> *&queue);
        static void deleteElement(Queue<DATA_TYPE> *&queue);
        static void showWithoutDelete(Queue<DATA_TYPE> *&queue);
        static void showWithDelete(Queue<DATA_TYPE> *&queue);
        static void calculateVariance(Queue<int> *&queue);

    public:
        
        static bool start(Queue<DATA_TYPE> *&queue);
};

#endif