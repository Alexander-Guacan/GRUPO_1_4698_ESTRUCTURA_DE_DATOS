#include "HandleConsole.hpp"
#include "BankGUI.hpp"
#include <conio.h>

int BankGUI::printScreen() {
    HandleConsole::setConsoleCursorVisibility(false);
    HandleConsole::clearScreen();
    printOptions();

    const int UP_KEY{328};
    const int DOWN_KEY{336};
    const int ENTER_KEY{13};

    int optionSelected = static_cast<int>(BankGUI::Options::ADD);
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
                case static_cast<int>(BankGUI::Options::ADD):
                    optionSelected = printAddOption();
                    break;

                case static_cast<int>(BankGUI::Options::ATEND):
                    optionSelected = printAtendOption();
                    break;

                case static_cast<int>(BankGUI::Options::SHOW_ALL):
                    optionSelected = printShowAllOption();
                    break;

                case static_cast<int>(BankGUI::Options::SHOW_NEXT):
                    optionSelected = printShowNextOption();
                    break;

                case static_cast<int>(BankGUI::Options::EXIT):
                    optionSelected = printExitOption();
                    break;
            }
        }
    }

    HandleConsole::setConsoleCursorVisibility(true);
    return optionSelected;
}

void BankGUI::printOptions() {
    HandleConsole console;

    console.setCursorPosition(TITLE_POSITION);
    console.printTextWithColor("MENU", HandleConsole::TextColors::DEEP_GREEN);

    console.setCursorPosition(ADD_OPTION_POSITION);
    console.printTextWithColor("> Agregar persona a la cola <", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(ATEND_OPTION_POSITION);
    console.printTextWithColor("  Atender cliente  ", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(SHOW_ALL_OPTION_POSITION);
    console.printTextWithColor("  Vista previa de la cola  ", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(SHOW_NEXT_OPTION_POSITION);
    console.printTextWithColor("  Siguiente en atender  ", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(EXIT_OPTION_POSITION);
    console.printTextWithColor("  Salir  ", HandleConsole::TextColors::DEEP_RED);
}

int BankGUI::printAddOption() {
    HandleConsole console;

    console.setCursorPosition(ADD_OPTION_POSITION);
    console.printTextWithColor("> Agregar persona a la cola <", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(ATEND_OPTION_POSITION);
    console.printTextWithColor("  Atender cliente  ", HandleConsole::TextColors::DEEP_CYAN);

    return static_cast<int>(BankGUI::Options::ADD);
}

int BankGUI::printAtendOption() {
    HandleConsole console;

    console.setCursorPosition(ADD_OPTION_POSITION);
    console.printTextWithColor("  Agregar persona a la cola  ", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(ATEND_OPTION_POSITION);
    console.printTextWithColor("> Atender cliente <", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(SHOW_ALL_OPTION_POSITION);
    console.printTextWithColor("  Vista previa de la cola  ", HandleConsole::TextColors::DEEP_CYAN);

    return static_cast<int>(BankGUI::Options::ATEND);
}

int BankGUI::printShowAllOption() {
    HandleConsole console;

    console.setCursorPosition(ATEND_OPTION_POSITION);
    console.printTextWithColor("  Atender cliente  ", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(SHOW_ALL_OPTION_POSITION);
    console.printTextWithColor("> Vista previa de la cola <", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(SHOW_NEXT_OPTION_POSITION);
    console.printTextWithColor("  Siguiente en atender  ", HandleConsole::TextColors::DEEP_CYAN);

    return static_cast<int>(BankGUI::Options::SHOW_ALL);
}

int BankGUI::printShowNextOption() {
    HandleConsole console;

    console.setCursorPosition(SHOW_ALL_OPTION_POSITION);
    console.printTextWithColor("  Vista previa de la cola  ", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(SHOW_NEXT_OPTION_POSITION);
    console.printTextWithColor("> Siguiente en atender <", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(EXIT_OPTION_POSITION);
    console.printTextWithColor("  Salir  ", HandleConsole::TextColors::DEEP_RED);

    return static_cast<int>(BankGUI::Options::SHOW_NEXT);
}

int BankGUI::printExitOption() {
    HandleConsole console;

    console.setCursorPosition(SHOW_NEXT_OPTION_POSITION);
    console.printTextWithColor("  Siguiente en atender  ", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(EXIT_OPTION_POSITION);
    console.printTextWithColor("> Salir <", HandleConsole::TextColors::DEEP_RED);

    return static_cast<int>(BankGUI::Options::EXIT);
}