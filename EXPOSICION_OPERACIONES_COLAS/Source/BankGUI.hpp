/*
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE
 * Crear un ejemplo que involucre el uso de la estructura de datos queue
 * Autor: Alexander David Guacán Rivera y Alison Paola Moncayo Achilchisa
 * Fecha de creacion: 14/06/2022
 * Fecha de ultima modificación: 15/06/2022
 * Grupo: 1
 * Github: https://github.com/Alexander-Guacan/GRUPO_1_4698_ESTRUCTURA_DE_DATOS.git
 */

#ifndef BANK_GUI_HPP
#define BANK_GUI_HPP

#include <windows.h>

class BankGUI {
     private:
        const COORD TITLE_POSITION {
            55,
            5
        };

        const COORD ADD_OPTION_POSITION {
            static_cast<SHORT>(TITLE_POSITION.X - 12),
            static_cast<SHORT>(TITLE_POSITION.Y + 3)
        };

        const COORD ATEND_OPTION_POSITION {
            static_cast<SHORT>(TITLE_POSITION.X - 7),
            static_cast<SHORT>(ADD_OPTION_POSITION.Y + 1)
        };

        const COORD SHOW_ALL_OPTION_POSITION {
            static_cast<SHORT>(TITLE_POSITION.X - 11),
            static_cast<SHORT>(ATEND_OPTION_POSITION.Y + 1)
        };

        const COORD SHOW_NEXT_OPTION_POSITION {
            static_cast<SHORT>(TITLE_POSITION.X - 10),
            static_cast<SHORT>(SHOW_ALL_OPTION_POSITION.Y + 1)
        };


        const COORD EXIT_OPTION_POSITION {
            static_cast<SHORT>(TITLE_POSITION.X - 3),
            static_cast<SHORT>(SHOW_NEXT_OPTION_POSITION.Y + 3)
        };

        void printOptions();
        int printAddOption();
        int printAtendOption();
        int printShowAllOption();
        int printShowNextOption();
        int printExitOption();

    public:

        enum class Options : const int {
            ADD,
            ATEND,
            SHOW_ALL,
            SHOW_NEXT,
            EXIT
        };

        int printScreen();
};

#endif