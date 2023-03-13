#include "header/Reroll.hpp"

Reroll::Reroll() 
{
    this->abilityCard = "Reroll";
}

void Reroll::useAbilityCard()
{
    cout << "Using ability Card: " << this->abilityCard << endl;
    setAbilityCard(ABILITYCARD_DEFAULT);
}