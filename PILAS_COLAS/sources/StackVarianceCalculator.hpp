/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Trabajar con colas y pilas, generar sus operaciones basicas y construir un metodo que permite obtener la varianza en cada tipo de estructura
 * Autor: Alexander David Guacán Rivera y Alison Paola Moncayo Achilchisa
 * Fecha de creacion: 13/06/2022
 * Fecha de ultima modificación: 14/06/2022
 * Grupo: 1
 * Github: https://github.com/Alexander-Guacan/GRUPO_1_4698_ESTRUCTURA_DE_DATOS.git
 */

#ifndef STACK_VARIANCE_CALCULATOR_HPP
#define STACK_VARIANCE_CALCULATOR_HPP

#include "Stack.hpp"

typedef int NUMBER;

class StackVarianceCalculator {
    private:
        static int elementsQuantity(Stack<NUMBER> *&stack);
        static double average(Stack<NUMBER> *&stack);

    public:
        static double calculate(Stack<NUMBER> *&stack);
};

#endif