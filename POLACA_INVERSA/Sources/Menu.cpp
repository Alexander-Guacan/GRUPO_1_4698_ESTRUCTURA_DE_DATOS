#include "Menu.hpp"
#include "Calculator.hpp"
#include "Mathematic.hpp"
#include <iostream>
#include <conio.h>

void Menu::printOptions() {
    system("clear");
    std::cout << "1.- Ingresar expresion matematica\n"
              << "2.- Salir\n"
              << "Ingrese una opcion ___";
}

void Menu::printResults(char *infixExpression) {
    system("clear");
    std::cout << "Expresion prefija: " << Mathematic::toPrefix(infixExpression) << '\n'
              << "Expresion postfija: " << Mathematic::toSufix(infixExpression) << '\n'
              << "Resultado: " << '\n';

    getch();
}

char Menu::selectOption() {
    Calculator calculator;
    char keyPressed{};
    char *infixExpression{};

    switch ((keyPressed = getch())) {
        case '1':
            infixExpression = calculator.inputExpression();
            printResults(infixExpression);
            break;
        case '2':
            break;
    }

    return keyPressed;
}

void Menu::start() {
    bool exit{false};
    
    while (!exit) {
        printOptions();
        exit = selectOption() == '2';
    }
}