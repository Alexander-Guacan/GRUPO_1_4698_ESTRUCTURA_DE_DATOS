#include "MenuInitialGUI.hpp"
#include "HandleConsole.hpp"
#include <conio.h>

int MenuInitialGUI::printScreen() {
    HandleConsole::setConsoleCursorVisibility(false);
    HandleConsole::clearScreen();
    printOptions();

    const int LEFT_KEY{331};
    const int RIGHT_KEY{333};
    const int ENTER_KEY{13};

    int optionSelected = static_cast<int>(MenuInitialGUI::Options::STACK);
    int keyPressed{};

    while ((keyPressed = getch()) != ENTER_KEY) {
        if (kbhit()) {
            if (keyPressed == 0 || keyPressed == 224)
                keyPressed = 256 + getch();

            switch (keyPressed) {
                case LEFT_KEY:
                    if (optionSelected > static_cast<int>(Options::STACK)) {
                        optionSelected--;
                    }

                    break;

                case RIGHT_KEY:
                    if (optionSelected < static_cast<int>(Options::EXIT)) {
                        optionSelected++;
                    }
                    
                    break;
            }

            switch (optionSelected) {
                case static_cast<int>(MenuInitialGUI::Options::STACK):
                    optionSelected = printStackOption();
                    break;

                case static_cast<int>(MenuInitialGUI::Options::QUEUE):
                    optionSelected = printQueueOption();
                    break;

                case static_cast<int>(MenuInitialGUI::Options::EXIT):
                    optionSelected = printExitOption();
                    break;
            }
        }
    }

    HandleConsole::setConsoleCursorVisibility(true);
    return optionSelected;
}

void MenuInitialGUI::printOptions() {
    HandleConsole console;
    console.setCursorPosition(TITLE_POSITION);
    console.printTextWithColor("EJERCICIO CON PILAS Y COLAS", HandleConsole::TextColors::GREEN);

    console.setCursorPosition(SUBTITLE_POSITION);
    console.printTextWithColor("Elija la estructura de datos a utilizar", HandleConsole::TextColors::DEEP_CYAN);

    console.setCursorPosition(STACK_OPTION_POSITION);
    console.printTextWithColor("> Pila <", HandleConsole::TextColors::BLUE);

    console.setCursorPosition(QUEUE_OPTION_POSITION);
    console.printTextWithColor("  Cola  ", HandleConsole::TextColors::BLUE);

    console.setCursorPosition(EXIT_OPTION_POSITION);
    console.printTextWithColor("  Salir  ", HandleConsole::TextColors::BLUE);
}

int MenuInitialGUI::printStackOption() {
    HandleConsole console;
    console.setCursorPosition(STACK_OPTION_POSITION);
    console.printTextWithColor("> Pila <", HandleConsole::TextColors::BLUE);

    console.setCursorPosition(QUEUE_OPTION_POSITION);
    console.printTextWithColor("  Cola  ", HandleConsole::TextColors::BLUE);

    return static_cast<int>(Options::STACK);
}

int MenuInitialGUI::printQueueOption() {
    HandleConsole console;
    console.setCursorPosition(STACK_OPTION_POSITION);
    console.printTextWithColor("  Pila  ", HandleConsole::TextColors::BLUE);

    console.setCursorPosition(QUEUE_OPTION_POSITION);
    console.printTextWithColor("> Cola <", HandleConsole::TextColors::BLUE);

    console.setCursorPosition(EXIT_OPTION_POSITION);
    console.printTextWithColor("  Salir  ", HandleConsole::TextColors::BLUE);

    return static_cast<int>(Options::QUEUE);
}

int MenuInitialGUI::printExitOption() {
    HandleConsole console;
    console.setCursorPosition(QUEUE_OPTION_POSITION);
    console.printTextWithColor("  Cola  ", HandleConsole::TextColors::BLUE);

    console.setCursorPosition(EXIT_OPTION_POSITION);
    console.printTextWithColor("> Salir <", HandleConsole::TextColors::BLUE);

    return static_cast<int>(Options::EXIT);
}