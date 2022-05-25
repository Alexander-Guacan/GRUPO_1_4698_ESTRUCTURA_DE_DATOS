/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Crear un programa que permita pasar de un numero decimal a numero binario usando punteros
 * Crear un programa que permita calcular el minimo comun multiplo y el maximo comun divisor de 3 terminos
 * sin crear nuevas variables dentro de las funciones
 * Autores: Alexander David Guacán Rivera y Alison Paola Moncayo Achilchisa
 * Fecha de creacion: 22/05/2022
 * Fecha de ultima modificación: 24/05/2022
 * Grupo: 1
 * Github: https://github.com/Alexander-Guacan/GRUPO_1_4698_ESTRUCTURA_DE_DATOS.git
 */

#include <iostream>
#include "TransformarDecimalABinario.h"
#include "Matematica.h"

int main() {

    Matematica matematica;
    TransformarDecimalABinario DecimalABinario;

    std :: cout << "TRANSFORMAR DE DECIMAL A BINARIO" << std :: endl;
    std::cout << "Ingrese un numero: " << std :: endl ;
    int valor = 0;
    std :: cin >> valor;
    char * Transformacion = new char [10]{};
    DecimalABinario.decimalABinario(Transformacion,valor);
    std :: cout << "Resultado: " << Transformacion << std::endl  <<std :: endl;

    std :: cout <<"MINIMO COMUN MULTIPLO Y MAXIMO COMUN DIVISOR" <<std :: endl;
    int valor1, valor2, valor3;
    std :: cout <<"Ingrese valor1 : " <<std ::endl;
    std :: cin >> valor1;
    std :: cout <<"Ingrese valor2 : " <<std ::endl;
    std :: cin >> valor2;
    std :: cout <<"Ingrese valor3 : " <<std ::endl;
    std :: cin >> valor3;

    int mcm = matematica.minimoComunMultiplo(valor1,valor2,valor3,2);
    int mcd = matematica.maximoComunDivisor(valor1,valor2,valor3,2);

    std :: cout << "Resultado Minimo Comun Multiplo: " << mcm << std :: endl << std :: endl;
    std :: cout << "Resultado Maximo Comun Divisor: " << mcd << std :: endl << std :: endl;

    return 0;
}