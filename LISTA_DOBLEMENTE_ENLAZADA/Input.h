#ifndef INPUT_H
#define INPUT_H

class Input {
    
    public:
        int integerNumber(const char *instructionMessage, int charAmount);
        double realNumber(const char *instructionMessage, int charAmount);
        char *letters(const char *instructionMessage, int charAmount);
};

#endif