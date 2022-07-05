#ifndef MENU_GUI_HPP
#define MENU_GUI_HPP

#include <windows.h>
#include <string>

class MenuGUI {
    private:
        COORD menuPosition{};
        COORD arrowPosition{};
        std::string title{};
        const std::string *options{nullptr};
        size_t sizeOfArrayOptions;
        short activeOption{1};

        void printOptions();
        void printArrow();
        void setNextOption();
        void setPreviousOption();
        bool switchOption(int keyPressed);

    public:
        MenuGUI(const std::string &titleOfMenu, std::string listOptions[], size_t sizeOfListOptions, COORD positionOfMenu);
        int start();
};

#endif