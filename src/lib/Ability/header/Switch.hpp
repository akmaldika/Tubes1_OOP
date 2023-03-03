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

        // Setter
        // Set Ability menjadi "Switch"
        void setAbility();

        // Method
        // menggunakan Ability jenis kartu Switch
        void useAbility();
};

#endif