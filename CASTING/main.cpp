#include "Menu.h"
#include "ValidadorAscii.h"
#include "Input.h"
#include "CastToInt.h"
#include "CastToFloat.h"
#include <iostream>
#include <cstdio>
#include <string.h>

int main() {
    /* Input *input = new Input();
    char* valorReal = input->ingresarDatoReal("Ingrese un numero real: ");
    char* valorEntero = input->ingresarDatoEntero("\nIngrese un numero entero: ");

    CastToInt *castToInt = new CastToInt();
    CastToFloat *castToFloat = new CastToFloat();

    printf("\nValores transformado a entero: %d, %d", castToInt->transform(valorReal), castToInt->transform(valorEntero));
    printf("\nValores transformado a real: %.4f, %.4f", castToFloat->transform(valorReal), castToFloat->transform(valorEntero)); */
    Menu *menu = new Menu();

    menu->printMenu();
    
    return 0;
}