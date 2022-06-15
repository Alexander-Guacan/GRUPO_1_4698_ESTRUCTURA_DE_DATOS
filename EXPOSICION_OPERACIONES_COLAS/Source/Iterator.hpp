/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Crear un ejemplo que involucre el uso de la estructura de datos queue
 * Autor: Alexander David Guacán Rivera y Alison Paola Moncayo Achilchisa
 * Fecha de creacion: 14/06/2022
 * Fecha de ultima modificación: 15/06/2022
 * Grupo: 1
 * Github: https://github.com/Alexander-Guacan/GRUPO_1_4698_ESTRUCTURA_DE_DATOS.git
 */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "SimpleNode.hpp"

template <typename T>
class Iterator {
    private:
        SimpleNode<T> *node;

    public:
        // Inicializamos con el primer nodo de la lista para recorrerla sin afectar su orden
        Iterator(SimpleNode<T> *beginOfList);
        // Devuelve true si existen mas elementos en la lista, caso contrario retorna false
        bool hasNext();
        // Devuelve el siguiente elemento de la lista, si la lista esta vacia o ya no quedan mas elementos retornara un nullptr
        T *next();
};

template <typename T>
Iterator<T>::Iterator(SimpleNode<T> *beginOfList) {
    this->node = beginOfList;
}

template <typename T>
bool Iterator<T>::hasNext() {
    return this->node != nullptr;
}

template <typename T>
T *Iterator<T>::next() {
    T *data = node->getData();

    node = node->getNextNode();

    return data;
}

#endif