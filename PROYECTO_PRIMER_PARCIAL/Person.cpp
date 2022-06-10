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

void Person::setEmail(const char *newEmail) {
    std::strcpy(this->email, newEmail);
}

void Person::setData() {
    Input input;
    this->idCard = input.identificationCard("\nIngresa tu cedula: ");
    this->firstName = input.oneWord("Ingrese su nombre: ", 3, 20);
    this->lastName = input.oneWord("Ingrese su apellido: ", 3, 20);
    this->password = input.any("Ingresa una clave (entre 5 a 10 caracteres): ", 5, 10);
}