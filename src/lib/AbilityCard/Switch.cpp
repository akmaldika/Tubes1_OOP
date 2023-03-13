#include "header/Switch.hpp"

Switch::Switch() 
{
    this->abilityCard = "Switch";
}

void Switch::useAbilityCard()
{
    cout << "Using ability Card: " << this->abilityCard << endl;
    setAbilityCard(ABILITYCARD_DEFAULT);
}