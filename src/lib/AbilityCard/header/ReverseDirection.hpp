// File : ReverseDirection.hpp

#ifndef REVERSEDIRECTION_HPP
#define REVERSEDIRECTION_HPP

#include "AbilityCard.hpp"

class ReverseDirection : public AbilityCard
{
    public:
        // Constructor Default
        // ability = "ReverseDirection"
        ReverseDirection();

        // Method

        /* 
        Menggunakan ReverseDirection Card, setelahnya ability set ABILITYCARD_DEFAULT
        membalikan boolean reverse pada GameState
        */
        void useAbilityCard(bool&);
        void printAbilityCard();
};

#endif