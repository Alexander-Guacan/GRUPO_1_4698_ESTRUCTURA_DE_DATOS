/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Trabajar con colas y pilas, generar sus operaciones basicas y construir un metodo que permite obtener la varianza en cada tipo de estructura
 * Autor: Alexander David Guacán Rivera y Alison Paola Moncayo Achilchisa
 * Fecha de creacion: 13/06/2022
 * Fecha de ultima modificación: 14/06/2022
 * Grupo: 1
 * Github: https://github.com/Alexander-Guacan/GRUPO_1_4698_ESTRUCTURA_DE_DATOS.git
 */

#ifndef DATA_STRUCTURE_HPP
#define DATA_STRUCTURE_HPP

#include "Iterator.hpp"

template <typename T>
class DataStructure {
    protected:
        SimpleNode<T> *head{nullptr};

    public:
        // Verifica si la lista esta vacia
        bool isEmpty();
        // Retorna el numero de elementos existentes en la lista
        int size();
        // Retorna un objeto Iterator
        Iterator<T> *getIterator();
};

template <typename T>
bool DataStructure<T>::isEmpty() {
    return this->head == nullptr;
}

template <typename T>
int DataStructure<T>::size() {
    int sizeOfDataStructure{};
    SimpleNode<T> *iterator{head};

    while (iterator != nullptr) {
        iterator = iterator->getNextNode();
        sizeOfDataStructure++;
    }

    return sizeOfDataStructure;
}

template <typename T>
Iterator<T> *DataStructure<T>::getIterator() {
    return new Iterator<T>(this->head);
}

#endif