// File : Abilityless.hpp

#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "Ability.hpp"

using namespace std;

class Abilityless : public Ability 
{
    public:
        // Constructor Default
        // ability = "Abilityless"
        Abilityless();

        // Method

        // Method
        // menggunakan Ability jenis kartu Abilityless set to Default
        void useAbility(string&);
        
        void useAbility();
        void useAbility(int&);
        void useAbility(vector<Player>&);
        void useAbility(pair<Card,Card>&, pair<Card,Card>);
        void useAbility(pair<Card,Card>&, Card, Card);
        void useAbility(Card&, Card&);

};

#endif