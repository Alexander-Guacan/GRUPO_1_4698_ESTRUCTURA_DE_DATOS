#include "Matematica.h"

int Matematica::siguienteNumeroPrimo(int numeroPrimoActual) {
    bool esNumeroPrimo = false;
    numeroPrimoActual++;

    while (!esNumeroPrimo) {
        int iterador{ 1 };
        int divisores{};
        while (divisores <= 2 && iterador <= numeroPrimoActual) {
            if (numeroPrimoActual % iterador == 0)
                divisores++;

            iterador++;
        }

        esNumeroPrimo = divisores == 2;

        if (!esNumeroPrimo)
            numeroPrimoActual++;
    }

    return numeroPrimoActual;
}

int Matematica::minimoComunMultiplo(int valor1, int valor2, int valor3) {

    if (valor1 == 1 && valor2 == 1 && valor3 == 1) {
        this->numeroPrimo = 2;
        return 1;
    }
    else if (valor1 % this->numeroPrimo == 0 || valor2 % this->numeroPrimo == 0 || valor3 % this->numeroPrimo == 0) {
        if (valor1 % this->numeroPrimo == 0) valor1 /= this->numeroPrimo;
        if (valor2 % this->numeroPrimo == 0) valor2 /= this->numeroPrimo;
        if (valor3 % this->numeroPrimo == 0) valor3 /= this->numeroPrimo;

        return this->numeroPrimo * minimoComunMultiplo(valor1, valor2, valor3);
    } else {
        this->numeroPrimo = siguienteNumeroPrimo(this->numeroPrimo);
        return minimoComunMultiplo(valor1, valor2, valor3);
    }
}

int Matematica::maximoComunDivisor(int valor1, int valor2, int valor3) {
    if (valor1 == 1 && valor2 == 1 && valor3 == 1) {
        this->numeroPrimo = 2;

        return 1;
    } else if (valor1 % this->numeroPrimo == 0 && valor2 % this->numeroPrimo == 0 && valor3 % this->numeroPrimo == 0) {
        valor1 /= this->numeroPrimo;
        valor2 /= this->numeroPrimo;
        valor3 /= this->numeroPrimo;

        return this->numeroPrimo * maximoComunDivisor(valor1, valor2, valor3);
    } else if (valor1 % this->numeroPrimo == 0 || valor2 % this->numeroPrimo == 0 || valor3 % this->numeroPrimo == 0) {
        if (valor1 % this->numeroPrimo == 0) valor1 /= this->numeroPrimo;
        if (valor2 % this->numeroPrimo == 0) valor2 /= this->numeroPrimo;
        if (valor3 % this->numeroPrimo == 0) valor3 /= this->numeroPrimo;

        return maximoComunDivisor(valor1, valor2, valor3);
    } else {

        this->numeroPrimo = siguienteNumeroPrimo(this->numeroPrimo);

        return maximoComunDivisor(valor1, valor2, valor3);
    }
}