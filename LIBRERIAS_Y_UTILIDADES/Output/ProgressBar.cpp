#include "ProgressBar.hpp"
#include "HandleConsole.hpp"
#include <iostream>
#include <thread>
#include <chrono>

void ProgressBar::printProgressBarIcon(short x) {
    const unsigned char progressBarIcon{254};

    if (this->useThread)
        HandleConsole::setCursorPosition(x, this->verticalPosition);

    printf("%c", progressBarIcon);
}

void ProgressBar::printProgressBarWithoutLoad() {
    HandleConsole::setCursorPosition(this->horizontalStartPosition, this->verticalPosition);
    HandleConsole::setTextColor(HandleConsole::TextColor::WHITE);
    for (short i{this->horizontalStartPosition}; i <= this->horizontalStartPosition + this->width; i++) {
        printProgressBarIcon(i);
    }

    HandleConsole::setTextColor(HandleConsole::TextColor::DARK_RED);
    const std::string messageLoading{"Loading..."};
    HandleConsole::setCursorPosition(this->horizontalStartPosition + this->width / 2 - messageLoading.size() / 2, this->verticalPosition + 2);
    std::cout << messageLoading;
}

void ProgressBar::loadProgressBar() {
    HandleConsole::setCursorPosition(this->horizontalStartPosition, this->verticalPosition);
    HandleConsole::setTextColor(HandleConsole::TextColor::GREEN);
    for (short i{this->horizontalStartPosition}; i <= this->horizontalStartPosition + this->width; i++) {
        printProgressBarIcon(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(velocity));
    }

    const std::string messageComplete{"Complete, press any key to continue"};
    HandleConsole::setCursorPosition(this->horizontalStartPosition + this->width / 2 - messageComplete.size() / 2, this->verticalPosition + 2);
    std::cout << messageComplete;
    system("pause > nul");
}

ProgressBar::ProgressBar(short xStartPosition, short widthOfProgressBar, short velocityOfRender) {
    this->horizontalStartPosition = xStartPosition;
    this->width = widthOfProgressBar;
    setVelocity(this->velocity);
}

void ProgressBar::setVerticalPosition(short y) { this->verticalPosition = y; }

void ProgressBar::setLimits(short xStartPosition, short newWidth) {
    this->horizontalStartPosition = xStartPosition;
    this->width = newWidth;
}

void ProgressBar::setVelocity(short newVelocity) {
    const short minimumTimeInMilliseconds{0};
    const short maximumTimeInMilliseconds{500};
    const short minimumWaitTimeFoNextInstruction{minimumTimeInMilliseconds};
    const short maximumWaitTimeForNextInstruction{maximumTimeInMilliseconds};
    // Minimum value for newVelocity variable
    const short minimumSpeed{1};
    // Maximum value for newVelocity variable
    const short maximumSpeed{5};
    const short slope{(maximumWaitTimeForNextInstruction - minimumWaitTimeFoNextInstruction) / (minimumSpeed - maximumSpeed)};

    if (newVelocity < minimumSpeed || newVelocity > maximumSpeed)
        newVelocity = this->DEFAUL_VELOCITY;

    this->velocity = slope * newVelocity + maximumWaitTimeForNextInstruction;
}

void ProgressBar::print() {
    HandleConsole::setCursorVisibilitie(false);

    printProgressBarWithoutLoad();
    loadProgressBar();

    HandleConsole::setCursorVisibilitie(true);
    HandleConsole::setTextColor(HandleConsole::TextColor::GREY);
}

void ProgressBar::printUsingThread() {
    this->useThread = true;
    print();
}