#include "header/Abilityless.hpp"

Abilityless::Abilityless() 
{
    this->abilityCard = "Abilityless";
}

void Abilityless::useAbilityCard()
{
    cout << "Using ability Card: " << this->abilityCard << endl;
    setAbilityCard(ABILITYCARD_DEFAULT);
}