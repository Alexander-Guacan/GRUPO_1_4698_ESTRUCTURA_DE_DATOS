#ifndef SMARTPHONE_HPP
#define SMARTPHONE_HPP

#include <cstring>
#include <iostream>

class Smartphone {
    char *mark{};
    char *model{};
    float price{};

    private:
        void setData();

    public:
        Smartphone();
        Smartphone(char *initialMark, char *initialModel, float initialPrice);
        char *getMark();
        char *getModel();
        float getPrice();

        bool operator==(const Smartphone &smartphoneToCompare) {
            bool equalsMark = std::strcmp(mark, smartphoneToCompare.mark) == 0;
            bool equalsModel = std::strcmp(model, smartphoneToCompare.model) == 0;

            return equalsMark && equalsModel;
        }

        friend std::ostream& operator<<(std::ostream &output, const Smartphone &smartphoneToPrint) {
            output << "\nMarca: " << smartphoneToPrint.mark
                   << "\nModelo: " << smartphoneToPrint.model
                   << "\nPrecio: " << smartphoneToPrint.price << "\n";

            return output;
        }
};

#endif