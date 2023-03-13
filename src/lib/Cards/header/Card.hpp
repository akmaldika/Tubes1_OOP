#ifndef CARD_HPP
#define CARD_HPP

#include "Valuable.hpp"
#include "../../color.h"
#include <iostream>
#include <map>
using namespace std;
class Card : public Valuable {
    private:
        int valueCard;
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

        void print(Card card2);
        void print(Card card2, Card card3);
        void print(Card card2, Card card3, Card card4);
        void print(Card card2, Card card3, Card card4, Card card5);

            
};

#endif