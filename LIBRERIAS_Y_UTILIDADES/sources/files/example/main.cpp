#include <iostream>
#include "Cuadrado.hpp"
#include "Triangulo.hpp"

int main() {
    Figura *figuras[] = {
        new Cuadrado(5),
        new Triangulo(6, 8),
        new Triangulo(7, 9),
        new Cuadrado(9)
    };

    for (auto &figura : figuras) {
        std::cout << "Area = " << figura->area() << '\n';
    }

    return 0;
}