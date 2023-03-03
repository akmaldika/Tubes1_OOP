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


        // Setter
        // Set Ability menjadi "Quadruple"
        void setAbility();

        // Method
        // menggunakan Ability jenis kartu Quadruple
        void useAbility(int&);
};

#endif