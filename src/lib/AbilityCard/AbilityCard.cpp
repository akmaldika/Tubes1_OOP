#include "header/AbilityCard.hpp"
#include "../Cards/header/Card.hpp"
#include "../InventoryHolder/header/DeckCard.hpp"
#include "../InventoryHolder/header/PlayerCard.hpp"
#include "../Player/header/Player.hpp"
#include "../GameState/header/GameState.hpp"

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
    setAbilityCard(ABILITYCARD_DEFAULT);
}