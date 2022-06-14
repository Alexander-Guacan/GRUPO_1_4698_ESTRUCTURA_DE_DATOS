/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Trabajar con colas y pilas, generar sus operaciones basicas y construir un metodo que permite obtener la varianza en cada tipo de estructura
 * Autor: Alexander David Guacán Rivera y Alison Paola Moncayo Achilchisa
 * Fecha de creacion: 13/06/2022
 * Fecha de ultima modificación: 14/06/2022
 * Grupo: 1
 * Github: https://github.com/Alexander-Guacan/GRUPO_1_4698_ESTRUCTURA_DE_DATOS.git
 */

#include <iostream>
#include "Queue.hpp"
#include "Stack.hpp"

void rellenarQueue(Queue<int> *queue);
void recorrerListaEliminandoSusElementos(Queue<int> *queue);
void recorrerListaSinEliminarSusElementos(Queue<int> *queue);

int main() {
    Queue<int> *queue = new Queue<int>();

    rellenarQueue(queue);

    recorrerListaEliminandoSusElementos(queue);

    rellenarQueue(queue);

    recorrerListaSinEliminarSusElementos(queue);

    return 0;
}

void rellenarQueue(Queue<int> *queue) {

    queue->add(new int{45});
    queue->add(new int{78});
    queue->add(new int{34});
    queue->add(new int{9});
    queue->add(new int{23});
}

void recorrerListaEliminandoSusElementos(Queue<int> *queue) {
    std::cout << "\nSize inicial: " << queue->size() << '\n';

    while (!queue->isEmpty()) {
        std::cout << "Valor: " << *(queue->poll()) << '\n';
    }

    std::cout << "Size final: " << queue->size() << '\n';
}

void recorrerListaSinEliminarSusElementos(Queue<int> *queue) {
    std::cout << "\nSize inicial: " << queue->size() << '\n';

    Iterator<int> *iterator = queue->getIterator();

    while (iterator->hasNext()) {
        std::cout << "Valor: " << *(iterator->next()) << '\n';
    }

    std::cout << "Size final: " << queue->size() << '\n';
}