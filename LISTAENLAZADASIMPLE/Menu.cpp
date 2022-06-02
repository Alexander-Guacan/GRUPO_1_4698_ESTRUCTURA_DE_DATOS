#include <iostream>
#include <conio.h>
#include "Menu.h"
#include "Input.h"
#include "ListInteger.h"

void Menu::start() {

    bool exit{false};
    bool hasFoundValue{false};
    Input *input = new Input();
    List *integerNumbers = new ListInteger();

    do {
        system("cls");

        printf("1. Insertar numero al inicio de la lista\n"
               "2. Insertar numero al final de la lista\n"
               "3. Imprimir numeros desde el inicio hasta el final\n"
               "4. Imprimir numeros desde el final hasta el inicio\n"
               "5. Buscar numero en la lista\n"
               "6. Eliminar primera ocurrencia desde el principio\n"
               "7. Eliminar primera ocurrencia desde el final\n"
               "8. Salir\n\n"
               "Presione una opcion [ ]\b\b");

        switch (getch()) {

            case '1':
                integerNumbers->insertTop(input->integerNumber("Ingrese un numero entero que ira al principio de la lista: ", 5));
                break;

            case '2':
                integerNumbers->insertBack(input->integerNumber("Ingrese un numero entero que ira al final de la lista: ", 5));
                break;

            case '3':
                integerNumbers->printFromStart();
                system("pause");
                break;

            case '4':
                integerNumbers->printFromEnd();
                system("pause");
                break;

            case '5':
                integerNumbers->search(input->integerNumber("Ingrese numero a buscar: ", 5));
                system("pause");
                break;

            case '6':
                hasFoundValue = integerNumbers->deleteFromHead(input->integerNumber("Ingrese numero a eliminar desde el inicio de la lista: ", 5));

                if (!hasFoundValue) {
                    printf("\nEl valor no se encuentra en la lista\n");
                    system("pause");
                }

                break;

            case '7':
                hasFoundValue = integerNumbers->deleteFromTail(input->integerNumber("Ingrese numero a eliminar desde el final de la lista: ", 5));

                if (!hasFoundValue) {
                    printf("\nEl valor no se encuentra en la lista\n");
                    system("pause");
                }

                break;

            case '8':
                exit = true;
                break;

            default:
                break;
        }

    } while (!exit);
}