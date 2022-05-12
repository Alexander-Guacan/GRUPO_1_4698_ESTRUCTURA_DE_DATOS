#include "Input.h"
#include <cstdio>
#include <cstring>
#include <iostream>

int main() {

    Input *input = new Input();

    std::string resultado = input->ingresarDatoReal("Ingrese un dato cualquiera: ");
    
    std::cout << "\nResultado: " << resultado;

    return 0;
}