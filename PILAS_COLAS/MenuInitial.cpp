#include "MenuInitial.hpp"
#include "HandleConsole.hpp"
#include <conio.h>

const COORD MenuInitial::TITLE_POSITION = {
    10,
    5
};

const COORD MenuInitial::SUBTITLE_POSITION = {
    static_cast<SHORT>(TITLE_POSITION.X - 6),
    static_cast<SHORT>(TITLE_POSITION.Y + 1)
};

const COORD MenuInitial::STACK_OPTION_POSITION = {
    static_cast<SHORT>(TITLE_POSITION.X + 2),
    static_cast<SHORT>(SUBTITLE_POSITION.Y + 1)
};

const COORD MenuInitial::QUEUE_OPTION_POSITION = {
    static_cast<SHORT>(STACK_OPTION_POSITION.X + 15),
    static_cast<SHORT>(STACK_OPTION_POSITION.Y)
};

int MenuInitial::printScreen() {
    HandleConsole::setConsoleCursorVisibility(false);
    HandleConsole::clearScreen();
    printOptions();

    const int LEFT_KEY{331};
    const int RIGHT_KEY{333};
    const int ENTER_KEY{13};

    int optionSelected = static_cast<int>(MenuInitial::Options::STACK_OPTION);
    int keyPressed{};

    while ((keyPressed = getch()) != ENTER_KEY) {
        if (kbhit()) {
            if (keyPressed == 0 || keyPressed == 224)
                keyPressed = 256 + getch();

            switch (keyPressed) {
                case LEFT_KEY:
                    if (optionSelected > static_cast<int>(Options::STACK_OPTION)) {
                        optionSelected--;
                    }

                    break;

                case RIGHT_KEY:
                    if (optionSelected < static_cast<int>(Options::QUEUE_OPTION)) {
                        optionSelected++;
                    }
                    
                    break;
            }

            switch (optionSelected) {
                case static_cast<int>(MenuInitial::Options::STACK_OPTION):
                    optionSelected = printStackOption();
                    break;

                case static_cast<int>(MenuInitial::Options::QUEUE_OPTION):
                    optionSelected = printQueueOption();
                    break;
            }
        }
    }

    HandleConsole::setConsoleCursorVisibility(true);
    return optionSelected;
}

void MenuInitial::printOptions() {
    HandleConsole::setCursorPosition(MenuInitial::TITLE_POSITION);
    HandleConsole::printTextWithColor("EJERCICIO CON PILAS Y COLAS", HandleConsole::TextColors::BLUE);

    HandleConsole::setCursorPosition(MenuInitial::SUBTITLE_POSITION);
    HandleConsole::printTextWithColor("Que estructura de datos desea utilizar?", HandleConsole::TextColors::BLUE);

    HandleConsole::setCursorPosition(MenuInitial::STACK_OPTION_POSITION);
    HandleConsole::printTextWithColor("> Pila <", HandleConsole::TextColors::BLUE);

    HandleConsole::setCursorPosition(MenuInitial::QUEUE_OPTION_POSITION);
    HandleConsole::printTextWithColor("  Cola  ", HandleConsole::TextColors::BLUE);

    HandleConsole::setCursorPosition(MenuInitial::STACK_OPTION_POSITION);
}

int MenuInitial::printStackOption() {
    HandleConsole::setCursorPosition(MenuInitial::STACK_OPTION_POSITION);
    HandleConsole::printTextWithColor("> Pila <", HandleConsole::TextColors::BLUE);

    HandleConsole::setCursorPosition(MenuInitial::QUEUE_OPTION_POSITION);
    HandleConsole::printTextWithColor("  Cola  ", HandleConsole::TextColors::BLUE);

    HandleConsole::setCursorPosition(MenuInitial::STACK_OPTION_POSITION);

    return static_cast<int>(Options::STACK_OPTION);
}

int MenuInitial::printQueueOption() {
    HandleConsole::setCursorPosition(MenuInitial::STACK_OPTION_POSITION);
    HandleConsole::printTextWithColor("  Pila  ", HandleConsole::TextColors::BLUE);

    HandleConsole::setCursorPosition(MenuInitial::QUEUE_OPTION_POSITION);
    HandleConsole::printTextWithColor("> Cola <", HandleConsole::TextColors::BLUE);

    HandleConsole::setCursorPosition(MenuInitial::QUEUE_OPTION_POSITION);

    return static_cast<int>(Options::QUEUE_OPTION);
}