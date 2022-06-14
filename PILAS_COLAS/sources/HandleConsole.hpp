#ifndef HANDLE_CONSOLE_HPP
#define HANDLE_CONSOLE_HPP

#include <windows.h>

class HandleConsole {
    private:
        COORD cursor{0, 0};

    public:
        enum class TextColors : const int {
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
        static void setConsoleTextColor(enum HandleConsole::TextColors colorId);
        COORD getCursor();
        void setCursorPosition(COORD position);
        void printTextWithColor(const char* message, enum HandleConsole::TextColors colorId);
};

#endif