#ifndef MENU_PRINCIPAL_HPP
#define MENU_PRINCIPAL_HPP

class MenuPrincipal {
    private:
        static void printTitles();
        static bool switchOption(char option);
        
    public:
        static void start();
};

#endif