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

        // Setter
        // Set Ability menjadi "Reroll"
        void setAbility();

        // Method
        // menggunakan Ability jenis kartu Reroll
        void useAbility(pair<Card,Card>&);
};

#endif