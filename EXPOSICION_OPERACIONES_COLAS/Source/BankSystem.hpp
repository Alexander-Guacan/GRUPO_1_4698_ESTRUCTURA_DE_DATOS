/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Crear un ejemplo que involucre el uso de la estructura de datos queue
 * Autor: Alexander David Guacán Rivera y Alison Paola Moncayo Achilchisa
 * Fecha de creacion: 14/06/2022
 * Fecha de ultima modificación: 15/06/2022
 * Grupo: 1
 * Github: https://github.com/Alexander-Guacan/GRUPO_1_4698_ESTRUCTURA_DE_DATOS.git
 */

#ifndef BANK_SYSTEM_HPP
#define BANK_SYSTEM_HPP

#include "Queue.hpp"

class Person;

class BankSystem {
    private:
        static Queue<Person> *usersToAtend;

        static bool selectOption();
        static void addClientToQueue();
        static void atendClient();
        static void showQueue();
        static void showNextPersonToAtend();

    public:
        static void start();
};

#endif