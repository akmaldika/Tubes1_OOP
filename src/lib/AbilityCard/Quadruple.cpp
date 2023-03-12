#include "header/Quadruple.hpp"

Quadruple::Quadruple() 
{
    this->abilityCard = "Quadruple";
}

void Quadruple::useAbilityCard()
{
    cout << "Using ability Card: " << this->abilityCard << endl;
    setAbilityCard(ABILITYCARD_DEFAULT);
}