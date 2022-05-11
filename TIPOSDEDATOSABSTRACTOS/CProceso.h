#ifndef CPROCESO_H
#define CPROCESO_H

class CProceso {
    int numerador;
    int denominador;

    public:
        CProceso(int numerador, int denominador);
        void setNumerador(int numerador);
        void setDenominador(int denominador);
        int getNumerador();
        int getDenominador();
};

#endif