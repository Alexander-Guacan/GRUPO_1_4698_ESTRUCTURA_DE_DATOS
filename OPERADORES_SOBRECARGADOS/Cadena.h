#ifndef CADENA_H
#define CADENA_H

class Cadena {
    char mensaje[40];

    public:
        Cadena(char *);
        char *dameCadena();
        void operator+(Cadena);
};

#endif