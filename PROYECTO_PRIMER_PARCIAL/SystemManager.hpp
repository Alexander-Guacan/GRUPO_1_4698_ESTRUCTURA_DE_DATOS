#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

#include "CircularDoublyLinkedList.hpp"
#include "Smartphone.hpp"

class SystemManager {
    List<Smartphone> *smartphones{nullptr};

    private:
        void buySmartphone();
        void soldSmartphone();
        void allSmartphones();
        void stockSmartphone();

    public:
        SystemManager(List<Smartphone> *initialSmartphones);
        bool start();
};

#endif