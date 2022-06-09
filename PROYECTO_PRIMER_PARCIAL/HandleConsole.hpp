#ifndef HANDLE_CONSOLE_HPP
#define HANDLE_CONSOLE_HPP

#include <windows.h>

class HandleConsole {

    public:
        enum textColors {
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

        void setConsoleCursorVisibility(bool enabled);
        void setConsoleCursorPosition(COORD positionXY);
        void printTextWithColor(const char* message, int colorId);
        void printTextWithColor(const char* message, int colorId, COORD positionXY);
};

#endif