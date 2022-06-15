/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Trabajar con colas y pilas, generar sus operaciones basicas y construir un metodo que permite obtener la varianza en cada tipo de estructura
 * Autor: Alexander David Guacán Rivera y Alison Paola Moncayo Achilchisa
 * Fecha de creacion: 13/06/2022
 * Fecha de ultima modificación: 14/06/2022
 * Grupo: 1
 * Github: https://github.com/Alexander-Guacan/GRUPO_1_4698_ESTRUCTURA_DE_DATOS.git
 */ 

#ifndef MENU_INITIAL_GUI_HPP
#define MENU_INITIAL_GUI_HPP

#include <windows.h>

class MenuInitialGUI {
    private:
        const COORD TITLE_POSITION {
            45,
            5
        };

        const COORD SUBTITLE_POSITION {
            static_cast<SHORT>(TITLE_POSITION.X - 6),
            static_cast<SHORT>(TITLE_POSITION.Y + 2)
        };

        const COORD STACK_OPTION_POSITION {
            static_cast<SHORT>(TITLE_POSITION.X - 10),
            static_cast<SHORT>(SUBTITLE_POSITION.Y + 2)
        };

        const COORD QUEUE_OPTION_POSITION {
            static_cast<SHORT>(STACK_OPTION_POSITION.X + 19),
            static_cast<SHORT>(STACK_OPTION_POSITION.Y)
        };

        const COORD EXIT_OPTION_POSITION {
            static_cast<SHORT>(QUEUE_OPTION_POSITION.X + 19),
            static_cast<SHORT>(STACK_OPTION_POSITION.Y)
        };

        void printOptions();
        int printStackOption();
        int printQueueOption();
        int printExitOption();

    public:

        enum class Options : const int {
            STACK,
            QUEUE,
            EXIT
        };

        int printScreen();
};

#endif