#include "Input.h"
#include <iostream>
#include <conio.h>

int Input::integerNumber(const char *instructionMessage) {
    printf("\n%s", instructionMessage);

    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[11]{};
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