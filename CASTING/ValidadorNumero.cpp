#include "ValidadorNumero.h"
#include <cstring>
#include <iostream>

bool ValidadorNumero::esValido(char *input) {
    int i{};
    bool esNumero{true};
    int cantidadDePuntos{};
    while (i < std::strlen(input) && esNumero && cantidadDePuntos <= 1) {
        esNumero = input[i] >= '0' && input[i] <= '9' || input[i] == '.';
        
        if (input[i] == '.') {
            cantidadDePuntos++;
        }
        
        i++;
    }

    return esNumero && cantidadDePuntos <= 1;
}