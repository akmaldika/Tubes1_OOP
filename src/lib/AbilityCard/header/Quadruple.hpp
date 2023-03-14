// File : Quadruple.hpp

#ifndef QUADRUPLE_HPP
#define QUADRUPLE_HPP

#include "AbilityCard.hpp"

class Quadruple : public AbilityCard
{
    public:
        // Constructor Default
        // ability = "Quadruple"
        Quadruple();

        // Method
        
        // Menggunakan Quadruple Card, setelahnya ability set ABILITYCARD_DEFAULT
        void useAbilityCard(GameState&);
};

#endif