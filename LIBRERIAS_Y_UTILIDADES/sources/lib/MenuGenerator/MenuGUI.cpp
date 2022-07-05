#include "MenuGUI.hpp"
#include "..\Tools\HandleConsole.hpp"
#include <conio.h>
#include <iostream>

void MenuGUI::printOptions() {
    system("clear");
    HandleConsole::setCursorVisibilitie(false);
    HandleConsole::setCursorPosition(this->menuPosition.X + 1, this->menuPosition.Y);
    std::cout << title;
    for (size_t option{1}; option <= sizeOfArrayOptions; option++) {
        HandleConsole::setCursorPosition(this->menuPosition.X, (this->menuPosition.Y + option));
        std::cout << ' ' << options[option - 1];
    }
}

void MenuGUI::printArrow() {
    for (size_t option{1}; option <= sizeOfArrayOptions; option++) {
        HandleConsole::setCursorPosition(arrowPosition.X, (this->arrowPosition.Y + option));
        std::cout << ((option == this->activeOption) ? "->" : "  ");
    }
}

void MenuGUI::setNextOption() {
    this->activeOption++;

    if (this->activeOption > this->sizeOfArrayOptions)
        this->activeOption = 1;
}

void MenuGUI::setPreviousOption() {
    this->activeOption--;

    if (this->activeOption <= 0)
        this->activeOption = this->sizeOfArrayOptions;
}


bool MenuGUI::switchOption(int keyPressed) {
    const short UP_KEY{72};
    const short DOWN_KEY{80};
    const short ENTER_KEY{13};

    switch (keyPressed) {
        case UP_KEY:
            setPreviousOption();
            break;
        case DOWN_KEY:
            setNextOption();
            break;
        case ENTER_KEY:
            return true;
    }

    return false;
}

MenuGUI::MenuGUI(const std::string &titleOfMenu, std::string listOptions[], size_t sizeOfListOptions, COORD positionOfMenu) {
    this->title = titleOfMenu;
    this->options = listOptions;
    this->sizeOfArrayOptions = sizeOfListOptions;
    this->menuPosition.X = positionOfMenu.X;
    this->menuPosition.Y = positionOfMenu.Y;
    this->arrowPosition.X = this->menuPosition.X - 2;
    this->arrowPosition.Y = this->menuPosition.Y;
}

int MenuGUI::start() {
    printOptions();

    bool exit{false};
    do {
        printArrow();
        while (!kbhit()) {}
        exit = switchOption(getch());
    } while (!exit);

    HandleConsole::setCursorVisibilitie(true);
    return this->activeOption;
}