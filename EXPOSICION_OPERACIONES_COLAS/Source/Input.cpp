#include "Input.hpp"
#include "IdVerificator.hpp"
#include <iostream>
#include <conio.h>

char *Input::numbers(const char *instructionMessage, short minimumDigits, short maximumDigits) {
    printf("%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 1]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {
        if (keyPressed >= '0' && keyPressed <= '9' && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            digitsAmount--;
            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return numbers;
}

int Input::unsignedIntegerNumber(const char *instructionMessage, short minimumDigits, short maximumDigits) {
    printf("%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 1]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {
        if (keyPressed >= '0' && keyPressed <= '9' && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            digitsAmount--;
            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atoi(numbers);
}

int Input::integerNumber(const char *instructionMessage, short minimumDigits, short maximumDigits) {

    printf("%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 2]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {
        if (keyPressed == '-' && iterator == numbers) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

        } else if (keyPressed >= '0' && keyPressed <= '9' && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            iterator--;
            
            if (*iterator != '-')
                digitsAmount--;

            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atoi(numbers);
}

double Input::unsignedRealNumber(const char *instructionMessage, short minimumDigits, short maximumDigits) {
    printf("%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 2]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};
    bool hasEnteredADot{false};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {
        if (keyPressed == '.' && iterator != numbers && !hasEnteredADot) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

            hasEnteredADot = true;

        } else if (keyPressed >= '0' && keyPressed <= '9' && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            iterator--;

            if (*iterator == '.') {
                hasEnteredADot = false;
            } else {
                digitsAmount--;
            }

            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atof(numbers);
}

double Input::realNumber(const char *instructionMessage, short minimumDigits, short maximumDigits) {
    printf("%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 3]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};
    bool hasEnteredADot{false};

    
    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {

        if (keyPressed == '-' && iterator == numbers) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

        } else if (keyPressed == '.' && iterator != numbers && !hasEnteredADot) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

            hasEnteredADot = true;

        } else if (keyPressed >= '0' && keyPressed <= '9' && digitsAmount < maximumDigits) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            iterator--;
            
            if (*iterator == '.') {
                hasEnteredADot = false;
            } else if (*iterator != '-') {
                digitsAmount--;
            }


            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atof(numbers);
}

char *Input::oneWord(const char *instructionMessage, short minimumCharacters, short maximumCharacters) {
    printf("%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *string = new char[maximumCharacters + 1]{};

    char keyPressed{};
    char *iterator{string};
    int sizeOfString{};

    while ((keyPressed = getch()) != ENTER_KEY || *string == '\0' || sizeOfString < minimumCharacters) {

        if (((keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z')) && sizeOfString < maximumCharacters) {
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

    printf("\n");

    return string;
}

char *Input::alphabetic(const char *instructionMessage, short minimumCharacters, short maximumCharacters) {
    printf("%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};
    const char SPACE_KEY{32};

    char *string = new char[maximumCharacters + 1]{};

    char keyPressed{};
    char *iterator{string};
    int sizeOfString{};

    while ((keyPressed = getch()) != ENTER_KEY || *string == '\0' || sizeOfString < minimumCharacters) {

        if (keyPressed == SPACE_KEY && iterator != string && sizeOfString < maximumCharacters) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (((keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z'))
             && sizeOfString < maximumCharacters) {

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
        while (*(--iterator) == SPACE_KEY) {
            *iterator = '\0';
        }
    }

    printf("\n");

    return string;
}

char *Input::identificationCard(const char *instructionMessage) {
    printf("%s", instructionMessage);

    const short MAXIMUM_DIGITS{10};
    const short MINIMUM_DIGITS{10};
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *idCard = new char[MAXIMUM_DIGITS + 1]{};
    char *iterator{idCard};
    int digitsAmount{};
    bool isIdCardValid{false};

    do {
        char keyPressed{};

        while ((keyPressed = getch()) != ENTER_KEY || *idCard == '\0' || digitsAmount < MINIMUM_DIGITS) {
            if (keyPressed >= '0' && keyPressed <= '9' && digitsAmount < MAXIMUM_DIGITS) {
                printf("%c", keyPressed);

                *iterator = keyPressed;
                iterator++;
                digitsAmount++;

            } else if (keyPressed == BACKSPACE_KEY && iterator != idCard) {
                printf("\b \b");

                digitsAmount--;
                iterator--;
                *iterator = '\0';
            }
        }

        IdVerificator verificator;

        isIdCardValid = verificator.isValid(idCard);

        if (!isIdCardValid) {
            short sizeOfMessage = printf("  [CEDULA NO VALIDA]");

            for (short i{}; i < sizeOfMessage; i++)
                printf("\b");
            
        } else {
            printf("  [CEDULA VALIDA]   ");
        }

    } while (!isIdCardValid);

    printf("\n");

    return idCard;
}