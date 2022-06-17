#include "Mathematic.hpp"
#include "Stack.hpp"
#include <cstring>
#include <string>
#include <iostream>

bool Mathematic::isOperator(char value) {
    switch (value) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return true;
            break;
    }

    return false;
}

bool Mathematic::isOperand(char value) {
    return std::isdigit(value);
}

char *Mathematic::reverseExpression(const char *expression) {
    Stack<char> *reverse = new Stack<char>();

    for (int i{}; i < std::strlen(expression); i++) {
        reverse->push(new char{*(expression + i)});
    }

    char *result = new char[std::strlen(expression) + 1]{};
    
    for (int i = 0; i < std::strlen(expression); i++) {
        result[i] = *(reverse->pop());
    }

    return result;
}

char *Mathematic::toPrefix(const char *infixExpression) {
    char *reverseInfixExpresion = reverseExpression(infixExpression);

    Stack<char> *expression = new Stack<char>();
    Stack<char> *operators = new Stack<char>();

    for (int i{}; i < std::strlen(reverseInfixExpresion); i++) {
        if (isOperand(reverseInfixExpresion[i]))
            expression->push(new char{reverseInfixExpresion[i]});

        else if (isOperator(reverseInfixExpresion[i]))
            operators->push(new char{reverseInfixExpresion[i]});
    }

    while (!operators->isEmpty()) {
        expression->push(new char{*(operators->pop())});
    }

    char *prefixExpression = new char[expression->size() + 1]{};
    char *iterator{prefixExpression};

    while (!expression->isEmpty()) {
        *iterator = *(expression->pop());
        iterator++;
    }

    return prefixExpression;
}