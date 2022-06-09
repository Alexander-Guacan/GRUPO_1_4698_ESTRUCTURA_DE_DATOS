#include "HandleConsole.hpp"
#include <iostream>

void HandleConsole::setConsoleCursorVisibility(bool enabled) {
    HANDLE consoleIdentification = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;

    cursor.bVisible = enabled;
    cursor.dwSize = (enabled) ? 3 : 1;

    SetConsoleCursorInfo(consoleIdentification, &cursor);
}

void HandleConsole::setConsoleCursorPosition(COORD positionXY) {
    HANDLE consoleIdentification = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(consoleIdentification, positionXY);
}

void HandleConsole::printTextWithColor(const char* message, int colorId) {
    HANDLE consoleIdentification = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleIdentification, colorId);

    std::cout << message;

    SetConsoleTextAttribute(consoleIdentification, GREY);
}

void HandleConsole::printTextWithColor(const char* message, int colorId, COORD positionXY) {
    HANDLE consoleIdentification = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleIdentification, colorId);

    setConsoleCursorPosition(positionXY);
    std::cout << message;

    SetConsoleTextAttribute(consoleIdentification, GREY);
}