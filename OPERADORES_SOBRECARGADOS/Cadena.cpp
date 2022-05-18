#include "Cadena.h"
#include <cstring>

Cadena::Cadena(char *mensaje) {
    std::strcpy(this->mensaje, mensaje);
}

char *Cadena::dameCadena() {
    return this->mensaje;
}

void Cadena::operator+(Cadena nuevaCadena) {
    std::strcat(this->mensaje, nuevaCadena.dameCadena());
}