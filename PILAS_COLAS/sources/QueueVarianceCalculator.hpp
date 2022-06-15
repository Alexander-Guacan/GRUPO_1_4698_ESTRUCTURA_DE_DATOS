/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Trabajar con colas y pilas, generar sus operaciones basicas y construir un metodo que permite obtener la varianza en cada tipo de estructura
 * Autor: Alexander David Guacán Rivera y Alison Paola Moncayo Achilchisa
 * Fecha de creacion: 13/06/2022
 * Fecha de ultima modificación: 14/06/2022
 * Grupo: 1
 * Github: https://github.com/Alexander-Guacan/GRUPO_1_4698_ESTRUCTURA_DE_DATOS.git
 */
#ifndef QUEUE_VARIANCE_CALCULATOR_HPP
#define QUEUE_VARIANCE_CALCULATOR_HPP

#include "Queue.hpp"

typedef int NUMBER;

class QueueVarianceCalculator {
    private:
        static int elementsQuantity(Queue<NUMBER> *&queue);
        static double average(Queue<NUMBER> *&queue);

    public:
        static double calculate(Queue<NUMBER> *&queue);
};

#endif