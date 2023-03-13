// File : Abilityless.hpp

#ifndef ABILITYLESS_HPP
#define ABILITYLESS_HPP

#include "AbilityCard.hpp"

class Abilityless : public AbilityCard
{
    public :
        // Constructor Default
        // ability = "Abilityless"
        Abilityless();

        // Method
        
        // Menggunakan Abilityless Card, setelahnya ability set ABILITYCARD_DEFAULT
        void useAbilityCard();
};

#endif