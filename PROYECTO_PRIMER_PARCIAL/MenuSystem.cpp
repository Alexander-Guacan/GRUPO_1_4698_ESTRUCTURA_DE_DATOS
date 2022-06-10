#include "MenuSystem.hpp"
#include <conio.h>

short MenuSystem::start() {
    system("cls");
    printOptions();
    HandleConsole console;
    console.setConsoleCursorVisibility(false);

    enum positions {
        FIRST_OPTION_ID,
        SECOND_OPTION_ID,
        THIRD_OPTION_ID,
        RETURN_OPTION_ID,
        EXIT_OPTION_ID
    };

    const int UP_KEY{328};
    const int DOWN_KEY{336};
    const int ENTER_KEY{13};

    bool hasPressedEnter = false;
    short selectedOptionPositionY{FIRST_OPTION_ID};
    short optionSelected{BUY};

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

                case THIRD_OPTION_ID:
                    optionSelected = renderThirdOption();
                    break;

                case RETURN_OPTION_ID:
                    optionSelected = renderReturnOption();
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

void MenuSystem::printOptions() {
    HandleConsole console;

    console.printTextWithColor("MENU DE COMPRA DE CELULARES", console.RED, {SPACE_LEFT, TITLE_POSITION});

    console.printTextWithColor("Comprar", console.GREEN, {SPACE_LEFT, FIRST_OPTION_POSITION});
    
    console.printTextWithColor("Ver listado completo", console.GREY, {SPACE_LEFT, SECOND_OPTION_POSITION});
    
    console.printTextWithColor("Stock", console.GREY, {SPACE_LEFT, THIRD_OPTION_POSITION});

    console.printTextWithColor("Regresar", console.GREY, {SPACE_LEFT, RETURN_OPTION_POSITION});

    console.printTextWithColor("Salir", console.GREY, {SPACE_LEFT, EXIT_OPTION_POSITION});
}

short MenuSystem::renderFirstOption() {
    HandleConsole console;

    console.printTextWithColor("Comprar", console.GREEN, {SPACE_LEFT, FIRST_OPTION_POSITION});
    
    console.printTextWithColor("Ver listado completo", console.GREY, {SPACE_LEFT, SECOND_OPTION_POSITION});

    return BUY;
}

short MenuSystem::renderSecondOption() {
    HandleConsole console;

    console.printTextWithColor("Comprar", console.GREY, {SPACE_LEFT, FIRST_OPTION_POSITION});
    
    console.printTextWithColor("Ver listado completo", console.GREEN, {SPACE_LEFT, SECOND_OPTION_POSITION});
    
    console.printTextWithColor("Stock", console.GREY, {SPACE_LEFT, THIRD_OPTION_POSITION});

    return COMPLETE_LIST;
}

short MenuSystem::renderThirdOption() {
    HandleConsole console;
    
    console.printTextWithColor("Ver listado completo", console.GREY, {SPACE_LEFT, SECOND_OPTION_POSITION});
    
    console.printTextWithColor("Stock", console.GREEN, {SPACE_LEFT, THIRD_OPTION_POSITION});

    console.printTextWithColor("Regresar", console.GREY, {SPACE_LEFT, RETURN_OPTION_POSITION});

    return STOCK;
}

short MenuSystem::renderReturnOption() {
    HandleConsole console;
    
    console.printTextWithColor("Stock", console.GREY, {SPACE_LEFT, THIRD_OPTION_POSITION});

    console.printTextWithColor("Regresar", console.GREEN, {SPACE_LEFT, RETURN_OPTION_POSITION});

    console.printTextWithColor("Salir", console.GREY, {SPACE_LEFT, EXIT_OPTION_POSITION});

    return RETURN;
}

short MenuSystem::renderExitOption() {
    HandleConsole console;

    console.printTextWithColor("Regresar", console.GREY, {SPACE_LEFT, RETURN_OPTION_POSITION});

    console.printTextWithColor("Salir", console.GREEN, {SPACE_LEFT, EXIT_OPTION_POSITION});

    return EXIT;
}