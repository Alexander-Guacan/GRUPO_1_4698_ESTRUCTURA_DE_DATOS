#include "Person.hpp"

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

    Input input;
    this->idCard = input.identificationCard("\nIngresa tu cedula: ");
    this->firstName = input.oneWord("Ingrese su nombre: ", 3, 20);
    this->lastName = input.oneWord("Ingrese su apellido: ", 3, 20);
    this->password = input.alphanumeric("Ingresa una clave (entre 5 a 10 caracteres): ", 5, 10);
}