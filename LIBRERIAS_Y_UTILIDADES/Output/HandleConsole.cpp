#include "HandleConsole.hpp"
#include <windows.h>

void HandleConsole::setCursorPosition(short x, short y) {
    COORD position{x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void HandleConsole::setCursorVisibilitie(bool on) {
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = on;
    const short DEFAULT_CURSOR_SIZE{3};
    const short INVISIBLE_CURSOR_SIZE{1};
    cursor.bVisible = on;
    cursor.dwSize = (on) ? INVISIBLE_CURSOR_SIZE : DEFAULT_CURSOR_SIZE;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void HandleConsole::setTextColor(enum HandleConsole::TextColor color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<short>(color));
}