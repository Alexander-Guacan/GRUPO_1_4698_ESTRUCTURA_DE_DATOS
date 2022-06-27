#include "MenuHash.hpp"
#include <iostream>
#include <conio.h>

void MenuHash::printTitles() {
    system("clear");
    std::cout << "------MENU HASH------\n"
              << "1. Insertar\n"
              << "2. Eliminar\n"
              << "3. Buscar\n"
              << "4. Imprimir\n"
              << "5. Regresar\n"
              << "6. Salir\n";
}