#include "Person.hpp"
#include "HandleConsole.hpp"

Person::Person() {
    setData();
}

Person::Person(char *initialIdCard) {
    this->idCard = initialIdCard;
}

const char *Person::getFirstName() {
    return this->firstName;
}

const char *Person::getLastName() {
    return this->lastName;
}

const char *Person::getEmail() {
    return this->email;
}

void Person::setEmail(char *newEmail) {
    this->email = newEmail;
}

void Person::setPassword(char *newPassword) {
    this->password = newPassword;
}

void Person::setData() {
    system("cls");
    const short LEFT_SPACING = 40;
    const short UP_SPACING = 5;

    HandleConsole console;
    Input input;

    console.setConsoleCursorPosition({LEFT_SPACING, UP_SPACING});
    this->idCard = input.identificationCard("Ingresa tu cedula: ");
    console.setConsoleCursorPosition({LEFT_SPACING, (UP_SPACING + 1)});
    this->firstName = input.oneWord("Ingrese su nombre: ", 3, 20);
    console.setConsoleCursorPosition({LEFT_SPACING, (UP_SPACING + 2)});
    this->lastName = input.oneWord("Ingrese su apellido: ", 3, 20);
    console.setConsoleCursorPosition({LEFT_SPACING, (UP_SPACING + 3)});
    this->password = input.alphanumeric("Ingresa una clave (entre 5 a 10 caracteres): ", 5, 10);
}