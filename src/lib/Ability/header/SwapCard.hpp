// File : SwapCard.hpp

#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "Ability.hpp"

using namespace std;

class SwapCard : public Ability 
{
    public:
        // Constructor Default
        // ability = "SwapCard"
        SwapCard();

        // Method

        // Setter
        // Set Ability menjadi "SwapCard"
        void setAbility();

        // Method
        // menggunakan Ability jenis kartu SwapCard
        void useAbility();
};

#endif