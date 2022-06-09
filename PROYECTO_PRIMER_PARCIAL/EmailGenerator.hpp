#ifndef EMAIL_GENERATOR_HPP
#define EMAIL_GENERATOR_HPP

#include "Person.hpp"
#include "CircularDoublyLinkedList.hpp"

class EmailGenerator {
    const char *domain{};

    public:
        EmailGenerator(const char *initialDomain);
        void generate(Person *person, short repeats);
};

#endif