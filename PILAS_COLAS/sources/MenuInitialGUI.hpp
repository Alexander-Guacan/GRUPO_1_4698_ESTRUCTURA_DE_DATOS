#ifndef MENU_INITIAL_GUI_HPP
#define MENU_INITIAL_GUI_HPP

#include <windows.h>

class MenuInitialGUI {
    private:
        const COORD TITLE_POSITION {
            45,
            5
        };

        const COORD SUBTITLE_POSITION {
            static_cast<SHORT>(TITLE_POSITION.X - 6),
            static_cast<SHORT>(TITLE_POSITION.Y + 2)
        };

        const COORD STACK_OPTION_POSITION {
            static_cast<SHORT>(TITLE_POSITION.X - 10),
            static_cast<SHORT>(SUBTITLE_POSITION.Y + 2)
        };

        const COORD QUEUE_OPTION_POSITION {
            static_cast<SHORT>(STACK_OPTION_POSITION.X + 19),
            static_cast<SHORT>(STACK_OPTION_POSITION.Y)
        };

        const COORD EXIT_OPTION_POSITION {
            static_cast<SHORT>(QUEUE_OPTION_POSITION.X + 19),
            static_cast<SHORT>(STACK_OPTION_POSITION.Y)
        };

        void printOptions();
        int printStackOption();
        int printQueueOption();
        int printExitOption();

    public:

        enum class Options : const int {
            STACK,
            QUEUE,
            EXIT
        };

        int printScreen();
};

#endif