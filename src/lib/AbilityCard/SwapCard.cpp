#include "header/SwapCard.hpp"

SwapCard::SwapCard() 
{
    this->abilityCard = "SwapCard";
}

void SwapCard::useAbilityCard()
{
    cout << "Using ability Card: " << this->abilityCard << endl;
    setAbilityCard(ABILITYCARD_DEFAULT);
}