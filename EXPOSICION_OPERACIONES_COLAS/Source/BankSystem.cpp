#include "BankSystem.hpp"
#include "BankGUI.hpp"
#include "HandleConsole.hpp"
#include "Person.hpp"
#include "Input.hpp"
#include <conio.h>

Queue<Person> *BankSystem::usersToAtend = new Queue<Person>();

void BankSystem::addClientToQueue() {
    HandleConsole::clearScreen();

    HandleConsole console;

    console.setCursorPosition({30, 4});
    std::cout << "Bienvenido a nuestro banco porfavor llene el siguiente formulario";

    Person *personToInsert = new Person();

    console.setCursorPosition({30, 5});
    personToInsert->setFirstName(Input::oneWord("Ingresa tu nombre: ", 3, 15));

    console.setCursorPosition({30, 6});
    personToInsert->setLastName(Input::oneWord("Ingresa tu apellido: ", 3, 15));

    console.setCursorPosition({30, 7});
    personToInsert->setIdCard(Input::identificationCard("Ingresa tu numero de cedula: "));

    console.setCursorPosition({30, 8});
    personToInsert->setMoneyOfBank(Input::unsignedRealNumber("Ingresa tu saldo actual en el banco: ", 1, 5));

    usersToAtend->add(personToInsert);
}

void BankSystem::atendClient() {
    HandleConsole::clearScreen();

    HandleConsole console;

    console.setCursorPosition({30, 4});
    std::cout << "Persona atendida:";

    Person *personToAtend = BankSystem::usersToAtend->poll();

    console.setCursorPosition({30, 5});
    std::cout << "Nombre completo: " << personToAtend->getFirstName() << " " << personToAtend->getLastName();

    console.setCursorPosition({30, 6});
    std::cout << "Cedula: " << personToAtend->getIdCard();

    console.setCursorPosition({30, 7});
    std::cout << "Saldo: " << personToAtend->getMoneyOfBank();

    personToAtend->substract(
        [&]() -> double {
            double substract{};

            do {
                console.setCursorPosition({30, 8});
                substract = Input::unsignedRealNumber("Ingresa la cantidad de dinero a retirar: ", 1, 5);

                if (substract > personToAtend->getMoneyOfBank()) {
                    console.setCursorPosition({30, 8});
                    int sizeOfString = printf("[CANTIDAD MAYOR A LA DISPONIBLE]              ");
                    getch();
                }

            } while (substract > personToAtend->getMoneyOfBank());

            return substract;
        }()
    );

    console.setCursorPosition({30, 10});
    std::cout << "Su saldo ahora es de: " << personToAtend->getMoneyOfBank();

    getch();
}

void BankSystem::showQueue() {
    HandleConsole::clearScreen();
    HandleConsole console;

    console.setCursorPosition({45, 3});
    std::cout << "Ventanilla";

    console.setCursorPosition({45, 4});
    std::cout << "     |";

    Iterator<Person> *iterator = BankSystem::usersToAtend->getIterator();

    short positionY{5};
    while (iterator->hasNext()) {
        Person *person = iterator->next();

        console.setCursorPosition({45, positionY++});
        std::cout << "[" << person->getIdCard() << "]";

        console.setCursorPosition({45, positionY++});
        std::cout << "     |";
    }

    getch();
}

void BankSystem::showNextPersonToAtend() {
    HandleConsole::clearScreen();

    HandleConsole console;

    console.setCursorPosition({30, 4});
    std::cout << "Siguiente persona para ser atendida:";

    Person *personToAtend = BankSystem::usersToAtend->peek();

    console.setCursorPosition({30, 5});
    std::cout << "Nombre completo: " << personToAtend->getFirstName() << " " << personToAtend->getLastName();

    console.setCursorPosition({30, 6});
    std::cout << "Cedula: " << personToAtend->getIdCard();

    console.setCursorPosition({30, 7});
    std::cout << "Saldo: " << personToAtend->getMoneyOfBank();

    getch();
}

bool BankSystem::selectOption() {
    BankGUI menu;
    bool exit{false};

    switch (menu.printScreen()) {
        case static_cast<int>(BankGUI::Options::ADD):
            addClientToQueue();
            break;

        case static_cast<int>(BankGUI::Options::ATEND):

            if (!BankSystem::usersToAtend->isEmpty()) {
                atendClient();
            } else {
                HandleConsole::clearScreen();
                HandleConsole console;
                console.setCursorPosition({35, 7});
                std::cout << "No hay mas clientes por atender";
                getch();
            }

            break;

        case static_cast<int>(BankGUI::Options::SHOW_ALL):
            showQueue();
            break;

        case static_cast<int>(BankGUI::Options::SHOW_NEXT):
            if (!BankSystem::usersToAtend->isEmpty()) {
                showNextPersonToAtend();
            } else {
                HandleConsole::clearScreen();
                HandleConsole console;
                console.setCursorPosition({35, 7});
                std::cout << "No hay mas clientes por atender";
                getch();
            }

            break;

        case static_cast<int>(BankGUI::Options::EXIT):
            exit = true;
            break;
    }

    return exit;
}

void BankSystem::start() {
    bool exit{false};

    int option{4};
    while (!exit) {
        exit = selectOption();
    }
}