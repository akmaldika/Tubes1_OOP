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
        
        /* 
        Menggunakan Quadruple Card, setelahnya ability set ABILITYCARD_DEFAULT
        prizePoint pada GmaseState dikali 4
        */
        void useAbilityCard(unsigned long long&);
};

#endif