#ifndef CUADRO_H
#define CUADRO_H

#include <iostream>
#include <windows.h>

class Cuadro {

    public:
        void dibujar(int);
        void *operator new(std::size_t, short x, short y);
};

#endif