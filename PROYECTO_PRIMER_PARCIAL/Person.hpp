#ifndef PERSON_HPP
#define PERSON_HPP

#include "Input.hpp"
#include <iostream>
#include <cstring>

class Person {
    char *idCard{};
    char *firstName{};
    char *lastName{};
    char *email{};
    char *password{};

    private:

    public:
        Person();
        Person(char *initialIdCard);
        Person(char *initialEmail, char *initialPassword);
        const char *getFirstName();
        const char *getLastName();
        const char *getEmail();
        const char *getPassword();
        void setEmail(char *newEmail);
        void setPassword(char *newPassword);
        void setData();

        bool operator ==(const Person &personToCompare) {
            return std::strcmp(idCard, personToCompare.idCard) == 0;
        }

        friend std::ostream& operator<<(std::ostream &output, const Person &personToPrint) {
            output << "\nNombre completo: " << personToPrint.firstName << " " << personToPrint.lastName
                   << "\nCedula: " << personToPrint.idCard
                   << "\nEmail: " << personToPrint.email << '\n';

            return output;
        }
};

#endif