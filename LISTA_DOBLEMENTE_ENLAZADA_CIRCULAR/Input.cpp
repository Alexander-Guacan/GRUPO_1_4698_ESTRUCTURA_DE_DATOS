#include "Input.hpp"

void Input::setTextColor(short colorId) {
    HANDLE consoleIdentificator = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleIdentificator, colorId);
}

int Input::unsignedIntegerNumber(const char *instructionMessage, short charactersAmount) {
    printf("%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[charactersAmount + 1]{};

    char keyPressed{};
    char *iterator{numbers};
    int sizeOfString{};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0') {
        if (keyPressed >= '0' && keyPressed <= '9' && sizeOfString < charactersAmount) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            sizeOfString--;
            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atoi(numbers);
}

int Input::integerNumber(const char* instructionMessage, short charactersAmount) {

    printf("%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[charactersAmount + 1]{};

    char keyPressed{};
    char *iterator{numbers};
    int sizeOfString{};

    /* 
        No saldra del bucle a menos que:
        - Presione Enter
        - Ingrese numeros
        - Ingrese signo negativo pero seguido un numero
     */
    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || (*numbers == '-' && *(numbers + 1) == '\0')) {
        if (keyPressed == '-' && iterator == numbers) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed >= '0' && keyPressed <= '9' && sizeOfString < charactersAmount) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            sizeOfString--;
            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atoi(numbers);
}

double Input::unsignedRealNumber(const char *instructionMessage, short charactersAmount) {
    printf("%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[charactersAmount + 1]{};

    char keyPressed{};
    char *iterator{numbers};
    int sizeOfString{};
    bool hasEnteredADot{false};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0') {
        if (keyPressed == '.' && iterator != numbers && !hasEnteredADot) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

            hasEnteredADot = true;

        } else if (keyPressed >= '0' && keyPressed <= '9' && sizeOfString < charactersAmount) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            sizeOfString--;
            iterator--;

            if (*iterator == '.') {
                hasEnteredADot = false;
            }

            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atof(numbers);
}

double Input::realNumber(const char* instructionMessage, short charactersAmount) {
    printf("%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[charactersAmount + 1]{};

    char keyPressed{};
    char *iterator{numbers};
    int sizeOfString{};
    bool hasEnteredADot{false};

    /* 
        NO saldra del bucle a menos que:
        - Presione Enter
        - Ingrese numeros con o sin decimales
        - Ingrese signo negativo pero seguido de la parte entera
     */
    while ((keyPressed = getch()) != ENTER_KEY
        || *numbers == '\0'
        || (*numbers == '-' && (*(numbers + 1) == '\0' || *(numbers + 1) == '.'))) {

        if (keyPressed == '-' && iterator == numbers) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == '.' && iterator != numbers && !hasEnteredADot) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

            hasEnteredADot = true;

        } else if (keyPressed >= '0' && keyPressed <= '9' && sizeOfString < charactersAmount) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            sizeOfString--;
            iterator--;

            if (*iterator == '.') {
                hasEnteredADot = false;
            }

            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atof(numbers);
}

char *Input::alphabetic(const char *instructionMessage, short charactersAmount) {
    printf("%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};
    const char SPACE_KEY{32};

    char *string = new char[charactersAmount + 1]{};

    char keyPressed{};
    char *iterator{string};
    int sizeOfString{};

    while ((keyPressed = getch()) != ENTER_KEY || *string == '\0') {

        if (keyPressed == SPACE_KEY && iterator != string && sizeOfString < charactersAmount) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (((keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z'))
             && sizeOfString < charactersAmount) {

            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != string) {
            printf("\b \b");

            sizeOfString--;
            iterator--;
            *iterator = '\0';
        }
    }

    // Limpiando espacios en blanco despues del ultimo caracter alfabetico
    if (*(iterator - 1) == SPACE_KEY) {
        iterator--;
        while (*iterator == SPACE_KEY) {
            *iterator = '\0';
            iterator--;
        }
    }

    printf("\n");

    return string;
}

int Input::unsignedIntegerNumber(const char *instructionMessage, short charactersAmount, short textColor) {
    setTextColor(textColor);

    int value{unsignedIntegerNumber(instructionMessage, charactersAmount)};

    setTextColor(GREY);

    return value;
}

int Input::integerNumber(const char *instructionMessage, short charactersAmount, short textColor) {
    setTextColor(textColor);

    int value{integerNumber(instructionMessage, charactersAmount)};

    setTextColor(GREY);

    return value;
}

double Input::unsignedRealNumber(const char *instructionMessage, short charactersAmount, short textColor) {
    setTextColor(textColor);

    double value{unsignedRealNumber(instructionMessage, charactersAmount)};

    setTextColor(GREY);

    return value;
}

double Input::realNumber(const char *instructionMessage, short charactersAmount, short textColor) {
    setTextColor(textColor);

    double value{realNumber(instructionMessage, charactersAmount)};

    setTextColor(GREY);

    return value;
}

char *Input::alphabetic(const char *instructionMessage, short charactersAmount, short textColor) {
    setTextColor(textColor);

    char *string{alphabetic(instructionMessage, charactersAmount)};

    setTextColor(GREY);

    return string;
}