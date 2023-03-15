// File : Quarter.hpp

#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "AbilityCard.hpp"

class Quarter : public AbilityCard
{
    public:
        // Constructor Default
        // ability = "Quarter"
        Quarter();

        // Method

        /* 
        Menggunakan Quarter Card, setelahnya ability set ABILITYCARD_DEFAULT
        prizePoint pada GameState dibagi 4
        */
        void useAbilityCard(unsigned long long&);
        void printAbilityCard();
};

#endif