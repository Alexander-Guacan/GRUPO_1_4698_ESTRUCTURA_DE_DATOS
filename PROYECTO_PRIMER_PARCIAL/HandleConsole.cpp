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

void HandleConsole::setConsoleTextColor(int colorId) {
    HANDLE consoleIdentification = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleIdentification, colorId);
}

void HandleConsole::printTextWithColor(const char* message, int colorId) {
    setConsoleTextColor(colorId);

    std::cout << message;

    setConsoleTextColor(GREY);
}

void HandleConsole::printTextWithColor(const char* message, int colorId, COORD positionXY) {
    setConsoleTextColor(colorId);

    setConsoleCursorPosition(positionXY);
    std::cout << message;

    setConsoleTextColor(GREY);
}