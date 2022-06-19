#include "Calculator.hpp"
#include "Queue.hpp"
#include <cstring>
#include <conio.h>
#include <iostream>

char *Calculator::toArrayChar() {
    Queue<char> *infixExpression = new Queue<char>();

    Stack<std::string> *reverseExpression = reverseMathematicExpression();
    while (!reverseExpression->isEmpty()) {
        std::string expression = *(reverseExpression->pop());
        for (int i{}; i < expression.size(); i++) {
            infixExpression->add(new char{expression[i]});
        }
    }

    char *result = new char[infixExpression->size() + 1]{};
    char *iterator{result};

    while (!infixExpression->isEmpty()) {
        *iterator = *(infixExpression->poll());
        iterator++;
    }

    return result;
}

bool Calculator::isBalancedExpression() {
    Stack<char> parenthesis;
    Iterator<std::string> *iterator = reverseMathematicExpression()->getIterator();

    while (iterator->hasNext()) {
        std::string expression = *(iterator->next());

        for (int i{}; i < expression.size(); i++) {
            char parenthesisOpen{'('};
            char parenthesisClose{')'};

            if (expression[i] == parenthesisOpen) {
                parenthesis.push(new char{parenthesisOpen});

            } else if (expression[i] == parenthesisClose && !parenthesis.isEmpty() && *(parenthesis.top()) == parenthesisOpen) {
                parenthesis.pop();
            } else if (expression[i] == parenthesisClose && parenthesis.isEmpty()){
                return false;
            }
        }
    }

    return parenthesis.isEmpty();
}

Stack<std::string> *Calculator::reverseMathematicExpression() {
    Stack<std::string> *reverseExpression = new Stack<std::string>();

    Iterator<std::string> *iterator = this->mathematicExpression->getIterator();

    while (iterator->hasNext()) {
        reverseExpression->push(new std::string(*(iterator->next())));
    }

    return reverseExpression;
}

