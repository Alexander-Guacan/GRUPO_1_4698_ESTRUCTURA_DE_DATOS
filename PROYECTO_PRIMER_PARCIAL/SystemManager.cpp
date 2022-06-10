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
                buySmartphone();
                break;

            case SOLD_SMARTPHONE:
                soldSmartphone();
                break;

            case ALL_SMARTPHONES:
                allSmartphones();
                break;

            case STOCK_SMARTPHONE:
                stockSmartphone();
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

void SystemManager::buySmartphone() {
    system("cls");

    const short LEFT_SPACING = 40;
    const short UP_SPACING = 5;

    HandleConsole console;
    console.printTextWithColor("\t[COMPRA DE CELULAR]", console.RED, {LEFT_SPACING, UP_SPACING - 1});

    Smartphone *smartphoneToInsert = new Smartphone();

    Input input;
    console.setConsoleCursorPosition({LEFT_SPACING, UP_SPACING + 3});
    int amountToAdd = input.positiveIntegerNumber("Ingrese la cantidad de telefonos comprados: ", 1, 4);
    
    IteratorLinkedList<Smartphone> *iterator = smartphones->getIterator();
    bool hasFoundSmartphone = false;

    Smartphone *smartphoneInList{nullptr};
    while (iterator->hasNext() && !hasFoundSmartphone) {
        smartphoneInList = iterator->getData();
        hasFoundSmartphone = *(smartphoneToInsert) == *(smartphoneInList);
    }

    if (!hasFoundSmartphone) {
        smartphoneToInsert->addSmartphoneAmount(amountToAdd);
        smartphones->insertAtEnd(smartphoneToInsert);
    } else {
        smartphoneInList->addSmartphoneAmount(amountToAdd);
    }
    
}

void SystemManager::soldSmartphone() {
    system("cls");

    const short LEFT_SPACING = 40;
    const short UP_SPACING = 5;

    HandleConsole console;
    Input input;

    console.printTextWithColor("[VENTA DE CELULAR]", console.RED, {LEFT_SPACING, UP_SPACING});

    console.setConsoleCursorPosition({LEFT_SPACING, UP_SPACING + 1});
    char *mark = input.alphabetic("Ingrese la marca del celular: ", 3, 15);
    console.setConsoleCursorPosition({LEFT_SPACING, UP_SPACING + 2});
    char *model = input.alphanumeric("Ingrese el modelo del celular: ", 3, 10);

    Smartphone *smartphoneToSearch = new Smartphone(mark, model, 0);

    IteratorLinkedList<Smartphone> *iterator = smartphones->getIterator();
    bool hasFoundSmartphone = false;

    Smartphone *smartphoneInList{nullptr};
    int positionInList{};
    while (iterator->hasNext() && !hasFoundSmartphone) {
        positionInList++;
        smartphoneInList = iterator->getData();
        hasFoundSmartphone = *(smartphoneToSearch) == *(smartphoneInList);
    }

    if (hasFoundSmartphone) {
        int amountToRemove{};
        int sizeOfMessage{};

        do {
            console.setConsoleCursorPosition({LEFT_SPACING, UP_SPACING + 3});
            for (short i{}; i < sizeOfMessage; i++) {
                printf(" ");
            }

            console.setConsoleCursorPosition({LEFT_SPACING, UP_SPACING + 3});
            amountToRemove = input.positiveIntegerNumber("Ingrese cantidad de celulares a vender: ", 1, 4);

            if (amountToRemove > smartphoneInList->getAmount()) {
                console.setConsoleCursorPosition({LEFT_SPACING, UP_SPACING + 3});
                sizeOfMessage = printf("[CANTIDAD MAYOR A LA DISPONIBLE, PRESIONE CUALQUIER TECLA PARA REINTENTAR]");
            } else {
                console.printTextWithColor("[VENTA REALIZADA, PRESIONE CUALQUIER TECLA PARA CONTINUAR]", console.GREEN, {LEFT_SPACING, UP_SPACING + 4});
            }

            getch();

        } while (amountToRemove > smartphoneInList->getAmount());

        smartphoneInList->reduceSmartphoneAmount(amountToRemove);

        if (smartphoneInList->getAmount() <= 0) {
            this->smartphones->deleteAt(positionInList);
        }
            
    } else {
        console.printTextWithColor("[EL TELEFONO QUE BUSCA NO SE ENCUENTRA DISPONIBLE, PRESIONA CUALQUIER TECLA PARA CONTINUAR]", console.RED, {LEFT_SPACING, UP_SPACING + 3});
        getch();
    }

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

void SystemManager::stockSmartphone() {
    system("cls");

    HandleConsole console;

    console.printTextWithColor("\t\t[TELEFONO A BUSCAR EN LA TIENDA]\n", console.RED);

    Input input;

    char *mark = input.alphabetic("Ingrese la marca del celular: ", 3, 15);
    char *model = input.alphanumeric("Ingrese el modelo del celular: ", 3, 10);
    Smartphone *smartphoneToSearch = new Smartphone(mark, model, 0);

    IteratorLinkedList<Smartphone> *iterator = smartphones->getIterator();
    bool hasFoundSmartphone = false;

    Smartphone *smartphoneInList{nullptr};
    while (iterator->hasNext() && !hasFoundSmartphone) {
        smartphoneInList = iterator->getData();
        hasFoundSmartphone = *(smartphoneToSearch) == *(smartphoneInList);
    }

    if (!hasFoundSmartphone)
        console.printTextWithColor("\n[NO EXISTE EL TELEFONO EN LA TIENDA]\n", console.RED);

    else {
        console.setConsoleTextColor(console.GREEN);
        std::cout << *(smartphoneInList);
    }

    console.printTextWithColor("\t\t----PRESIONA UNA TECLA PARA CONTINUAR----", console.BLUE);
    getch();
}