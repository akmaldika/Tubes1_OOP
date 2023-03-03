// File : ReverseDirection.hpp

#ifndef REVERSEDIRECTION_HPP
#define REVERSEDIRECTION_HPP

#include "Ability.hpp"

using namespace std;

class ReverseDirection : public Ability 
{
    public:
        // Constructor Default
        // ability = "ReverseDirection"
        ReverseDirection();

        // Method
        // menggunakan Ability jenis kartu ReverseDirection
        // Urutan pemain menjadi terbalik
        void useAbility(vector<Player>&);

        void useAbility(int&);
        void useAbility(string&);
        void useAbility();
        void useAbility(pair<Card,Card>&, pair<Card,Card>);
        void useAbility(pair<Card,Card>&, Card, Card);
        void useAbility(Card&, Card&);
};

#endif