#include "Input.h"
#include "CastToInt.h"
#include <cstdio>
#include <cstring>
#include <iostream>

int main() {

    Input *input = new Input();

    char* resultado = input->ingresarDatoReal("Ingrese un dato cualquiera: ");
    
    CastToInt *casteador = new CastToInt();

    std::cout << "\nResultado: " << casteador->casting(resultado);

    return 0;
}