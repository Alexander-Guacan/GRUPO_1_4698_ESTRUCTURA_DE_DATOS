#ifndef CUADRADO_HPP
#define CUADRADO_HPP

#include "Figura.hpp"

class Cuadrado : public Figura {
    private:
        float lado{};

    public:
        Cuadrado(int ladoInicial);
        float area() override;
        float perimetro() override;
};

#endif