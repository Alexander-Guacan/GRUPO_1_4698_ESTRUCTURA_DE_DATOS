#include "Mathematic.hpp"
#include <iostream>

int main() {

    char infixExpresion[] = {"5*4+3"};

    std::cout << "Resultado: " << Mathematic::toPrefix("5*4+3");

    return 0;
}