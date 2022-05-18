#ifndef COMPLEJO_H
#define COMPLEJO_H

class Complejo {
    float parteReal;
    float parteImaginaria;

    public:
        Complejo(float, float);
        float getParteReal();
        float getParteImaginaria();
        Complejo operator+(Complejo);
        Complejo operator-(Complejo);
};

#endif