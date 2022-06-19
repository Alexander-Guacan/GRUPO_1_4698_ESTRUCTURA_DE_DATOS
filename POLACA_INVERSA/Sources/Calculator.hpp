#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "Stack.hpp"
#include <string>

class Calculator {
    private:

    public:
        Stack<std::string> *mathematicExpression = new Stack<std::string>();
        Stack<std::string> *reverseMathematicExpression();
        bool isBalancedExpression();
        char *toArrayChar();
        void inputExpression();
        void printMathematicExpression();
};

#endif