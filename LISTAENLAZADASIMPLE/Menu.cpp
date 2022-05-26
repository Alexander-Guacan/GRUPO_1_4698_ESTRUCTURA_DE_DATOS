#include <iostream>
#include <conio.h>
#include "Menu.h"
#include "Input.h"
#include "ListInteger.h"

void Menu::start(){

    bool exit{false};
    Input *input = new Input();
    ListInteger *listaEnteros = new ListInteger();

    do{
        system ("cls");
        printf("1. Ingresar elementos por Cabeza \n"  
               "2. Ingresar elementos por Cola \n"
               "3. Imprimir elementos desde el inicio \n"
               "4. Imprimir elementos desde el final \n"
               "5. Buscar elemento de la lista \n"
               "6. Eliminar 1era ocurrencia por Cabeza \n"
               "7. Eliminar 1era ocurrencia por Cola \n"
               "8. SALIR \n\n"

               "Presione una opcion:  ");

        switch (getch())
        {
        case '1':
            listaEnteros->insertTop(input->integerNumber("Ingrese un numero ENTERO al principio de la lista: "));
            break;
        
        case '2':
            listaEnteros->insertBack(input->integerNumber("Ingrese un numero ENTERO el final de la lista: "));
            break;
        
        case '3':
            listaEnteros->printFromStart();
            system ("pause");
            break;
        
        case '4':
            listaEnteros->printFromEnd();
            system ("pause");
            break;
        
        case '5':
            listaEnteros->search(input->integerNumber("Ingrese numero a buscar:  "));
            system ("pause");
            break;
        
        case '6':
            listaEnteros->deleteFromHead(input->integerNumber("Ingrese numero a eliminar del inicio de la lista: "));
            break;
        
        case '7':
            listaEnteros->deleteFromTail(input->integerNumber("Ingrese numero a elimnar del final de la lista:  "));
            break;

        case '8':
            exit = true;
            break;
        
        default:
            break;
        }
        
    }while (!exit);

}