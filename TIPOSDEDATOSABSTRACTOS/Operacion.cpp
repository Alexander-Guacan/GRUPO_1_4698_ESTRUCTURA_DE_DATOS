#include "Operacion.h"

CProceso Operacion::suma(CProceso obj1, CProceso obj2) {
    int a = obj1.getNumerador();
    int b = obj1.getDenominador();
    int c = obj2.getNumerador();
    int d = obj2.getDenominador();

    CProceso resultado = CProceso(0,0);
    resultado.setNumerador((a*d) + (c*b));
    resultado.setDenominador(b*d);
    return resultado;
}