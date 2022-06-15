/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Crear un ejemplo que involucre el uso de la estructura de datos queue
 * Autor: Alexander David Guacán Rivera y Alison Paola Moncayo Achilchisa
 * Fecha de creacion: 14/06/2022
 * Fecha de ultima modificación: 15/06/2022
 * Grupo: 1
 * Github: https://github.com/Alexander-Guacan/GRUPO_1_4698_ESTRUCTURA_DE_DATOS.git
 */

#ifndef INPUT_HPP
#define INPUT_HPP

class Input {
    private:

    public:
        
        static char *numbers(const char *instructionMessage, short minimumDigits, short maximumDigits);        
        static int unsignedIntegerNumber(const char *instructionMessage, short minimumDigits, short maximumDigits);        
        static int integerNumber(const char *instructionMessage, short minimumDigits, short maximumDigits);        
        static double unsignedRealNumber(const char *instructionMessage, short minimumDigits, short maximumDigits);        
        static double realNumber(const char *instructionMessage, short minimumDigits, short maximumDigits);        
        static char *oneWord(const char *instructionMessage, short minimumDigits, short maximumDigits);        
        static char *alphabetic(const char *instructionMessage, short minimumCharacters, short maximumCharacters);
        static char *identificationCard(const char *instructionMessage);
};

#endif