#include "header/Quarter.hpp"

Quarter::Quarter() 
{
    this->abilityCard = "Quarter";
}

void Quarter::useAbilityCard()
{
    cout << "Using ability Card: " << this->abilityCard << endl;
    setAbilityCard(ABILITYCARD_DEFAULT);
}