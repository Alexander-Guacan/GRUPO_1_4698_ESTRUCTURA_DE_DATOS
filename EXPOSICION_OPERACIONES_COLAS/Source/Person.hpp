/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Crear un ejemplo que involucre el uso de la estructura de datos queue
 * Autor: Alexander David Guacán Rivera y Alison Paola Moncayo Achilchisa
 * Fecha de creacion: 14/06/2022
 * Fecha de ultima modificación: 15/06/2022
 * Grupo: 1
 * Github: https://github.com/Alexander-Guacan/GRUPO_1_4698_ESTRUCTURA_DE_DATOS.git
 */

#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>

class Person {
    private:
        char *firstName{nullptr};
        char *lastName{nullptr};
        char *idCard{nullptr};
        double moneyOfBank{};

    public:
        void setFirstName(char *newFirstName);
        void setLastName(char *newLastName);
        void setIdCard(char *newIdCard);
        void setMoneyOfBank(double newMoneyOfBank);
        char *getFirstName();
        char *getLastName();
        const char *getIdCard();
        double getMoneyOfBank();
        void substract(double amount);
};

#endif