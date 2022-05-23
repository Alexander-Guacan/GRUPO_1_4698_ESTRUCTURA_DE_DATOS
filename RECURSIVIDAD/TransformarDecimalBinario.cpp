#include "TransformarDecimalBinario.h"
#include <cstdio>
#include <conio.h>

char *TransformarDecimalBinario(char* destino, int valor) {
    if (valor >= 1) {
        destino = TransformarDecimalBinario(destino, valor / 2);

        *destino = (valor % 2) + '0';
        destino++;
    }

    return destino;
}