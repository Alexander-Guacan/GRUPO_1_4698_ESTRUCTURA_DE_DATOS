#include "HandleConsole.hpp"
#include <iostream>

void HandleConsole::clearScreen() {
    system("cls");
}

void HandleConsole::setConsoleCursorVisibility(bool enabled) {
    HANDLE consoleIdentification = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    cursorInfo.bVisible = enabled;

    const int DEFAULT_SIZE{3};
    const int INVISIBLE_SIZE{1};
    cursorInfo.dwSize = (enabled) ? DEFAULT_SIZE : INVISIBLE_SIZE;

    SetConsoleCursorInfo(consoleIdentification, &cursorInfo);
}

void HandleConsole::setConsoleTextColor(enum HandleConsole::TextColors colorId) {
    HANDLE consoleIdentification = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleIdentification, static_cast<int>(colorId));
}

COORD HandleConsole::getCursor() {
    return this->cursor;
}

void HandleConsole::setCursorPosition(COORD position) {
    this->cursor = position;

    HANDLE consoleIdentification = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(consoleIdentification, this->cursor);
}

void HandleConsole::printTextWithColor(const char* message, enum HandleConsole::TextColors colorId) {
    setConsoleTextColor(colorId);

    std::cout << message;

    setConsoleTextColor(TextColors::GREY);

    this->cursor.Y++;
    setCursorPosition(this->cursor);
}