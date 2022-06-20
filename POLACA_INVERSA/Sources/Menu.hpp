#ifndef MENU_HPP
#define MENU_HPP

class Menu {
    private:
        void printOptions();
        char selectOption();
        void printResults(char *infixExpression);

    public:
        void start();
};

#endif