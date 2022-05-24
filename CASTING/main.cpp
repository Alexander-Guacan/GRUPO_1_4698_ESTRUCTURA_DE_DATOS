#include "Menu.h"
#include "ValidadorAscii.h"
#include "Input.h"
#include "CastToInt.h"
#include "CastToFloat.h"
#include <iostream>
#include <cstdio>
#include <string.h>

int main() {
    Input *input = new Input();
    printf("\nTRANSFORMAR NUMEROS A ENTERO Y/O REAL\n");
    char* valorReal = input->ingresarDatoReal("Ingrese un numero real: ");
    char* valorEntero = input->ingresarDatoEntero("\nIngrese un numero entero: ");

    CastToInt *castToInt = new CastToInt();
    CastToFloat *castToFloat = new CastToFloat();

    printf("\n\nValores transformados a entero: %d, %d", castToInt->transform(valorReal), castToInt->transform(valorEntero));
    printf("\nValores transformados a real: %.4f, %.4f", castToFloat->transform(valorReal), castToFloat->transform(valorEntero));

    printf("\n\nTRANSFORMAR NUMERO A ENTERO, REAL O CHAR\n");

    Menu *menu = new Menu();

    menu->printMenu();
    
    return 0;
}