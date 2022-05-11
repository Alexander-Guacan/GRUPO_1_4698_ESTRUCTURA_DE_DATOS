/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Resolver el siguiente problema usando metodos racionales a/b + c/d = ((a*d) + (c*b)) / b*d
 * Autores: Alexander David Guacán Rivera y Alison Paola Moncayo Achilchisa
 * Fecha de creacion: 11/05/2022
 * Fecha de ultima modificación: 11/05/2022
 * Grupo: 10
 * Github: https://github.com/Alexander-Guacan/GRUPO_10_4698_ESTRUCTURA_DE_DATOS.git
 */

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