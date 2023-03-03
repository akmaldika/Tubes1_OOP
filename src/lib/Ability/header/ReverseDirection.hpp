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

        // Setter
        // Set Ability menjadi "ReverseDirection"
        void setAbility();

        // Method
        // menggunakan Ability jenis kartu ReverseDirection
        void useAbility();
};

#endif