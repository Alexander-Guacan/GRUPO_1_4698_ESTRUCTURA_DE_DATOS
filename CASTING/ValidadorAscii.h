#ifndef VALIDADOR_ASCII_H
#define VALIDADOR_ASCII_H

#include "Validador.h"

class ValidadorAscii : public Validador {
    
    public:
        bool esValido(char *);
};

#endif