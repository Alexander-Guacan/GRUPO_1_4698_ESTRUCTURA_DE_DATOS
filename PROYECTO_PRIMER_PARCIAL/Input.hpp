#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "IdVerificator.hpp"

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
        
        char *numbers(const char *instructionMessage, short minimumDigits, short maximumDigits);
        char *numbers(const char *instructionMessage, short minimumDigits, short maximumDigits, short textColor);
        int unsignedIntegerNumber(const char *instructionMessage, short minimumDigits, short maximumDigits);
        int unsignedIntegerNumber(const char *instructionMessage, short minimumDigits, short maximumDigits, short textColor);
        int integerNumber(const char *instructionMessage, short minimumDigits, short maximumDigits);
        int integerNumber(const char *instructionMessage, short minimumDigits, short maximumDigits, short textColor);
        double unsignedRealNumber(const char *instructionMessage, short minimumDigits, short maximumDigits);
        double unsignedRealNumber(const char *instructionMessage, short minimumDigits, short maximumDigits, short textColor);
        double realNumber(const char *instructionMessage, short minimumDigits, short maximumDigits);
        double realNumber(const char *instructionMessage, short minimumDigits, short maximumDigits, short textColor);
        char *oneWord(const char *instructionMessage, short minimumDigits, short maximumDigits);
        char *oneWord(const char *instructionMessage, short minimumDigits, short maximumDigits, short textColor);
        char *alphabetic(const char *instructionMessage, short minimumCharacters, short maximumCharacters);
        char *alphabetic(const char *instructionMessage, short minimumCharacters, short maximumCharacters, short textColor);
        char *identificationCard(const char *instructionMessage);
        char *identificationCard(const char *instructionMessage, short textColor);
        char *alphanumeric(const char *instructionMessage, short minimumCharacters, short maximumCharacters);
        char *alphanumeric(const char *instructionMessage, short minimumCharacters, short maximumCharacters, short textColor);
};

#endif