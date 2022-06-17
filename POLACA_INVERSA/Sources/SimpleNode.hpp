/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Trabajar con colas y pilas, generar sus operaciones basicas y construir un metodo que permite obtener la varianza en cada tipo de estructura
 * Autor: Alexander David Guacán Rivera y Alison Paola Moncayo Achilchisa
 * Fecha de creacion: 13/06/2022
 * Fecha de ultima modificación: 14/06/2022
 * Grupo: 1
 * Github: https://github.com/Alexander-Guacan/GRUPO_1_4698_ESTRUCTURA_DE_DATOS.git
 */

#ifndef SIMPLE_NODE_HPP
#define SIMPLE_NODE_HPP

template <typename T>
class SimpleNode {
    private:
        T *data{nullptr};
        SimpleNode<T> *nextNode{nullptr};

    public:
        SimpleNode(T *initialData);
        T *getData();
        SimpleNode<T> *getNextNode();
        void setData(T *newNode);
        void setNextNode(SimpleNode<T> *newNextNode);
        ~SimpleNode();
};

template <typename T>
SimpleNode<T>::SimpleNode(T *initialData) {
    this->data = initialData;
}

template <typename T>
T *SimpleNode<T>::getData() {
    return this->data;
}

template <typename T>
SimpleNode<T> *SimpleNode<T>::getNextNode() {
    return this->nextNode;
}

template <typename T>
void SimpleNode<T>::setData(T *newData) {
    this->data = newData;
}

template <typename T>
void SimpleNode<T>::setNextNode(SimpleNode<T> *newNextNode) {
    this->nextNode = newNextNode;
}

template <typename T>
SimpleNode<T>::~SimpleNode() {
    this->data = nullptr;
    this->nextNode = nullptr;
}

#endif