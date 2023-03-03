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

        // Setter
        // Set Ability menjadi "Abilityless"
        void setAbility();

        // Method
        // menggunakan Ability jenis kartu Abilityless set to Default
        void useAbility(string&);
};

#endif