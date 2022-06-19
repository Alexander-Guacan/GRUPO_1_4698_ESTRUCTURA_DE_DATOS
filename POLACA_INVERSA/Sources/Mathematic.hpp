#ifndef MATHEMATIC_HPP
#define MATHEMATIC_HPP

class Mathematic {
    private:
        static bool isOperand(char character);
        static bool isOperator(char character);
        static int hierarchy(char operatorChar);
        static bool isParenthesisOpen(char character);
        static bool isParenthesisClose(char character);

    public:
        static char *toPrefix(char *infixExpression);
        static char *toSufix(char *infixExpression);
};

#endif