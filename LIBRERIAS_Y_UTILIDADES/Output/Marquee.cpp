#include "Marquee.hpp"
#include "HandleConsole.hpp"
#include <iostream>
#include <conio.h>

void Marquee::renderMarquee(SHORT x) {
    HandleConsole::setCursorPosition(x, this->yHight);
    std::cout << this->message;
}

void Marquee::renderMarquee(const std::string &substring, SHORT x) {
    HandleConsole::setCursorPosition(x, this->yHight);
    std::cout << substring;
}

void Marquee::clearMarquee(SHORT xActualPosition) {
    HandleConsole::setCursorPosition(xActualPosition - 1, this->yHight);
    std::cout << ' ';
}

Marquee::Marquee(const std::string &initialMessage, size_t initialXLimitleft, size_t initialXLimitRight) {
    this->message = initialMessage;
    this->xLimitLeft = initialXLimitleft;
    this->xLimitRight = initialXLimitRight;
    this->setVelocity(this->DEFAULT_VELOCITY);
}

void Marquee::setPosition(SHORT y) {
    this->yHight = y;
}

void Marquee::setVelocity(short newVelocity) {
    const short MINIMUM_TIME_IN_MILISECONDS{10};
    const short MAXIMUM_TIME_IN_MILISECONDS{1000};
    const short MINIMUM_WAIT_TIME_FOR_NEXT_INSTRUCTION{MINIMUM_TIME_IN_MILISECONDS};
    const short MAXIMUM_WAIT_TIME_FOR_NEXT_INSTRUCTION{MAXIMUM_TIME_IN_MILISECONDS};
    const short MINIMUM_SPEED{0};
    const short MAXIMUM_SPEED{10};
    const short SLOPE{(MAXIMUM_WAIT_TIME_FOR_NEXT_INSTRUCTION - MINIMUM_WAIT_TIME_FOR_NEXT_INSTRUCTION) / (MINIMUM_SPEED - MAXIMUM_SPEED)};

    if (newVelocity < 0 || newVelocity > 10)
        newVelocity = this->DEFAULT_VELOCITY;

    this->velocity = SLOPE * newVelocity + MAXIMUM_WAIT_TIME_FOR_NEXT_INSTRUCTION;
}

void Marquee::print() {
    HandleConsole::setCursorVisibilitie(false);

    for (size_t i{1}; i < this->message.length(); i++) {
        HandleConsole::setCursorPosition(this->xLimitLeft, this->yHight);
        std::cout << std::string(this->message, this->message.length() - i, this->message.length() - (this->message.length() - i));
        Sleep(this->velocity);
    }

    size_t x{this->xLimitLeft};
    while (true) {
        
        if (x < this->xLimitRight - this->message.length()) {
            renderMarquee(x);

            clearMarquee(x);
        } else {

            clearMarquee(x);

            renderMarquee(std::string(this->message, 0, this->xLimitRight - x), x);

            renderMarquee(std::string(this->message, this->xLimitRight - x, this->message.length() - (this->xLimitRight - x)), this->xLimitLeft);
        }

        Sleep(this->velocity);
        x++;

        if (x > this->xLimitRight)
            x = this->xLimitLeft;

        if (kbhit()) {
            const int ESCAPE_KEY{27};
            if (getch() == ESCAPE_KEY)
                break;
        }
    }

    HandleConsole::setCursorVisibilitie(true);
}