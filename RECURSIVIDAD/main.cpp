#include <iostream>
#include "TransformarDecimalBinario.h"
#include "Matematica.h"

int main() {

    Matematica matematica;
    TransformarDecimalBinario DecimalABinario;

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