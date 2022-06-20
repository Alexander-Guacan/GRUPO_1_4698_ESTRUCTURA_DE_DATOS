#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "Stack.hpp"
#include <string>

class Calculator {
    private:
        Stack<std::string> *mathematicExpression = new Stack<std::string>();
        Stack<std::string> *reverseMathematicExpression();
        bool isBalancedExpression();
        char *toArrayChar();
        void printMathematicExpression();

    public:
        char *inputExpression();
};

#endif