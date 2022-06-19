#include "Mathematic.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include <cstring>
#include <string>
#include <string.h>
#include <iostream>

bool Mathematic::isOperator(char character) {
    return std::strchr("+ - * / ^", character) != nullptr;
}

bool Mathematic::isOperand(char character) {
    return std::isdigit(character);
}

int Mathematic::hierarchy(char operatorChar) {
    int level{};

    switch (operatorChar) {
        case '^':
            level = 3;
            break;

        case '*':
        case '/':
            level = 2;
            break;

        case '+':
        case '-':
            level = 1;
            break;
    }

    return level;
}

bool Mathematic::isParenthesisOpen(char character) {
    return character == '(';
}

bool Mathematic::isParenthesisClose(char character) {
    return character == ')';
}

char *Mathematic::toPrefix(char *infixExpression) {
    strrev(infixExpression);

    Stack<char> *expression = new Stack<char>();
    Stack<char> *operators = new Stack<char>();

    for (int i{}; i < std::strlen(infixExpression); i++) {
        if (isOperand(infixExpression[i])) {
            expression->push(new char{infixExpression[i]});

        } else if (isOperator(infixExpression[i])) {

            while (!operators->isEmpty() && hierarchy(infixExpression[i]) <= hierarchy(*(operators->top()))) {
                expression->push(new char{*(operators->pop())});
            }

            operators->push(new char{infixExpression[i]});

        } else if (isParenthesisClose(infixExpression[i])) {
            operators->push(new char{infixExpression[i]});

        } else if (isParenthesisOpen(infixExpression[i])) {
            while (*(operators->top()) != ')') {
                expression->push(new char{*(operators->pop())});
            }

            operators->pop();
        } else if (std::isalpha(infixExpression[i])) {
            expression->push(new char{infixExpression[i]});
        }
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

char *Mathematic::toSufix(char *infixExpression) {
    Queue<char> *expression = new Queue<char>();
    Stack<char> *operators = new Stack<char>();

    for (int i{}; i < std::strlen(infixExpression); i++) {
        if (isOperand(infixExpression[i])) {
            expression->add(new char{infixExpression[i]});
            
        } else if (isOperator(infixExpression[i])) {

            while (!operators->isEmpty() && hierarchy(infixExpression[i]) <= hierarchy(*(operators->top()))) {
                expression->add(new char{*(operators->pop())});
            }

            operators->push(new char{infixExpression[i]});

        } else if (isParenthesisOpen(infixExpression[i])) {
            operators->push(new char{infixExpression[i]});
            
        } else if (isParenthesisClose(infixExpression[i])) {
            while (*(operators->top()) != '(') {
                expression->add(new char{*(operators->pop())});
            }

            operators->pop();

        } else if (std::isalpha(infixExpression[i])) {
            expression->add(new char{infixExpression[i]});
        }
    }

    while (!operators->isEmpty()) {
        expression->add(new char{*(operators->pop())});
    }

    char *sufixExpression = new char[expression->size() + 1]{};
    char *iterator{sufixExpression};

    while (!expression->isEmpty()) {
        *iterator = *(expression->poll());
        iterator++;
    }

    return sufixExpression;
}