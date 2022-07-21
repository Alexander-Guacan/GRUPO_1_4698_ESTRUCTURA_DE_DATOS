#ifndef INPUT_HPP
#define INPUT_HPP

#include <windows.h>
#include <string>

class Input {
    private:
        COORD cursorPosition{};
        SHORT xInitialPosition{};

        void printKey(char input);
        void eraseCharacter();
        void printEndLine();

    public:

        /**
         * @brief Construct a new Input object
         * 
         */
        Input();

        /**
         * @brief Construct a new Input object, use this constructor when other process use output stream at the same time
         * 
         * @param xPosition 
         * @param yPosition 
         */
        Input(SHORT xPosition, SHORT yPosition);

        /**
         * @brief Set the new cursor position that work when use the input functions
         * 
         * @param coordinate Example: {12, 5}
         */
        void updateCursorPosition(COORD coordinate);

        /**
         * @brief Set the new cursor position that work when use the input functions
         * 
         * @param x 
         * @param y 
         */
        void updateCursorPosition(SHORT x, SHORT y);

        /**
         * @brief Input only positive integer numbers until 9 digits
         * 
         * @param minimumDigits The user will not be able to continue if the number entered does not have the minimum number of digits established. (0 - 9)
         * @param maximumDigits The user will not be able to enter more numbers when the limit is reached. (0 - 9)
         * @return unsigned int 
         */
        unsigned int unsignedIntegerNumber(short minimumDigits, short maximumDigits);
        
        /**
         * @brief Input only positive real numbers until 14 digits, decimal numbers will count as one more digit
         * 
         * @param minimumDigits The user will not be able to continue if the number entered does not have the minimum number of digits established. (0 - 9)
         * @param maximumDigits The user will not be able to enter more numbers when the limit is reached. (0 - 9)
         * @return double 
         */
        double unsignedRealNumber(short minimumDigits, short maximumDigits);
        
        /**
         * @brief Input integer numbers until 9 digits
         * 
         * @param minimumDigits The user will not be able to continue if the number entered does not have the minimum number of digits established. (0 - 9)
         * @param maximumDigits The user will not be able to enter more numbers when the limit is reached. (0 - 9)
         * @return int 
         */
        int integerNumber(short minimumDigits, short maximumDigits);
        
        /**
         * @brief Input real numbers until 14 digits, decimal numbers will count as one more digit
         * 
         * @param minimumDigits The user will not be able to continue if the number entered does not have the minimum number of digits established. (0 - 9)
         * @param maximumDigits The user will not be able to enter more numbers when the limit is reached. (0 - 9)
         * @return double 
         */
        double realNumber(short minimumDigits, short maximumDigits);
        
        /**
         * @brief Input alphabetic characters, but the space key don't work
         * 
         * @param minimumCharacters > 0
         * @param maximumCharacters without limits
         * @return std::string 
         */
        std::string word(short minimumCharacters, short maximumCharacters);
        
        /**
         * @brief Input numeric characters, util for strings of more 9 digits
         * 
         * @param minimumDigits > 0
         * @param maximumDigits without limits
         * @return std::string 
         */
        std::string digits(short minimumDigits, short maximumDigits);
        
        /**
         * @brief Input alphabetic characters, including the space key
         * 
         * @param minimumLetters > 0
         * @param maximumLetters without limits
         * @return std::string 
         */
        std::string alphabetic(short minimumLetters, short maximumLetters);
        
        /**
         * @brief Input alphabetic and numeric characters, including the space key
         * 
         * @param minimumCharacters > 0
         * @param maximumCharacters without limits
         * @return std::string 
         */
        std::string alphanumeric(short minimumCharacters, short maximumCharacters);
};

#endif