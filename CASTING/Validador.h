#ifndef VALIDATE_H
#define VALIDATE_H

#include <string>

class Validador {
    
    public:
        virtual bool esValido(char*) = 0;
};

#endif