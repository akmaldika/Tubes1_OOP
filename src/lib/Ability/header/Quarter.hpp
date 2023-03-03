// File : Quarter.hpp

#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "Ability.hpp"

using namespace std;

class Quarter : public Ability 
{
    public:
        // Constructor Default
        // ability = "Quarter"
        Quarter();

        // Method

        // Method
        // menggunakan Ability jenis kartu Quarter
        void useAbility(int&);
        void useAbility(string&);
        void useAbility();
        void useAbility(vector<Player>&);
        void useAbility(pair<Card,Card>&, pair<Card,Card>);
        void useAbility(pair<Card,Card>&, Card, Card);
        void useAbility(Card&, Card&);        
};

#endif