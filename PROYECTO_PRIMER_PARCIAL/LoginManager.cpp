#include "LoginManager.hpp"
#include "MenuLogin.hpp"
#include "MenuOfBuy.hpp"
#include "EmailGenerator.hpp"
#include <iostream>
#include <cstdlib>

void LoginManager::start() {
    MenuLogin menuLogin;
    MenuOfBuy menuOfBuy;
    CircularDoublyLinkedList<Person> *users = new CircularDoublyLinkedList<Person>(false);

    bool hasSelectedExit{false};

    while (!hasSelectedExit) {
        const int LOGIN = menuLogin.LOGIN;
        const int REGISTER = menuLogin.REGISTER;
        const int EXIT_LOGIN = menuLogin.EXIT;

        switch (menuLogin.start()) {
            
            case LOGIN:
                std::cout << "\nPresiono opcion login\n";
                system("pause");
                break;

            case REGISTER:
                registerOnSystem(users);
                break;

            case EXIT_LOGIN:
                hasSelectedExit = true;
                break;
        }
    }
}

bool LoginManager::registerOnSystem(List<Person> *users) {
    int seconds = 5;
    int waitTime = seconds * 1000;

    Person *personToInsert = new Person();

    while (!users->insertAtEnd(personToInsert)) {
        std::cout << "\n\tCargando espere...";
        Sleep(waitTime);

        std::cout << "\n[ERROR: la persona ingresada ya existe, presiona una tecla para reintentar]";
        getch();

        personToInsert->setData();
    }

    EmailGenerator emailGenerator("@empresa.com");

    emailGenerator.generate(personToInsert, [&]() -> short {
        IteratorLinkedList<Person> *iterator = users->getIterator();
        short repeats{};
        while (iterator->hasNext()) {
            Person *personInList = iterator->getData();
            bool equalsFirstLetterName = *(personToInsert->getFirstName()) == *(personInList->getFirstName());
            bool equalsLastName = std::strcmp(personToInsert->getLastName(), personInList->getLastName()) == 0;

            if (equalsFirstLetterName && equalsLastName)
                repeats++;
        }

        return repeats - 1;
    }());

    std::cout << "\n\tCargando espere...";
    Sleep(waitTime);
    
    std::cout << "\nTu correo electronico es: " << personToInsert->getEmail();

    std::cout << "\n---Presione una tecla para continuar---\n";
    getch();

    return true;
}