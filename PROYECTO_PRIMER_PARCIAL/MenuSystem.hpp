#ifndef MENU_SYSTEM_HPP
#define MENU_SYSTEM_HPP

class MenuSystem {
    private:
        const short TITLE_POSITION = 5;
        const short FIRST_OPTION_POSITION = TITLE_POSITION + 2;
        const short SECOND_OPTION_POSITION = FIRST_OPTION_POSITION + 1;
        const short THIRD_OPTION_POSITION = SECOND_OPTION_POSITION + 1;
        const short FOURTH_OPTION_POSITION = THIRD_OPTION_POSITION + 1;
        const short RETURN_OPTION_POSITION = FOURTH_OPTION_POSITION + 1;
        const short EXIT_OPTION_POSITION = RETURN_OPTION_POSITION + 1;
        const short SPACE_LEFT{40};
        
        void printOptions();
        short renderFirstOption();
        short renderSecondOption();
        short renderThirdOption();
        short renderFourthOption();
        short renderReturnOption();
        short renderExitOption();

    public:
        enum options {
            BUY,
            SOLD,
            COMPLETE_LIST,
            STOCK,
            RETURN,
            EXIT
        };

        short start();
};

#endif