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
 
        /* 
        Menggunakan SwapCard Card, setelahnya ability set ABILITYCARD_DEFAULT 
        jika isKiri1 true maka Player 1 akan mengambil kartu kiri dari palyer 2
        jika isKiri2 true maka Player 2 akan mengambil kartu kiri dari palyer 1
        jika false maka ambil kartu kanan
        */
        void useAbilityCard(Player&, const bool& isKiri1, Player&, const bool& isKiri2);
        void printAbilityCard();
};

#endif