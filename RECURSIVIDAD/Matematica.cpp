#include "Matematica.h"

int Matematica::siguienteNumeroPrimo(int numeroPrimo) {
    bool esNumeroPrimo = false;
    numeroPrimo++;

    while (!esNumeroPrimo) {
        int iterador{ 1 };
        int divisores{};
        while (divisores <= 2 && iterador <= numeroPrimo) {
            if (numeroPrimo % iterador == 0)
                divisores++;

            iterador++;
        }

        esNumeroPrimo = divisores == 2;

        if (!esNumeroPrimo)
            numeroPrimo++;
    }

    return numeroPrimo;
}

int Matematica::minimoComunMultiplo(int valor1, int valor2, int valor3, int numeroPrimo) {

    if (valor1 == 1 && valor2 == 1 && valor3 == 1) {
        return 1;
    }
    else if (valor1 % numeroPrimo == 0 || valor2 % numeroPrimo == 0 || valor3 % numeroPrimo == 0) {
        if (valor1 % numeroPrimo == 0) valor1 /= numeroPrimo;
        if (valor2 % numeroPrimo == 0) valor2 /= numeroPrimo;
        if (valor3 % numeroPrimo == 0) valor3 /= numeroPrimo;

        return numeroPrimo * minimoComunMultiplo(valor1, valor2, valor3, numeroPrimo);
    } else {
        return minimoComunMultiplo(valor1, valor2, valor3, siguienteNumeroPrimo(numeroPrimo));
    }
}

int Matematica::maximoComunDivisor(int valor1, int valor2, int valor3, int numeroPrimo) {
    if (valor1 == 1 && valor2 == 1 && valor3 == 1) {
        return 1;
    } else if (valor1 % numeroPrimo == 0 && valor2 % numeroPrimo == 0 && valor3 % numeroPrimo == 0) {
        valor1 /= numeroPrimo;
        valor2 /= numeroPrimo;
        valor3 /= numeroPrimo;

        return numeroPrimo * maximoComunDivisor(valor1, valor2, valor3, numeroPrimo);
    } else if (valor1 % numeroPrimo == 0 || valor2 % numeroPrimo == 0 || valor3 % numeroPrimo == 0) {
        if (valor1 % numeroPrimo == 0) valor1 /= numeroPrimo;
        if (valor2 % numeroPrimo == 0) valor2 /= numeroPrimo;
        if (valor3 % numeroPrimo == 0) valor3 /= numeroPrimo;

        return maximoComunDivisor(valor1, valor2, valor3, numeroPrimo);
    } else {
        return maximoComunDivisor(valor1, valor2, valor3, siguienteNumeroPrimo(numeroPrimo));
    }
}