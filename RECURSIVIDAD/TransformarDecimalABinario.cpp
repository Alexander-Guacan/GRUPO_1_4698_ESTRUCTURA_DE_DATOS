#include "TransformarDecimalABinario.h"
#include <cstdio>
#include <conio.h>

char *TransformarDecimalABinario ::decimalABinario(char* destino, int valor) {
    if (valor >= 1) {
        destino = decimalABinario(destino, valor / 2);

        *destino = (valor % 2) + '0';
        destino++;
    }

    return destino;
}