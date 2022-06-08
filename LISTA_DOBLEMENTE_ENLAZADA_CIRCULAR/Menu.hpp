#ifndef MENU_HPP
#define MENU_HPP

#include "CircularDoublyLinkedList.hpp"
#include "Input.hpp"

class Menu {
    private:
        short printOptions();
        template <typename T> void insertAtBegin(List<T> *list);
        template <typename T> void insertAtEnd(List<T> *list);
        template <typename T> void insertAt(List<T> *list);
        template <typename T> void deleteAtBegin(List<T> *list);
        template <typename T> void deleteAtEnd(List<T> *list);
        template <typename T> void deleteAt(List<T> *list);
        template <typename T> void search(List<T> *list);
        template <typename T> void printAll(List<T> *list);
        template <typename T> void printOf(List<T> *list);

    public:
        void start();

};

void Menu::start() {
    typedef int T;

    CircularDoublyLinkedList<T> *list = new CircularDoublyLinkedList<T>();

    bool exit{false};

    do {
        system("cls");

        switch (printOptions()) {
            case 1:
                insertAtBegin<T>(list);
                break;

            case 2:
                insertAtEnd<T>(list);
                break;

            case 3:
                insertAt<T>(list);
                break;

            case 4:
                deleteAtBegin<T>(list);
                break;

            case 5:
                deleteAtEnd<T>(list);
                break;

            case 6:
                deleteAt<T>(list);
                break;

            case 7:
                search<T>(list);
                break;

            case 8:
                printAll<T>(list);
                break;

            case 9:
                printOf<T>(list);
                break;

            case 10:
                exit = true;
                break;
        }

    } while (!exit);

    std::cout << "\nFin del programa\n";
}

short Menu::printOptions() {
    printf(
        "\tMENU\n"
        "1.- Insertar al principio\n"
        "2.- Insertar al final\n"
        "3.- Insertar en\n"
        "4.- Eliminar primer elemento\n"
        "5.- Eliminar ultimo elemento\n"
        "6.- Eliminar en\n"
        "7.- Buscar en\n"
        "8.- Imprimir lista completa\n"
        "9.- Imprimir en\n"
        "10.- Salir\n"
    );

    Input input;
    return input.unsignedIntegerNumber("\nINGRESA UNA OPCION: ", 2, input.GREEN);
}

template <typename T>
void Menu::insertAtBegin(List<T> *list) {
    Input input;
    list->insertAtBegin(input.integerNumber("\nIngresa un valor: ", 5));
}

template <typename T>
void Menu::insertAtEnd(List<T> *list) {
    Input input;
    list->insertAtEnd(input.integerNumber("\nIngresa un valor: ", 5));
}

template <typename T>
void Menu::insertAt(List<T> *list) {
    Input input;

    short positionToInsert = input.unsignedRealNumber("\nIngresa posicion a insertar: ", 3);

    if (!list->isEmpty() && (positionToInsert > 0 && positionToInsert <= list->size())) {
        list->insertAt(input.integerNumber("\nIngresa el valor a ingresar: ", 5), positionToInsert);
    } else {
        std::cout << "\nERROR: lista vacia o posicion fuera de rango\n";
        system("pause");
    }
}

template <typename T>
void Menu::deleteAtBegin(List<T> *list) {
    if (list->deleteAtBegin() != nullptr)
        std::cout << "\nPrimer elemento eliminado correctamente\n";
    else
        std::cout << "\nPrimer elemento no pudo ser eliminado\n";

    system("pause");
}

template <typename T>
void Menu::deleteAtEnd(List<T> *list) {
    if (list->deleteAtEnd() != nullptr)
        std::cout << "\nUltimo elemento eliminado correctamente\n";
    else
        std::cout << "\nUltimo elemento no pudo ser eliminado\n";
    
    system("pause");
}

template <typename T>
void Menu::deleteAt(List<T> *list) {
    Input input;

    if (list->deleteAt(input.unsignedIntegerNumber("\nIngresa posicion a eliminar: ", 3)) != nullptr) {
        std::cout << "\nElemento eliminado exitosamente\n";
    } else {
        std::cout << "\nElemento no pudo ser eliminado\n";
    }

    system("pause");
}

template <typename T>
void Menu::search(List<T> *list) {
    Input input;

    if (!list->isEmpty())
        list->search(input.unsignedIntegerNumber("\nIngresa posicion del elemento a buscar: ", 3));
    else
        std::cout << "\nLista vacia\n";

    system("pause");
}

template <typename T>
void Menu::printAll(List<T> *list) {
    list->printAll();

    system("pause");
}

template <typename T>
void Menu::printOf(List<T> *list) {
    Input input;

    list->printOf(input.unsignedIntegerNumber("\nIngresa la posicion a imprimir: ", 3));

    system("pause");
}

#endif