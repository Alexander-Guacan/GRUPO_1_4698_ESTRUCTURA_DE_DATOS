#ifndef MENU_OPERATIONS_GUI_HPP
#define MENU_OPERATIONS_GUI_HPP

#include <windows.h>

class MenuOperationsGUI {
    private:
        const COORD TITLE_POSITION {
            55,
            5
        };
        
        const COORD ADD_OPTION_POSITION {
            static_cast<SHORT>(TITLE_POSITION.X - 8),
            static_cast<SHORT>(TITLE_POSITION.Y + 3)
        };
        
        const COORD DELETE_OPTION_POSITION {
            static_cast<SHORT>(TITLE_POSITION.X - 9),
            static_cast<SHORT>(ADD_OPTION_POSITION.Y + 1)
        };
        
        const COORD SHOW_WITHOUT_DELETE_OPTION_POSITION {
            static_cast<SHORT>(TITLE_POSITION.X - 4),
            static_cast<SHORT>(DELETE_OPTION_POSITION.Y + 1)
        };
        
        const COORD SHOW_WITH_DELETE_OPTION_POSITION {
            static_cast<SHORT>(TITLE_POSITION.X - 6),
            static_cast<SHORT>(SHOW_WITHOUT_DELETE_OPTION_POSITION.Y + 1)
        };
        
        const COORD CALCULATE_VARIANCE_OPTION_POSITION {
            static_cast<SHORT>(TITLE_POSITION.X - 8),
            static_cast<SHORT>(SHOW_WITH_DELETE_OPTION_POSITION.Y + 1)
        };

        const COORD RETURN_OPTION_POSITION {
            static_cast<SHORT>(TITLE_POSITION.X - 4),
            static_cast<SHORT>(CALCULATE_VARIANCE_OPTION_POSITION.Y + 1)
        };
        
        const COORD EXIT_OPTION_POSITION {
            static_cast<SHORT>(TITLE_POSITION.X - 3),
            static_cast<SHORT>(RETURN_OPTION_POSITION.Y + 3)
        };
        
        void printOptions();
        int printAddOption();
        int printDeleteOption();
        int printShowWithoutDeleteOption();
        int printShowWithDeleteOption();
        int printCalculateVarianceOption();
        int printReturnOption();
        int printExitOption();

    public:

        enum class Options : const int {
            ADD,
            DELETE_ELEMENT,
            SHOW_WITHOUT_DELETE,
            SHOW_WITH_DELETE,
            CALCULATE_VARIANCE,
            RETURN,
            EXIT
        };

        int printScreen();
};

#endif