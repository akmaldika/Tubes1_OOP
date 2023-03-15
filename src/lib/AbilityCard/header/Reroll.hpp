// File : Reroll.hpp

#ifndef REROLL_HPP
#define REROLL_HPP

#include "AbilityCard.hpp"

class Reroll : public AbilityCard
{
    public:
        // Constructor Default
        // ability = "Reroll"
        Reroll();

        // Method
        
        /*  
        Menggunakan Reroll Card, setelahnya ability set ABILITYCARD_DEFAULT
        player akan mengambil karu dari deck 2 kali
         */
        void useAbilityCard(DeckCard&, Player&);
};

#endif