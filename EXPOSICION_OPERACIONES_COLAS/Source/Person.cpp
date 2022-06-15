#include "Person.hpp"

void Person::setFirstName(char *newFirstName) {
    this->firstName = newFirstName;
}

void Person::setLastName(char *newLastName) {
    this->lastName = newLastName;
}

void Person::setIdCard(char *newIdCard) {
    this->idCard = newIdCard;
}

void Person::setMoneyOfBank(double newMoneyOfBank) {
    this->moneyOfBank = newMoneyOfBank;
}

char *Person::getFirstName() {
    return this->firstName;
}

char *Person::getLastName() {
    return this->lastName;
}

const char *Person::getIdCard() {
    return this->idCard;
}

double Person::getMoneyOfBank() {
    return this->moneyOfBank;
}

void Person::substract(double amount) {

    if (amount <= this->moneyOfBank) {
        this->moneyOfBank -= amount;
    }
}