#include "IdVerificator.hpp"
#include <iostream>

bool IdVerificator::isValid(char *idCard) {
    int oddSum{};

    for (int i{}; i < 9; i += 2) {
        int value = (*(idCard + i) - '0') * 2;

        if (value > 9)
            value -= 9;

        oddSum += value;
    }

    int evenSum{};
    for (int i{1}; i < 8; i += 2) {
        evenSum += (*(idCard + i) - '0');
    }

    int verificationDigit = ((oddSum + evenSum) % 10 != 0) ? 10 - (oddSum + evenSum) % 10 : 0;

    return verificationDigit == (*(idCard + 9) - '0');
}