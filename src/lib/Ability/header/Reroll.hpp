// File : Reroll.hpp

#ifndef REROLL_HPP
#define REROLL_HPP

#include "Ability.hpp"

using namespace std;

class Reroll : public Ability 
{
    public:
        // Constructor Default
        // ability = "Reroll"
        Reroll();

        // Method

        // Method
        // menggunakan Ability jenis kartu Reroll
        // PlayerCard& = kartu player yang memiliki Reroll
        // PlayerCard& = pair<Card,Card>
        void useAbility(pair<Card,Card>&, pair<Card,Card>);
        // Overload
        void useAbility(pair<Card,Card>&, Card, Card);

        void useAbility(int&);
        void useAbility(string&);
        void useAbility();
        void useAbility(vector<Player>&);
        void useAbility(Card&, Card&);
};

#endif