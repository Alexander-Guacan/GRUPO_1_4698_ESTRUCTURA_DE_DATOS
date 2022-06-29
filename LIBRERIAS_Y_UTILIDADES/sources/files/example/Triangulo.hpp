#include "Figura.hpp"

class Triangulo : public Figura {
    private:
        float base{};
        float altura{};

    public:
        Triangulo(float baseInicial, float alturaInicial);
        float area() override;
        float perimetro() override;
};