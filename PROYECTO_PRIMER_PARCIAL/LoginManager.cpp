#include "LoginManager.hpp"
#include "MenuLogin.hpp"
#include "MenuSystem.hpp"
#include "EmailGenerator.hpp"
#include <iostream>
#include <cstdlib>

void LoginManager::start() {
    MenuLogin menuLogin;
    MenuSystem menuSystem;
    CircularDoublyLinkedList<Person> *users = new CircularDoublyLinkedList<Person>(false);

    bool hasSelectedExit{false};

    while (!hasSelectedExit) {
        const int LOGIN = menuLogin.LOGIN;
        const int REGISTER = menuLogin.REGISTER;
        const int EXIT_LOGIN = menuLogin.EXIT;

        switch (menuLogin.start()) {
            
            case LOGIN:

                if (login(users)) {
                    hasSelectedExit = menuSystem.start() == menuSystem.EXIT;
                }

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

bool LoginManager::login(List<Person> *users) {
    system("cls");
    const short LEFT_SPACING = 40;
    const short UP_SPACING = 5;
    HandleConsole console;
    Input input;

    console.setConsoleCursorPosition({LEFT_SPACING, UP_SPACING});
    char *emailInput = input.email("Ingresa tu correo electronico: ", std::strlen("@empresa.com") + 3, std::strlen("@empresa.com") + 20);
    console.setConsoleCursorPosition({LEFT_SPACING, UP_SPACING + 1});
    char *passwordInput = input.alphanumeric("Ingresa tu clave: ", 5, 10);

    Person *personToSearch = new Person(emailInput, passwordInput);

    IteratorLinkedList<Person> *iterator = users->getIterator();

    bool hasFoundPerson = false;

    while (iterator->hasNext() && !hasFoundPerson) {
        Person *personInList = iterator->getData();

        bool hasEqualsEmail = std::strcmp(personToSearch->getEmail(), personInList->getEmail()) == 0;
        bool hasEqualsPassword = std::strcmp(personToSearch->getPassword(), personInList->getPassword()) == 0;

        hasFoundPerson = hasEqualsEmail && hasEqualsPassword;
    }

    if (!hasFoundPerson) {
        console.printTextWithColor("[ERROR: usuario no consta en el sistema, presione una tecla para continuar]", console.RED, {LEFT_SPACING, UP_SPACING + 2});
        getch();
    } else {
        console.printTextWithColor("[Datos correctos, presione una tecla para continuar]", console.BLUE, {LEFT_SPACING, UP_SPACING + 2});
        getch();
    }

    return hasFoundPerson;
}

bool LoginManager::registerOnSystem(List<Person> *users) {
    const short LEFT_SPACING = 40;
    const short UP_SPACING = 5;
    HandleConsole console;
    Person *personToInsert = new Person();

    while (!users->insertAtEnd(personToInsert)) {

        console.printTextWithColor("[ERROR: la persona ingresada ya existe, presiona una tecla para reintentar]", console.RED, {LEFT_SPACING, UP_SPACING + 4});
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

    console.printTextWithColor("Tu correo electronico es: ", console.BLUE, {LEFT_SPACING, UP_SPACING + 4});
    console.printTextWithColor(personToInsert->getEmail(), console.GREEN);
    console.printTextWithColor("---Presione una tecla para continuar---", console.BLUE, {LEFT_SPACING, UP_SPACING + 5});
    getch();

    return true;
}