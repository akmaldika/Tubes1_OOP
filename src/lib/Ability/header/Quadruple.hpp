// File : Quadruple.hpp

#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include "Ability.hpp"

using namespace std;

class Quadruple : public Ability 
{
    public:
        // Constructor Default
        // ability = "Quadruple"
        Quadruple();

        // Method

        // Method
        // menggunakan Ability jenis kartu Quadruple
        void useAbility(int&);
        void useAbility(string&);
        void useAbility();
        void useAbility(vector<Player>&);
        void useAbility(pair<Card,Card>&, pair<Card,Card>);
        void useAbility(pair<Card,Card>&, Card, Card);
        void useAbility(Card&, Card&);
};

#endif