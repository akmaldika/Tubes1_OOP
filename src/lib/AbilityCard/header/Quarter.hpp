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

        // Menggunakan Quarter Card, setelahnya ability set ABILITYCARD_DEFAULT
        void useAbilityCard(GameState&);
};

#endif