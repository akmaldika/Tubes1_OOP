// File : SwapCard.hpp

#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "Ability.hpp"

using namespace std;

class SwapCard : public Ability 
{
    public:
        // Constructor Default
        // ability = "SwapCard"
        SwapCard();

        // Method

        // Method
        // menggunakan Ability jenis kartu SwapCard
        
        void useAbility(Card&, Card&);

        void useAbility(int&);
        void useAbility(string&);
        void useAbility();
        void useAbility(vector<Player>&);
        void useAbility(pair<Card,Card>&, pair<Card,Card>);
        void useAbility(pair<Card,Card>&, Card, Card);
};

#endif