#include "header/ReverseDirection.hpp"

ReverseDirection::ReverseDirection() 
{
    this->abilityCard = "ReverseDirection";
}

void ReverseDirection::useAbilityCard()
{
    cout << "Using ability Card: " << this->abilityCard << endl;
    setAbilityCard(ABILITYCARD_DEFAULT);
}