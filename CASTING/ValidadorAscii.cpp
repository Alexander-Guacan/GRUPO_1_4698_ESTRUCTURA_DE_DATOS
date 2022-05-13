#include "ValidadorAscii.h"
#include <cstring>

bool ValidadorAscii::esValido(char *input) {
    int i{};
    bool esNumero{true};

    while (i < std::strlen(input) && esNumero) {
        esNumero = input[i] >= '0' && input[i] <= '9';
        i++;
    }

    bool esCaracterImprimible{false};
    if (esNumero) esCaracterImprimible = std::atoi(input) >= 33 && std::atoi(input) <= 254 && std::atoi(input) != 127;

    return esNumero && esCaracterImprimible;
}