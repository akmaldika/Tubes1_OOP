#ifndef COMBO_HPP
#define COMBO_HPP

#include "Valuable.hpp"
#include "Card.hpp"
#include <vector>
#include <map>

class Combo: public Valuable{
    private:
        vector<Card> combination;
        string type;
        static map<string, double> threshold;

    public:
        Combo(vector<Card> combination);
        void setCombinationType();
        double value();
};



#endif
