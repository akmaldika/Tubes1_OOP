#ifndef CARD_HPP
#define CARD_HPP

#include "Valuable.hpp"
#include <iostream>
using namespace std;
class Card : public Valuable {
    private:
        int valueCard;
        string color;
        string category;
        string ability;

    public: 
    // Constructor
        Card();
        Card(int value, string color); 
        Card(string ability);

    // Methods
        string getColor();
        string getCategory();
        string getAbility();
        double value();

};

#endif