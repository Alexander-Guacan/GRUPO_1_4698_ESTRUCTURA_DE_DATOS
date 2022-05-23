#include <iostream>

char* decimalABinario(char*, int);
int siguienteNumeroPrimo(int);
int minimoComunMultiplo(int, int, int, int);
int maximoComunDivisor(int, int, int, int);

int siguienteNumeroPrimo(int numeroPrimo) {
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

int minimoComunMultiplo(int valor1, int valor2, int valor3, int numeroPrimo) {

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

int maximoComunDivisor(int valor1, int valor2, int valor3, int numeroPrimo) {
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

char* decimalABinario(char* destino, int valor) {
    if (valor >= 1) {
        destino = decimalABinario(destino, valor / 2);

        *destino = (valor % 2) + '0';
        destino++;
    }

    return destino;
}

int main() {
    int valor1 = 96;
    int valor2 = 160;
    int valor3 = 24;

    int mcm = minimoComunMultiplo(valor1, valor2, valor3, 2);
    int mcd = maximoComunDivisor(valor1, valor2, valor3, 2);

    std::cout << "Resultado: " << mcd << '\n';

    return 0;
}