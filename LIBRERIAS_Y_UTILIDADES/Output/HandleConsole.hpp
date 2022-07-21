#ifndef HANDLE_CONSOLE_HPP
#define HANDLE_CONSOLE_HPP

class HandleConsole {
    public:
        enum class TextColor : unsigned short {
            BLACK,
            BLUE,
            GREEN,
            CYAN,
            RED,
            MAGENTA,
            BROWN,
            GREY,
            DARK_GREY,
            DARK_BLUE,
            DARK_GREEN,
            DARK_CYAN,
            DARK_RED,
            DARK_MAGENTA,
            YELLOW,
            WHITE
        };

        /**
         * @brief Set the cursor position on native console
         * 
         * @param x horizontal coordinate: 0 - width of console, when the value is zero, the cursor will be on the left edge of the console
         * @param y vertical coordinate: 0 - hight of console, when the value is zero, the cursor will be at the top of the console
         */
        static void setCursorPosition(short x, short y);

        /**
         * @brief Set the visibilie of cursor
         * 
         * @param on true, cursor is visible
         */
        static void setCursorVisibilitie(bool on);

        /**
         * @brief Sets the color of the text without affecting what is already printed
         * 
         * @param color Example: HandleConsole::TextColor::GREY
         */
        static void setTextColor(enum HandleConsole::TextColor color);
};

#endif