#include "Input.h"
#include <iostream>
#include <conio.h>

int Input::integerNumber(const char *instructionMessage, int charAmount) {
    printf("\n%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[charAmount + 1]{};
    char *iterator{numbers};
    char keyPressed{};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0') {

        if (keyPressed >= '0' && keyPressed <= '9') {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atoi(numbers);
}

double Input::realNumber(const char *instructionMessage, int charAmount) {
    printf("\n%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[charAmount + 1]{};
    char *iterator{numbers};
    char keyPressed{};
    bool hasDot{false};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0') {

        if (keyPressed >= '0' && keyPressed <= '9') {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;
        } else if (keyPressed == '.' && !hasDot && iterator != numbers) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

            hasDot = true;
        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            printf("\b \b");

            iterator--;

            if (*iterator == '.')
                hasDot = false;

            *iterator = '\0';
        }
    }

    printf("\n");

    return std::atof(numbers);
}

char* Input::letters(const char *instructionMessage, int charAmount) {
    printf("\n%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};
    const char SPACE_KEY{32};

    char *string = new char[charAmount + 1]{};
    char *iterator{string};
    char keyPressed{};

    while ((keyPressed = getch()) != ENTER_KEY || *string == '\0') {

        if ((keyPressed >= 'a' && keyPressed <= 'z') || (keyPressed >= 'A' && keyPressed <= 'Z') || (keyPressed == SPACE_KEY && iterator != string)) {
            printf("%c", keyPressed);

            *iterator = keyPressed;
            iterator++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != string) {
            printf("\b \b");

            iterator--;
            *iterator = '\0';
        }
    }

    printf("\n");

    return string;
}