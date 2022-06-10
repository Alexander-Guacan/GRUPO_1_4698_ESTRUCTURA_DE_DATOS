#ifndef LOGIN_MANAGER_HPP
#define LOGIN_MANAGER_HPP

#include "CircularDoublyLinkedList.hpp"
#include "Person.hpp"

class LoginManager {

    private:
        bool login(List<Person> *users);
        bool registerOnSystem(List<Person> *users);

    public:
        void start();
};

#endif