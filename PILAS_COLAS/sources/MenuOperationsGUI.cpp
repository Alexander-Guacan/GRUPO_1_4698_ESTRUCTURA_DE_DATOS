#include "MenuOperationsGUI.hpp"
#include "HandleConsole.hpp"
#include <conio.h>

int MenuOperationsGUI::printScreen() {
    HandleConsole::setConsoleCursorVisibility(false);
    HandleConsole::clearScreen();
    printOptions();

    const int UP_KEY{328};
    const int DOWN_KEY{336};
    const int ENTER_KEY{13};

    int optionSelected = static_cast<int>(MenuOperationsGUI::Options::ADD);
    int keyPressed{};

    while ((keyPressed = getch()) != ENTER_KEY) {
        if (kbhit()) {
            if (keyPressed == 0 || keyPressed == 224)
                keyPressed = 256 + getch();

            switch (keyPressed) {
                case UP_KEY:
                    if (optionSelected > static_cast<int>(Options::ADD)) {
                        optionSelected--;
                    }

                    break;

                case DOWN_KEY:
                    if (optionSelected < static_cast<int>(Options::EXIT)) {
                        optionSelected++;
                    }
                    
                    break;
            }

            switch (optionSelected) {
                case static_cast<int>(MenuOperationsGUI::Options::ADD):
                    optionSelected = printAddOption();
                    break;

                case static_cast<int>(MenuOperationsGUI::Options::DELETE_ELEMENT):
                    optionSelected = printDeleteOption();
                    break;

                case static_cast<int>(MenuOperationsGUI::Options::SHOW_WITHOUT_DELETE):
                    optionSelected = printShowWithoutDeleteOption();
                    break;

                case static_cast<int>(MenuOperationsGUI::Options::SHOW_WITH_DELETE):
                    optionSelected = printShowWithDeleteOption();
                    break;

                case static_cast<int>(MenuOperationsGUI::Options::CALCULATE_VARIANCE):
                    optionSelected = printCalculateVarianceOption();
                    break;

                case static_cast<int>(MenuOperationsGUI::Options::EXIT):
                    optionSelected = printExitOption();
                    break;
            }
        }
    }

    HandleConsole::setConsoleCursorVisibility(true);
    return optionSelected;
}

void MenuOperationsGUI::printOptions() {
    HandleConsole console;

    console.setCursorPosition(TITLE_POSITION);
    console.printTextWithColor("MENU", HandleConsole::TextColors::DEEP_GREEN);

    console.setCursorPosition(ADD_OPTION_POSITION);
    console.printTextWithColor("> Agregar elemento <", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(DELETE_OPTION_POSITION);
    console.printTextWithColor("  Eliminar  elemento  ", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(SHOW_WITHOUT_DELETE_OPTION_POSITION);
    console.printTextWithColor("  Mostrar  ", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(SHOW_WITH_DELETE_OPTION_POSITION);
    console.printTextWithColor("  Extraer todo  ", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(CALCULATE_VARIANCE_OPTION_POSITION);
    console.printTextWithColor("  Calcular varianza  ", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(EXIT_OPTION_POSITION);
    console.printTextWithColor("  Salir  ", HandleConsole::TextColors::DEEP_RED);
}

int MenuOperationsGUI::printAddOption() {
    HandleConsole console;

    console.setCursorPosition(ADD_OPTION_POSITION);
    console.printTextWithColor("> Agregar elemento <", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(DELETE_OPTION_POSITION);
    console.printTextWithColor("  Eliminar  elemento  ", HandleConsole::TextColors::DEEP_CYAN);

    return static_cast<int>(MenuOperationsGUI::Options::ADD);
}

int MenuOperationsGUI::printDeleteOption() {
    HandleConsole console;

    console.setCursorPosition(ADD_OPTION_POSITION);
    console.printTextWithColor("  Agregar elemento  ", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(DELETE_OPTION_POSITION);
    console.printTextWithColor("> Eliminar  elemento <", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(SHOW_WITHOUT_DELETE_OPTION_POSITION);
    console.printTextWithColor("  Mostrar  ", HandleConsole::TextColors::DEEP_CYAN);

    return static_cast<int>(MenuOperationsGUI::Options::DELETE_ELEMENT);
}

int MenuOperationsGUI::printShowWithoutDeleteOption() {
    HandleConsole console;

    console.setCursorPosition(DELETE_OPTION_POSITION);
    console.printTextWithColor("  Eliminar  elemento  ", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(SHOW_WITHOUT_DELETE_OPTION_POSITION);
    console.printTextWithColor("> Mostrar <", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(SHOW_WITH_DELETE_OPTION_POSITION);
    console.printTextWithColor("  Extraer todo  ", HandleConsole::TextColors::DEEP_CYAN);

    return static_cast<int>(MenuOperationsGUI::Options::SHOW_WITHOUT_DELETE);
}

int MenuOperationsGUI::printShowWithDeleteOption() {
    HandleConsole console;

    console.setCursorPosition(SHOW_WITHOUT_DELETE_OPTION_POSITION);
    console.printTextWithColor("  Mostrar  ", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(SHOW_WITH_DELETE_OPTION_POSITION);
    console.printTextWithColor("> Extraer todo <", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(CALCULATE_VARIANCE_OPTION_POSITION);
    console.printTextWithColor("  Calcular varianza  ", HandleConsole::TextColors::DEEP_CYAN);

    return static_cast<int>(MenuOperationsGUI::Options::SHOW_WITH_DELETE);
}

int MenuOperationsGUI::printCalculateVarianceOption() {
    HandleConsole console;

    console.setCursorPosition(SHOW_WITH_DELETE_OPTION_POSITION);
    console.printTextWithColor("  Extraer todo  ", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(CALCULATE_VARIANCE_OPTION_POSITION);
    console.printTextWithColor("> Calcular varianza <", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(EXIT_OPTION_POSITION);
    console.printTextWithColor("  Salir  ", HandleConsole::TextColors::DEEP_RED);

    return static_cast<int>(MenuOperationsGUI::Options::CALCULATE_VARIANCE);
}

int MenuOperationsGUI::printExitOption() {
    HandleConsole console;

    console.setCursorPosition(CALCULATE_VARIANCE_OPTION_POSITION);
    console.printTextWithColor("  Calcular varianza  ", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(EXIT_OPTION_POSITION);
    console.printTextWithColor("> Salir <", HandleConsole::TextColors::DEEP_RED);

    return static_cast<int>(MenuOperationsGUI::Options::EXIT);
}