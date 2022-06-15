/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Crear un ejemplo que involucre el uso de la estructura de datos queue
 * Autor: Alexander David Guacán Rivera y Alison Paola Moncayo Achilchisa
 * Fecha de creacion: 14/06/2022
 * Fecha de ultima modificación: 15/06/2022
 * Grupo: 1
 * Github: https://github.com/Alexander-Guacan/GRUPO_1_4698_ESTRUCTURA_DE_DATOS.git
 */

#ifndef HANDLE_CONSOLE_HPP
#define HANDLE_CONSOLE_HPP

#include <windows.h>

class HandleConsole {
    private:
        COORD cursor{0, 0};

    public:
        enum class TextColors : const int {
            BLACK,
            BLUE,
            GREEN,
            CYAN,
            RED,
            MAGENTA,
            BROWN,
            GREY,
            DEEP_GREY,
            DEEP_BLUE,
            DEEP_GREEN,
            DEEP_CYAN,
            DEEP_RED,
            DEEP_MAGENTA,
            YELLOW,
            WHITE
        };

        static void clearScreen();
        static void setConsoleCursorVisibility(bool enabled);
        static void setConsoleTextColor(enum HandleConsole::TextColors colorId);
        void setCursorPosition(COORD position);
        void printTextWithColor(const char* message, enum HandleConsole::TextColors colorId);
};

#endif