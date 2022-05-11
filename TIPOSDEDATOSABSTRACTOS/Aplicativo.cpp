#include "CProceso.h"
#include "Impresion.h"

int main() {
    CProceso *obj1 = new CProceso(10, 3);
    CProceso *obj2 = new CProceso(7, 8);
    CProceso obj3 = CProceso(0, 0);
    Impresion obj4 = Impresion ();

    obj3.racional(*obj1, *obj2);
    obj4.mostrarEnConsola(*obj1);
    obj4.mostrarEnConsola(*obj2);
    obj4.mostrarEnConsola(obj3);

    return 0;
}