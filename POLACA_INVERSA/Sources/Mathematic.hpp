#ifndef MATHEMATIC_HPP
#define MATHEMATIC_HPP

class Mathematic {
    private:
        static bool isOperand(char operand);
        static bool isOperator(char value);
        static char *reverseExpression(const char *expresion);

    public:
        static char *toPrefix(const char *infixExpression);
};

#endif