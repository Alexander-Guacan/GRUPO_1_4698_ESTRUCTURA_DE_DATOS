#include "EmailGenerator.hpp"

EmailGenerator::EmailGenerator(const char *initialDomain) {
    this->domain = initialDomain;
}

void EmailGenerator::generate(Person *person, short repeats) {
    char *email = new char[45]{};

    *email = *(person->getFirstName());

    std::strcat(email, person->getLastName());

    if (repeats > 0) {
        char *iterator = email;
        while (*iterator != '\0')
            iterator++;

        *iterator = repeats + '0';
    }

    std::strcat(email, this->domain);
    person->setEmail(strlwr(email));
}