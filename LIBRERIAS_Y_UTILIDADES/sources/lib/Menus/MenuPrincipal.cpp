#include "MenuPrincipal.hpp"
#include "MenuStack.hpp"
#include "MenuQueue.hpp"
#include "MenuLinkedList.hpp"
#include "MenuArrayList.hpp"
#include <iostream>
#include <conio.h>

void MenuPrincipal::start() {
    bool exit;
    do {
        printMenuPrincipalTitles();
        exit = switchOption(getch());
    } while (!exit);
}

void MenuPrincipal::printMenuPrincipalTitles() {
    system("clear");
    std::cout << "-----PRINCIPAL MENU------\n"
              << "1. Stack menu\n"
              << "2. Queue menu\n"
              << "3. LinkedList menu\n"
              << "4. ArrayList menu\n"
              << "5. exit\n";
}

bool MenuPrincipal::switchOption(char option) {
    switch (option) {
        case '1':
            MenuStack::start();
            break;
        case '2':
            MenuQueue::start();
            break;
        case '3':
            MenuLinkedList::start();
            break;
        case '4':
            MenuArrayList::start();
            break;
        case '5':
            return true;
            break;
    }

    return false;
}