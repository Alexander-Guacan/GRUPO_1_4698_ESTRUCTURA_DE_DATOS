#include "Input.h"
#include "CastToInt.h"
#include "CastToFloat.h"
#include <cstdio>
#include <cstring>
#include <iostream>

int main() {

    Input *input = new Input();

    char* resultado = input->ingresarDatoReal("Ingrese un dato cualquiera: ");
    
    CastToInt *casteador = new CastToInt();
    
    CastToFloat *casteador2 = new CastToFloat();

    std::cout << "\nResultado: " << casteador->casting(resultado);
    std::cout << "\nResultado2: " << casteador2->casting(resultado);

    return 0;
}