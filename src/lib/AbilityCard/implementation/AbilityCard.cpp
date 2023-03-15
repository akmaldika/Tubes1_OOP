#include "../header/AbilityCard.hpp"
#include "../../Cards/header/Card.hpp"
#include "../../InventoryHolder/header/DeckCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../Player/header/Player.hpp"
#include "../../GameState/header/GameState.hpp"

void AbilityCard::setAbilityCard(const string& abilityCard)
{
    this->abilityCard = abilityCard;
}

string AbilityCard::getAbilityCard() const
{
    return this->abilityCard;
}

void AbilityCard::useAbilityCard()
{
    // cout << "Using ability Card: " << this->abilityCard << endl;
    this->abilityCard = ABILITYCARD_DEFAULT;
}

string AbilityCard::getAbilityCardOff()
{
    return this->ABILITYCARD_DEFAULT;
}

bool AbilityCard::isAbilityOff() const
{
    return this->abilityCard == ABILITYCARD_DEFAULT;
}

bool AbilityCard::operator==(const AbilityCard& other) const
{
    return this->abilityCard == other.abilityCard;
}

void AbilityCard::printAbilityCard(){};