void Calculator::inputExpression() {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};
    const char SQRT_KEY{'r'};
    const char SIN_KEY{'s'};
    const char COS_KEY{'c'};
    const char TAN_KEY{'t'};
    const char PARENTHESIS_OPEN{'('};
    const char PARENTHESIS_CLOSE{')'};
    char keyPressed{};
    bool specialFunctionAllowed{true};
    bool positiveSignAllowed{true};
    bool negativeSignAllowed{true};
    bool multiplicationSignAllowed{true};
    bool divisionSignAllowed{true};
    bool elevationSignAllowed{true};
    bool parenthesisOpenAllowed{true};
    bool parenthesisCloseAllowed{true};
    bool numbersAllowed{true};

    while ((keyPressed = getch()) != ENTER_KEY || this->mathematicExpression->isEmpty() || !isBalancedExpression()) {

        if (std::isdigit(keyPressed) && numbersAllowed) {
            this->mathematicExpression->push(new std::string(std::to_string(keyPressed - '0')));
            
            specialFunctionAllowed = false;
            positiveSignAllowed = true;
            negativeSignAllowed = true;
            multiplicationSignAllowed = true;
            divisionSignAllowed = true;
            elevationSignAllowed = true;
            parenthesisOpenAllowed = false;
            parenthesisCloseAllowed = true;
            numbersAllowed = true;
        }

        switch (keyPressed) {

            case SQRT_KEY:
                if (specialFunctionAllowed) {
                    this->mathematicExpression->push(new std::string("sqrt("));
                    
                    positiveSignAllowed = false;
                    negativeSignAllowed = true;
                    multiplicationSignAllowed = false;
                    divisionSignAllowed = false;
                    elevationSignAllowed = false;
                    parenthesisOpenAllowed = false;
                    parenthesisCloseAllowed = false;
                    numbersAllowed = true;
                }
                break;

            case SIN_KEY:
                if (specialFunctionAllowed) {
                    this->mathematicExpression->push(new std::string("sin("));
                    
                    positiveSignAllowed = false;
                    negativeSignAllowed = true;
                    multiplicationSignAllowed = false;
                    divisionSignAllowed = false;
                    elevationSignAllowed = false;
                    parenthesisOpenAllowed = false;
                    parenthesisCloseAllowed = false;
                    numbersAllowed = true;
                }
                break;

            case COS_KEY:
                if (specialFunctionAllowed) {
                    this->mathematicExpression->push(new std::string("cos("));
                    
                    positiveSignAllowed = false;
                    negativeSignAllowed = true;
                    multiplicationSignAllowed = false;
                    divisionSignAllowed = false;
                    elevationSignAllowed = false;
                    parenthesisOpenAllowed = false;
                    parenthesisCloseAllowed = false;
                    numbersAllowed = true;
                }
                break;

            case TAN_KEY:
                if (specialFunctionAllowed) {
                    this->mathematicExpression->push(new std::string("tan("));

                    positiveSignAllowed = false;
                    negativeSignAllowed = true;
                    multiplicationSignAllowed = false;
                    divisionSignAllowed = false;
                    elevationSignAllowed = false;
                    parenthesisOpenAllowed = false;
                    parenthesisCloseAllowed = false;
                    numbersAllowed = true;
                }
                break;

            case PARENTHESIS_OPEN:
                if (parenthesisOpenAllowed) {
                    this->mathematicExpression->push(new std::string("("));

                    specialFunctionAllowed = true;
                    positiveSignAllowed = false;
                    negativeSignAllowed = true;
                    multiplicationSignAllowed = false;
                    divisionSignAllowed = false;
                    elevationSignAllowed = false;
                    parenthesisCloseAllowed = false;
                    numbersAllowed = true;
                }


                break;

            case PARENTHESIS_CLOSE:
                if (parenthesisCloseAllowed) {
                    this->mathematicExpression->push(new std::string(")"));
                
                    specialFunctionAllowed = false;
                    positiveSignAllowed = true;
                    negativeSignAllowed = true;
                    multiplicationSignAllowed = true;
                    divisionSignAllowed = true;
                    elevationSignAllowed = true;
                    parenthesisOpenAllowed = false;
                    numbersAllowed = false;
                }
                break;

            case '+':
                if (positiveSignAllowed) {
                    this->mathematicExpression->push(new std::string("+"));
                    
                    specialFunctionAllowed = true;
                    positiveSignAllowed = false;
                    negativeSignAllowed = false;
                    multiplicationSignAllowed = false;
                    divisionSignAllowed = false;
                    elevationSignAllowed = false;
                    parenthesisOpenAllowed = true;
                    parenthesisCloseAllowed = false;
                    numbersAllowed = true;
                }
                break;

            case '-':
                if (negativeSignAllowed) {
                    this->mathematicExpression->push(new std::string("-"));
                    
                    specialFunctionAllowed = true;
                    positiveSignAllowed = false;
                    negativeSignAllowed = false;
                    multiplicationSignAllowed = false;
                    divisionSignAllowed = false;
                    elevationSignAllowed = false;
                    parenthesisOpenAllowed = true;
                    parenthesisCloseAllowed = false;
                    numbersAllowed = true;
                }
                break;

            case '*':
                if (multiplicationSignAllowed) {
                    this->mathematicExpression->push(new std::string("*"));
                    
                    specialFunctionAllowed = true;
                    positiveSignAllowed = false;
                    negativeSignAllowed = false;
                    multiplicationSignAllowed = false;
                    divisionSignAllowed = false;
                    elevationSignAllowed = false;
                    parenthesisOpenAllowed = true;
                    parenthesisCloseAllowed = false;
                    numbersAllowed = true;
                }
                break;

            case '/':
                if (divisionSignAllowed) {
                    this->mathematicExpression->push(new std::string("/"));
                    
                    specialFunctionAllowed = true;
                    positiveSignAllowed = false;
                    negativeSignAllowed = false;
                    multiplicationSignAllowed = false;
                    divisionSignAllowed = false;
                    elevationSignAllowed = false;
                    parenthesisOpenAllowed = true;
                    parenthesisCloseAllowed = false;
                    numbersAllowed = true;
                }
                break;

            case '^':
                if (elevationSignAllowed) {
                    this->mathematicExpression->push(new std::string("^"));
                    
                    specialFunctionAllowed = true;
                    positiveSignAllowed = false;
                    negativeSignAllowed = false;
                    multiplicationSignAllowed = false;
                    divisionSignAllowed = false;
                    elevationSignAllowed = false;
                    parenthesisOpenAllowed = true;
                    parenthesisCloseAllowed = false;
                    numbersAllowed = true;
                }
                break;

            case BACKSPACE_KEY:
                if (!this->mathematicExpression->isEmpty()) {
                    mathematicExpression->pop();
                }
        }

        printMathematicExpression();

    }
}

void Calculator::printMathematicExpression() {
    system("cls");
    std::cout << toArrayChar() << '\n'
              << "\nFuncion seno ('s')\n"
              << "Funcion coseno ('c')\n"
              << "Funcion tangente  ('t')\n"
              << "Funcion raiz ('r')\n";
}