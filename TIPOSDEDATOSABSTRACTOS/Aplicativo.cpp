#include "CProceso.h"
#include "Impresion.h"
#include "Operacion.h"

int main() {
    Impresion impresionDeFracciones = Impresion();
    Operacion operadorDeFracciones = Operacion();
    
    CProceso *obj1 = new CProceso(10, 3);
    CProceso *obj2 = new CProceso(7, 8);
    CProceso obj3 = CProceso(0, 0);

    obj3 = operadorDeFracciones.suma(*obj1, *obj2);

    impresionDeFracciones.mostrarEnConsola(*obj1);
    impresionDeFracciones.mostrarEnConsola(*obj2);
    impresionDeFracciones.mostrarEnConsola(obj3);

    return 0;
}