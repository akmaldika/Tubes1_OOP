// File : Quarter.hpp

#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "Ability.hpp"

using namespace std;

class Quarter : public Ability 
{
    public:
        // Constructor Default
        // ability = "Quarter"
        Quarter();

        // Method


        // Setter
        // Set Ability menjadi "Quarter"
        void setAbility();

        // Method
        // menggunakan Ability jenis kartu Quarter
        void useAbility(int&);
};

#endif