#ifndef MENU_INITIAL_SYSTEM_HPP
#define MENU_INITIAL_SYSTEM_HPP

#include "MenuInitialGUI.hpp"
#include "OperatorWithStack.hpp"
#include "OperatorWithQueue.hpp"

typedef int DATA_TYPE;

class MenuInitialSystem {
    private:
    
        static bool operationsWithStack(Stack<DATA_TYPE> *&stack);
        static bool operationsWithQueue(Queue<DATA_TYPE> *&queue);

    public:
        static void start();
};

#endif