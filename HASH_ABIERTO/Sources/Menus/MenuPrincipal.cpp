#include "MenuPrincipal.hpp"
#include "MenuHashInt.hpp"
#include "MenuHashString.hpp"
#include <iostream>
#include <conio.h>

void MenuPrincipal::start() {
    bool exit;
    do {
        printTitles();
        exit = switchOption(getch());
    } while (!exit);
}

void MenuPrincipal::printTitles() {
    system("clear");
    std::cout << "------PRINCIPAL MENU------\n"
              << "1. Int\n"
              << "2. String\n"
              << "3. exit\n";
}

bool MenuPrincipal::switchOption(char option) {
    switch (option) {
        case '1':
            MenuHashInt::start();
            break;
        case '2':
            MenuHashString::start();
            break;
        case '3':
            return true;
            break;
    }

    return false;
}