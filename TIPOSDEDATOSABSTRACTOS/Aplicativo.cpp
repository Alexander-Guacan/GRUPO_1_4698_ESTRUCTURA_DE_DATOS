#include "CProceso.h"

int main() {
    CProceso *obj1 = new CProceso(10, 3);
    CProceso *obj2 = new CProceso(7, 8);
    CProceso obj3 = CProceso(0, 0);

    obj3.racional(*obj1, *obj2);
    obj1->imprimir(*obj1);
    obj2->imprimir(*obj2);
    obj3.imprimir(obj3);

    return 0;
}