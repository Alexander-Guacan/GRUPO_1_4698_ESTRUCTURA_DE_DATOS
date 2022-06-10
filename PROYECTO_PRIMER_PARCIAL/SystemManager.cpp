#include "SystemManager.hpp"
#include "MenuSystem.hpp"
#include "HandleConsole.hpp"
#include "Input.hpp"

SystemManager::SystemManager(List<Smartphone> *initialSmartphones) {
    this->smartphones = initialSmartphones;
}

bool SystemManager::start() {
    MenuSystem menuSystem;
    const int BUY_SMARTPHONE = menuSystem.BUY;
    const int SOLD_SMARTPHONE = menuSystem.SOLD;
    const int ALL_SMARTPHONES = menuSystem.COMPLETE_LIST;
    const int STOCK_SMARTPHONE = menuSystem.STOCK;
    const int RETURN = menuSystem.RETURN;
    const int EXIT = menuSystem.EXIT;

    bool hasSelectedExit = false;
    bool hasSelectedReturn = false;

    while (!hasSelectedExit && !hasSelectedReturn) {
        switch (menuSystem.start()) {

            case BUY_SMARTPHONE:
                break;

            case SOLD_SMARTPHONE:
                break;

            case ALL_SMARTPHONES:
                allSmartphones();
                break;

            case STOCK_SMARTPHONE:
                break;

            case RETURN:
                hasSelectedReturn = true;
                break;

            case EXIT:
                hasSelectedExit = true;
                break;

        }
    }

    return hasSelectedExit && !hasSelectedReturn;
}

void SystemManager::allSmartphones() {
    system("cls");

    HandleConsole console;

    console.printTextWithColor("\t\t[LISTADO DE TELEFONOS]", console.RED);

    console.setConsoleTextColor(console.GREEN);
    this->smartphones->print();

    console.printTextWithColor("\t----PRESIONA UNA TECLA PARA CONTINUAR----", console.RED);
    getch();
}