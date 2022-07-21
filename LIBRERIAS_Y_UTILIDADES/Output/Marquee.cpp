#include "Marquee.hpp"
#include "HandleConsole.hpp"
#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <conio.h>

void Marquee::renderMarquee(short x) {
    HandleConsole::setCursorPosition(x, this->verticalPosition);
    std::cout << this->message;
}

void Marquee::renderMarquee(const std::string &substring, short x) {
    HandleConsole::setCursorPosition(x, this->verticalPosition);
    std::cout << substring;
}

void Marquee::clearMarquee(short xActualPosition) {
    HandleConsole::setCursorPosition(xActualPosition - 1, this->verticalPosition);
    std::cout << ' ';
}

Marquee::Marquee(const std::string &initialMessage, short xLimitleft, short xLimitRight) {
    this->message = initialMessage;
    this->limitLeft = xLimitleft;
    this->limitRight = xLimitRight;
    this->setVelocity(this->DEFAULT_VELOCITY);
}

void Marquee::setVerticalPosition(short y) {
    this->verticalPosition = y;
}

void Marquee::setVelocity(short newVelocity) {
    const short minimumTimeInMilliseconds{100};
    const short maximumTimeInMilliseconds{1000};
    const short minimumWaitTimeFoNextInstruction{minimumTimeInMilliseconds};
    const short maximumWaitTimeForNextInstruction{maximumTimeInMilliseconds};
    // Minimum value for newVelocity variable
    const short minimumSpeed{0};
    // Maximum value for newVelocity variable
    const short maximumSpeed{10};
    const short slope{(maximumWaitTimeForNextInstruction - minimumWaitTimeFoNextInstruction) / (minimumSpeed - maximumSpeed)};

    if (newVelocity < 0 || newVelocity > 10)
        newVelocity = this->DEFAULT_VELOCITY;

    this->velocity = slope * newVelocity + maximumWaitTimeForNextInstruction;
}

void Marquee::print() {

    HandleConsole::setCursorVisibilitie(false);
    
    // Print from last until first character of the message
    for (short i{static_cast<short>(this->message.length())}; i > 0; i--) {
        HandleConsole::setCursorPosition(this->limitLeft, this->verticalPosition);
        std::cout << std::string(this->message, i, static_cast<short>(this->message.length()) - i);
        Sleep(this->velocity);
    }

    short x{this->limitLeft};
    while (true) {
        
        if (x < this->limitRight - static_cast<short>(this->message.length())) {
            renderMarquee(x);

            clearMarquee(x);
        } else {

            clearMarquee(x);

            renderMarquee(std::string(this->message, 0, this->limitRight - x), x);

            renderMarquee(std::string(this->message, this->limitRight - x, static_cast<short>(this->message.length()) - (this->limitRight - x)), this->limitLeft);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(this->velocity));
        x++;

        if (x > this->limitRight)
            x = this->limitLeft;
    }

    HandleConsole::setCursorVisibilitie(true);
}