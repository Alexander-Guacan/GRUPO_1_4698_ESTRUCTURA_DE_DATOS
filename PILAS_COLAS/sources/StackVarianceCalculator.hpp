#ifndef STACK_VARIANCE_CALCULATOR_HPP
#define STACK_VARIANCE_CALCULATOR_HPP

#include "Stack.hpp"

typedef int NUMBER;

class StackVarianceCalculator {
    private:
        static int elementsQuantity(Stack<NUMBER> *&stack);
        static double average(Stack<NUMBER> *&stack);

    public:
        static double calculate(Stack<NUMBER> *&stack);
};

#endif