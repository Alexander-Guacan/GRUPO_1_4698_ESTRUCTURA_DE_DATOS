#include "Input.hpp"
#include "HandleConsole.hpp"
#include <iostream>
#include <conio.h>

void Input::printKey(char input) {
    if (this->cursorPosition.X != -1) {
        HandleConsole::setCursorPosition(this->cursorPosition.X, this->cursorPosition.Y);
        this->cursorPosition.X++;
    }

    printf("%c", input);
}

void Input::eraseCharacter() {
    if (this->cursorPosition.X != -1) {
        HandleConsole::setCursorPosition(this->cursorPosition.X, this->cursorPosition.Y);
        this->cursorPosition.X--;
    }

    printf("\b \b");
}

void Input::printEndLine() {
    if (this->cursorPosition.X != -1) {
        HandleConsole::setCursorPosition(this->cursorPosition.X, this->cursorPosition.Y);
        this->cursorPosition.X = this->xInitialPosition;
        this->cursorPosition.Y++;
        HandleConsole::setCursorPosition(this->cursorPosition.X, this->cursorPosition.Y);
    } else {
        printf("\n");
    }

}

Input::Input() {
    this->cursorPosition.X = -1;
    this->cursorPosition.Y = -1;
}

Input::Input(SHORT xPosition, SHORT yPosition) {
    this->cursorPosition.X = xPosition;
    this->cursorPosition.Y = yPosition;
    this->xInitialPosition = this->cursorPosition.X;
}

void Input::updateCursorPosition(COORD coordinates) { this->cursorPosition = coordinates; }

void Input::updateCursorPosition(SHORT x, SHORT y) {
    this->cursorPosition.X = x;
    this->cursorPosition.Y = y;
}

unsigned int Input::unsignedIntegerNumber(short minimumDigits, short maximumDigits) {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 1]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {
        if (std::isdigit(keyPressed) && digitsAmount < maximumDigits) {
            printKey(keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            eraseCharacter();

            digitsAmount--;
            iterator--;
            *iterator = '\0';
        }
    }

    printEndLine();

    return std::atoi(numbers);
}

double Input::unsignedRealNumber(short minimumDigits, short maximumDigits) {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 2]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};
    bool hasEnteredADot{false};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {
        if (keyPressed == '.' && iterator != numbers && !hasEnteredADot) {
            printKey(keyPressed);

            *iterator = keyPressed;
            iterator++;

            hasEnteredADot = true;

        } else if (std::isdigit(keyPressed) && digitsAmount < maximumDigits) {
            printKey(keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            eraseCharacter();

            iterator--;

            if (*iterator == '.') {
                hasEnteredADot = false;
            } else {
                digitsAmount--;
            }

            *iterator = '\0';
        }
    }

    printEndLine();

    return std::atof(numbers);
}

int Input::integerNumber(short minimumDigits, short maximumDigits) {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 2]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {
        if (keyPressed == '-' && iterator == numbers) {
            printKey(keyPressed);

            *iterator = keyPressed;
            iterator++;

        } else if (std::isdigit(keyPressed) && digitsAmount < maximumDigits) {
            printKey(keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            eraseCharacter();

            iterator--;
            
            if (*iterator != '-')
                digitsAmount--;

            *iterator = '\0';
        }
    }

    printEndLine();

    return std::atoi(numbers);
}

double Input::realNumber(short minimumDigits, short maximumDigits) {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 3]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};
    bool hasEnteredADot{false};

    
    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {

        if (keyPressed == '-' && iterator == numbers) {
            printKey(keyPressed);

            *iterator = keyPressed;
            iterator++;

        } else if (keyPressed == '.' && iterator != numbers && !hasEnteredADot) {
            printKey(keyPressed);

            *iterator = keyPressed;
            iterator++;

            hasEnteredADot = true;

        } else if (std::isdigit(keyPressed) && digitsAmount < maximumDigits) {
            printKey(keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            eraseCharacter();

            iterator--;
            
            if (*iterator == '.') {
                hasEnteredADot = false;
            } else if (*iterator != '-') {
                digitsAmount--;
            }


            *iterator = '\0';
        }
    }

    printEndLine();

    return std::atof(numbers);
}

std::string Input::word(short minimumCharacters, short maximumCharacters) {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *string = new char[maximumCharacters + 1]{};

    char keyPressed{};
    char *iterator{string};
    int sizeOfString{};

    while ((keyPressed = getch()) != ENTER_KEY || *string == '\0' || sizeOfString < minimumCharacters) {

        if (std::isalpha(keyPressed) && sizeOfString < maximumCharacters) {
            printKey(keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != string) {
            eraseCharacter();

            sizeOfString--;
            iterator--;
            *iterator = '\0';
        }
    }

    printEndLine();

    return string;
}

std::string Input::digits(short minimumDigits, short maximumDigits) {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};

    char *numbers = new char[maximumDigits + 1]{};

    char keyPressed{};
    char *iterator{numbers};
    int digitsAmount{};

    while ((keyPressed = getch()) != ENTER_KEY || *numbers == '\0' || digitsAmount < minimumDigits) {
        if (std::isdigit(keyPressed) && digitsAmount < maximumDigits) {
            printKey(keyPressed);

            *iterator = keyPressed;
            iterator++;
            digitsAmount++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != numbers) {
            eraseCharacter();

            digitsAmount--;
            iterator--;
            *iterator = '\0';
        }
    }

    printEndLine();

    return numbers;
}

std::string Input::alphabetic(short minimumLetters, short maximumLetters) {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};
    const char SPACE_KEY{32};

    char *string = new char[maximumLetters + 1]{};

    char keyPressed{};
    char *iterator{string};
    int sizeOfString{};

    while ((keyPressed = getch()) != ENTER_KEY || *string == '\0' || sizeOfString < minimumLetters) {

        if (keyPressed == SPACE_KEY && iterator != string && sizeOfString < maximumLetters) {
            printKey(keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (std::isalpha(keyPressed) && sizeOfString < maximumLetters) {

            printKey(keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != string) {
            eraseCharacter();

            sizeOfString--;
            iterator--;
            *iterator = '\0';
        }
    }

    // Cleaning blank spaces after last alphabetic character
    if (*(iterator - 1) == SPACE_KEY) {
        while (*(--iterator) == SPACE_KEY) {
            *iterator = '\0';
        }
    }

    printEndLine();

    return string;
}

std::string Input::alphanumeric(short minimumCharacters, short maximumCharacters) {
    const char ENTER_KEY{13};
    const char BACKSPACE_KEY{8};
    const char SPACE_KEY{32};

    char *string = new char[maximumCharacters + 1]{};

    char keyPressed{};
    char *iterator{string};
    int sizeOfString{};

    while ((keyPressed = getch()) != ENTER_KEY || *string == '\0' || sizeOfString < minimumCharacters) {

        if (keyPressed == SPACE_KEY && iterator != string && sizeOfString < maximumCharacters) {
            printKey(keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (std::isalnum(keyPressed) && sizeOfString < maximumCharacters) {

            printKey(keyPressed);

            *iterator = keyPressed;
            iterator++;
            sizeOfString++;

        } else if (keyPressed == BACKSPACE_KEY && iterator != string) {
            eraseCharacter();

            sizeOfString--;
            iterator--;
            *iterator = '\0';
        }
    }

    // Cleaning blank spaces after last alphabetic character
    if (*(iterator - 1) == SPACE_KEY) {
        while (*(--iterator) == SPACE_KEY) {
            *iterator = '\0';
        }
    }

    printEndLine();

    return string;
}