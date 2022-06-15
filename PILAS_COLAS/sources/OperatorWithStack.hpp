#ifndef OPERATOR_WITH_STACK_CPP
#define OPERATOR_WITH_STACK_CPP

#include "Stack.hpp"
#include <windows.h>

typedef int DATA_TYPE;

class OperatorWithStack {
    private:
        static COORD subtitlePosition;
        static COORD textPosition;

        static void add(Stack<DATA_TYPE> *&stack);
        static void deleteElement(Stack<DATA_TYPE> *&stack);
        static void showWithoutDelete(Stack<DATA_TYPE> *&stack);
        static void showWithDelete(Stack<DATA_TYPE> *&stack);
        static void calculateVariance(Stack<int> *&stack);

    public:
        
        static bool start(Stack<DATA_TYPE> *&stack);
};

#endif