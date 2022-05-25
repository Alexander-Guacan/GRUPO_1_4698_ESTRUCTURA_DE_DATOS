#include "CProceso.h"
#include "Impresion.h"
#include <iostream>

void Impresion::mostrarEnConsola(CProceso obj) {
    std::cout << obj.getNumerador() << "/" << obj.getDenominador() << std::endl;
}