#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>
#include <conio.h>
#include <windows.h>

class Input {
    private:
        // Establece el color con el que se imprimira el resto de texto en consola
        void setTextColor(short colorId);

    public:
        enum textColors {
            BLACK,
            BLUE,
            GREEN,
            CYAN,
            RED,
            MAGENTA,
            BROWN,
            GREY,
            DEEP_GREY,
            DEEP_BLUE,
            DEEP_GREEN,
            DEEP_CYAN,
            DEEP_RED,
            DEEP_MAGENTA,
            YELLOW,
            WHITE
        };
        
        // Ingresar numeros enteros positivos, cantidad de caracteres es el numero maximo de digitos
        int unsignedIntegerNumber(const char *instructionMessage, short charactersAmount);
        // Ingresar numeros enteros positivos y negativos, cantidad de caracteres es el numero maximo de digitos (el caracter '-'  sera tomado como un digito mas)
        int integerNumber(const char *instructionMessage, short charactersAmount);
        // Ingresar numeros reales positivos, cantidad de caracteres es el numero maximo de digitos (el caracter '.' sera tomado como un digito mas)
        double unsignedRealNumber(const char *instructionMessage, short charactersAmount);
        // Ingresar numeros reales positivos y negativos, cantidad de caracteres es el numero maximo de digitos (los caracteres '.' y '-' seran tomados como un digito mas)
        double realNumber(const char *instructionMessage, short charactersAmount);
        // Ingresar letras a-z y A-Z, cantidad de caracteres es el numero maximo de letras a ingresar
        char *alphabetic(const char *instructionMessage, short charactersAmount);
        // Ingresar numeros enteros positivos, cantidad de caracteres es el numero maximo de digitos
        int unsignedIntegerNumber(const char *instructionMessage, short charactersAmount, short colorText);
        // Ingresar numeros enteros positivos y negativos, cantidad de caracteres es el numero maximo de digitos (el caracter '-'  sera tomado como un digito mas)
        int integerNumber(const char *instructionMessage, short charactersAmount, short colorText);
        // Ingresar numeros reales positivos, cantidad de caracteres es el numero maximo de digitos (el caracter '.' sera tomado como un digito mas)
        double unsignedRealNumber(const char *instructionMessage, short charactersAmount, short colorText);
        // Ingresar numeros reales positivos y negativos, cantidad de caracteres es el numero maximo de digitos (los caracteres '.' y '-' seran tomados como un digito mas)
        double realNumber(const char *instructionMessage, short charactersAmount, short colorText);
        // Ingresar letras a-z y A-Z, cantidad de caracteres es el numero maximo de letras a ingresar
        char *alphabetic(const char *instructionMessage, short charactersAmount, short colorText);
};

#endif