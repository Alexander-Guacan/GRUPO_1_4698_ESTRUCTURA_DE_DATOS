#ifndef HANDLE_CONSOLE_HPP
#define HANDLE_CONSOLE_HPP

#include <windows.h>

class HandleConsole {
    private:

    public:
        static COORD cursor;
        enum class TextColors : int {
            BLACK,
            BLUE,
            GREEN,
            CYAN,
            RED,
            MAGENTA,
            BROWN,
            GREY,
            DEEP_GREY,
            DEEP_BLUE,
            DEEP_GREEN,
            DEEP_CYAN,
            DEEP_RED,
            DEEP_MAGENTA,
            YELLOW,
            WHITE
        };

        static void clearScreen();
        static void setConsoleCursorVisibility(bool enabled);
        static void setCursorPosition(COORD position);
        static void setConsoleTextColor(enum HandleConsole::TextColors colorId);
        static void printTextWithColor(const char* message, enum HandleConsole::TextColors colorId);
};

#endif