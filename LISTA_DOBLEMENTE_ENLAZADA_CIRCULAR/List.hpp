#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
    
    public:
        // Retorna verdadero si la lista esta vacia, caso contrario retorna falso
        virtual bool isEmpty() = 0;
        // Retorna el numero de elementos guardados en la lista
        virtual short size() = 0;
        // Inserta un dato al inicio de la lista
        virtual void insertAtBegin(T data) = 0;
        // Inserta un dato al final de la lista
        virtual void insertAtEnd(T data) = 0;
        // Inserta un dato en una posicion determinada de la lista, si se ha ingresado correctamente en la lista retornara true, si la lista esta vacia o la posicion indicada no existe retornara false
        virtual bool insertAt(T data, short positionToInsert) = 0;
        // Elimina el primer elemento de la lista, si la lista esta vacia retorna nullptr
        virtual const T* deleteAtBegin() = 0;
        // Elimina el ultimo elemento de la lista, si la lista esta vacia retorna nullptr
        virtual const T* deleteAtEnd() = 0;
        // Elimina el elemento en la posicion especificada la lista, si la lista esta vacia o no existe la posicion indicada retorna nullptr
        virtual const T* deleteAt(short positionToDelete) = 0;
        // Busca la primera coincidencia desde inicio a fin de la lista
        virtual void search(short positionToSearch) = 0;
        // Imprime la lista completa
        virtual void printAll() = 0;
        // Imprime un unico elemento en la poisicion indicada
        virtual void printOf(short positionToPrint) = 0;
};

#endif