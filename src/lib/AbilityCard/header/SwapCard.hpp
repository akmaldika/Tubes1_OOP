// File : SwapCard.hpp

#ifndef SWAPCARD_HPP
#define SWAPCARD_HPP

#include "AbilityCard.hpp"

class SwapCard : public AbilityCard
{
    public:
        // Constructor Default
        // ability = "SwapCard"
        SwapCard();

        // Method
 
        // Menggunakan SwapCard Card, setelahnya ability set ABILITYCARD_DEFAULT
        void useAbilityCard();
        void useAbilityCard(Card&, Card&);
};

#endif