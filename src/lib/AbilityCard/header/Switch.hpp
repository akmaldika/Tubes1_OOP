// File : Switch.hpp

#ifndef SWITCH_HPP
#define SWITCH_HPP

#include "AbilityCard.hpp"

class Switch : public AbilityCard
{
    public:
        // Constructor Default
        // ability = "Switch"
        Switch();

        // Method

        // Menggunakan Switch Card, setelahnya ability set ABILITYCARD_DEFAULT
        void useAbilityCard(Player&, Player&);
        void printAbilityCard();
};

#endif