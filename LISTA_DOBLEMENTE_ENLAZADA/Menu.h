#ifndef MENU_H
#define MENU_H

#include "DoublyLinkedList.h"
#include "Input.h"

class Menu {
    private:
        int printOptions();
        template <typename T> void insertAtBegin(List<T> *list);
        template <typename T> void insertAtEnd(List<T> *list);
        template <typename T> void insertAt(List<T> *list);
        template <typename T> void printList(List<T> *list);
        template <typename T> void searchFromBegin(List<T> *list);
        template <typename T> void searchFromEnd(List<T> *list);
        template <typename T> void deleteFirst(List<T> *list);
        template <typename T> void deleteLast(List<T> *list);
        template <typename T> void deleteAt(List<T> *list);

    public:
        void start();
};

void Menu::start() {
    typedef int T;
    bool exit{false};
    List<T> *list = new DoublyLinkedList<T>();

    do {
        system("clear");

        switch (printOptions()) {
            case 1:
                insertAtBegin<T>(list);
                break;

            case 2:
                insertAtEnd<T>(list);
                break;

            case 3:
                insertAt<T>(list);
                system("pause");
                break;

            case 4:
                printList<T>(list);
                system("pause");
                break;

            case 5:
                searchFromBegin(list);
                system("pause");
                break;

            case 6:
                searchFromEnd(list);
                system("pause");
                break;

            case 7:
                deleteFirst(list);
                system("pause");
                break;

            case 8:
                deleteLast(list);
                system("pause");
                break;

            case 9:
                deleteAt(list);
                system("pause");
                break;

            case 10:
                exit = true;
                break;
            
            default:
                
                break;
        }
    } while (!exit);
}

int Menu::printOptions() {

    Input input;

    printf("1. Insertar elemento al inicio de la lista\n"
           "2. Insertar elemento al final de la lista\n"
           "3. Insertar elemento en una determinada posicion\n"
           "4. Imprimir lista \n"
           "5. Buscar desde el principio\n"
           "6. Buscar desde el final\n"
           "7. Eliminar primer elemento\n"
           "8. Eliminar ultimo elemento\n"
           "9. Eliminar elemento en una determinada posicion\n"
           "10. Salir\n\n");

    return input.integerNumber("Ingrese una opcion: ", 2);
}

template <typename T>
void Menu::insertAtBegin(List<T> *list) {
    Input input;

    list->insertAtBegin(input.integerNumber("Ingrese el valor del elemento para la lista: ", 5));
}

template <typename T>
void Menu::insertAtEnd(List<T> *list) {
    Input input;

    list->insertAtEnd(input.integerNumber("Ingrese el valor del elemento para la lista: ", 5));
}

template <typename T>
void Menu::insertAt(List<T> *list) {
    Input input;

    list->insertAt(input.integerNumber("Ingrese el valor del elemento para la lista: ", 5),
    input.integerNumber("Ingrese la posicion de la lista donde desea insertar el elemento: ", 3));
}

template <typename T>
void Menu::searchFromBegin(List<T> *list) {
    Input input;

    list->searchFromBegin(input.integerNumber("Ingrese el valor del elemento a buscar en la lista desde el principio: ", 5));
}

template <typename T>
void Menu::searchFromEnd(List<T> *list) {
    Input input;

    list->searchFromEnd(input.integerNumber("Ingrese el valor del elemento a buscar en la lista desde el final: ", 5));
}

template <typename T>
void Menu::deleteFirst(List<T> *list) {

    if (list->deleteAtBegin()) {
        printf("\nSe ha eliminado el primer elemento de la lista exitosamente\n");
    }
}

template <typename T>
void Menu::deleteLast(List<T> *list) {

    if (list->deleteAtEnd()) {
        printf("\nSe ha eliminado el ultimo elemento de la lista exitosamente\n");
    }
}

template <typename T>
void Menu::deleteAt(List<T> *list) {
    Input input;

    if (list->deleteAt(input.integerNumber("Ingrese la posicion de la lista donde desea eliminar el elemento: ", 3))) {
        printf("\nSe ha eliminado el elemento en la posicion elegida de la lista exitosamente\n");
    }
}

template <typename T>
void Menu::printList(List<T> *list) {
    list->print();
}

#endif