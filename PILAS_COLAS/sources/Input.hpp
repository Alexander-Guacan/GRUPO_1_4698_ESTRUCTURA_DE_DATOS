#ifndef INPUT_HPP
#define INPUT_HPP

class Input {
    private:

    public:
        
        static char *numbers(const char *instructionMessage, short minimumDigits, short maximumDigits);        
        static int unsignedIntegerNumber(const char *instructionMessage, short minimumDigits, short maximumDigits);        
        static int integerNumber(const char *instructionMessage, short minimumDigits, short maximumDigits);        
        static double unsignedRealNumber(const char *instructionMessage, short minimumDigits, short maximumDigits);        
        static double realNumber(const char *instructionMessage, short minimumDigits, short maximumDigits);        
        static char *oneWord(const char *instructionMessage, short minimumDigits, short maximumDigits);        
        static char *alphabetic(const char *instructionMessage, short minimumCharacters, short maximumCharacters);
};

#endif