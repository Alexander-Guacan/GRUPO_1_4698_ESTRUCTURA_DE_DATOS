/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Crear una clase con un unico metodo que permita ingresar un string y lo castee a cualquiera elegido por el programador
 * Autores: Alexander David Guacán Rivera y Alison Paola Moncayo Achilchisa
 * Fecha de creacion: 11/05/2022
 * Fecha de ultima modificación: 11/05/2022
 * Grupo: 10
 * Github: https://github.com/Alexander-Guacan/GRUPO_10_4698_ESTRUCTURA_DE_DATOS.git
 */

#include "Casting.h"
#include <iostream>

int main() {

    Casting cast = Casting();

    int resultado = cast.transformarANumeroEntero("45");

    std::cout << "El valor es: " << resultado << std::endl;

    return 0;
}