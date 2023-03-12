#include "header/AbilityCard.hpp"

void AbilityCard::setAbilityCard(const string& abilityCard)
{
    this->abilityCard = abilityCard;
}

string AbilityCard::getAbilityCard() const
{
    return this->abilityCard;
}