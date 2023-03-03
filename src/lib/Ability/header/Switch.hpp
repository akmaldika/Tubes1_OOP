// File : Switch.hpp

#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "Ability.hpp"

using namespace std;

class Switch : public Ability 
{
    public:
        // Constructor Default
        // ability = "Switch"
        Switch();

        // Method

        // Method
        // menggunakan Ability jenis kartu Switch
        void useAbility(Card&, Card&);

        void useAbility(int&);
        void useAbility(string&);
        void useAbility();
        void useAbility(vector<Player>&);
        void useAbility(pair<Card,Card>&, pair<Card,Card>);
        void useAbility(pair<Card,Card>&, Card, Card);
};

#endif