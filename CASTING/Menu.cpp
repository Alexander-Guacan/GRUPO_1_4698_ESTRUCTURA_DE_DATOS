#include "Menu.h"
#include "ValidadorNumero.h"
#include "ValidadorAscii.h"
#include "CastToInt.h"
#include "CastToFloat.h"
#include "CastToChar.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>

char* Menu::inputData() {
    char *input = new char[10];
    std::cout << "Ingrese un dato: ";
    std::cin >> input;

    return input;
}

void Menu::printMenu() {
    char *input = inputData();
    bool hasPressCorrectKey{false};

    system("cls");

    std::cout << "Elija al tipo de dato a convertir:" << std::endl
            << "1) Entero" << std::endl
            << "2) Real" << std::endl
            << "3) Caracter" << std::endl
            << "Presione una opcion" << std::endl;

    Validador *validadorNumero = new ValidadorNumero();
    Validador *validadorAscii = new ValidadorAscii();
    CastToInt *castToInt = new CastToInt();
    CastToFloat *castToFloat = new CastToFloat();
    CastToChar *castToChar = new CastToChar();

    do {

        switch(getch()) {
            case '1':

                if (validadorNumero->esValido(input)) {
                    std::cout << "\nValor transformado a entero: " << castToInt->transform(input);
                } else {
                    std::cout << "\nNo se puede convertir a entero";
                }

                hasPressCorrectKey = true;

                break;

            case '2':
                if (validadorNumero->esValido(input)) {
                    printf("\nValor transformado a real: %.4f", castToFloat->transform(input));
                } else {
                    std::cout << "\nNo se puede convertir a real";
                }

                hasPressCorrectKey = true;

                break;

            case '3':
                if (validadorAscii->esValido(input)) {
                    std::cout << "Caracter ascii imprimible: " << castToChar->transform(input);
                } else {
                    std::cout << "No se puede transformar a caracter ascii imprimible";
                }

                hasPressCorrectKey = true;
                break;
        }
        
    } while (!hasPressCorrectKey);

    
}