#ifndef MENU_LOGIN_HPP
#define MENU_LOGIN_HPP

#include "HandleConsole.hpp"

class MenuLogin {
    private:
        const short TITLE_POSITION = 5;
        const short FIRST_OPTION_POSITION = TITLE_POSITION + 2;
        const short SECOND_OPTION_POSITION = FIRST_OPTION_POSITION + 1;
        const short EXIT_OPTION_POSITION = SECOND_OPTION_POSITION + 1;
        const short SPACE_LEFT = 40;

        void printOptions();
        short renderFirstOption();
        short renderSecondOption();
        short renderThirdOption();
        short renderReturnOption();
        short renderExitOption();

    public:
        enum options {
            LOGIN,
            REGISTER,
            EXIT
        };

        short start();
};

#endif