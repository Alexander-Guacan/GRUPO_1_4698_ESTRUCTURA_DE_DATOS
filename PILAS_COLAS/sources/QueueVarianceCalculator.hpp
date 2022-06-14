#ifndef QUEUE_VARIANCE_CALCULATOR_HPP
#define QUEUE_VARIANCE_CALCULATOR_HPP

#include "Queue.hpp"

typedef int NUMBER;

class QueueVarianceCalculator {
    private:
        static int elementsQuantity(Queue<NUMBER> *&queue);
        static double average(Queue<NUMBER> *&queue);

    public:
        static double calculate(Queue<NUMBER> *&queue);
};

#endif