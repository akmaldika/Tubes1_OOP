#ifndef CARD_HPP
#define CARD_HPP

#include "StandardCard.hpp"
#include "../../color.h"
using namespace std;
class Card : public StandardCard{
    private:
        string color;
        static map<string, float> colorFactor;
    public: 
    // Constructor
        Card();
        Card(int value, string color); 

    // Methods
        string getColor();
        float value();
        float weightValue();
        static map<string, float> getColorFactor();
        bool operator>(Card& card);
        bool operator==(Card& card);
        bool operator<(Card& card);
        void print(); // Print kartu dalam bentuk kartu
        // Contoh
        // .---------.
        // |7        |
        // |  .---.  |
        // |  : Y :  |
        // |  '---'  |
        // |        7|
        // `---------'
};

#endif