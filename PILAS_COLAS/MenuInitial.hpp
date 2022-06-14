#ifndef MENU_INITIAL_HPP
#define MENU_INITIAL_HPP

#include <windows.h>

class MenuInitial {
    private:
        static void printOptions();
        static int printStackOption();
        static int printQueueOption();

    public:
        static const COORD TITLE_POSITION;
        static const COORD SUBTITLE_POSITION;
        static const COORD STACK_OPTION_POSITION;
        static const COORD QUEUE_OPTION_POSITION;
        enum class Options : int {
            STACK_OPTION,
            QUEUE_OPTION
        };

        static int printScreen();
};

#endif