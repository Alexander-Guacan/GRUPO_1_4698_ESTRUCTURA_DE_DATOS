#include "MenuLogin.hpp"
#include <conio.h>

short MenuLogin::start() {
    system("cls");
    printOptions();
    HandleConsole console;
    console.setConsoleCursorVisibility(false);

    enum positions {
        FIRST_OPTION_ID,
        SECOND_OPTION_ID,
        EXIT_OPTION_ID
    };

    const int UP_KEY{328};
    const int DOWN_KEY{336};
    const int ENTER_KEY{13};

    bool hasPressedEnter = false;
    short selectedOptionPositionY{FIRST_OPTION_ID};
    short optionSelected{LOGIN};

    while (!hasPressedEnter) {
        if (kbhit()) {
            int keyPressed = getch();

            if (keyPressed == 0 || keyPressed == 224) keyPressed = 256 + getch();

            switch(keyPressed) {

                case UP_KEY:
                    if (selectedOptionPositionY > FIRST_OPTION_ID)
                        selectedOptionPositionY--;
                        
                    break;

                case DOWN_KEY:
                    if (selectedOptionPositionY < EXIT_OPTION_ID)
                        selectedOptionPositionY++;

                    break;

                case ENTER_KEY:
                    hasPressedEnter = true;
                    break;
            }

            switch (selectedOptionPositionY) {
                case FIRST_OPTION_ID:
                    optionSelected = renderFirstOption();
                    break;

                case SECOND_OPTION_ID:
                    optionSelected = renderSecondOption();
                    break;

                case EXIT_OPTION_ID:
                    optionSelected = renderExitOption();
                    break;
            }
        }

    }

    console.setConsoleCursorVisibility(true);
    return optionSelected;
}

void MenuLogin::printOptions() {
    HandleConsole console;

    console.printTextWithColor("LOGIN", console.RED, {SPACE_LEFT, TITLE_POSITION});

    console.printTextWithColor("Ingresar", console.GREEN, {SPACE_LEFT, FIRST_OPTION_POSITION});
    
    console.printTextWithColor("Registrarse", console.GREY, {SPACE_LEFT, SECOND_OPTION_POSITION});

    console.printTextWithColor("Salir", console.GREY, {SPACE_LEFT, EXIT_OPTION_POSITION});
}

short MenuLogin::renderFirstOption() {
    HandleConsole console;

    console.printTextWithColor("Ingresar", console.GREEN, {SPACE_LEFT, FIRST_OPTION_POSITION});
    
    console.printTextWithColor("Registrarse", console.GREY, {SPACE_LEFT, SECOND_OPTION_POSITION});

    return LOGIN;
}

short MenuLogin::renderSecondOption() {
    HandleConsole console;

    console.printTextWithColor("Ingresar", console.GREY, {SPACE_LEFT, FIRST_OPTION_POSITION});
    
    console.printTextWithColor("Registrarse", console.GREEN, {SPACE_LEFT, SECOND_OPTION_POSITION});
    
    console.printTextWithColor("Salir", console.GREY, {SPACE_LEFT, EXIT_OPTION_POSITION});

    return REGISTER;
}

short MenuLogin::renderExitOption() {
    HandleConsole console;

    console.printTextWithColor("Registrarse", console.GREY, {SPACE_LEFT, SECOND_OPTION_POSITION});

    console.printTextWithColor("Salir", console.GREEN, {SPACE_LEFT, EXIT_OPTION_POSITION});

    return EXIT;
}