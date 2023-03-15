#include "../header/Abilityless.hpp"

#include "../../Cards/header/Card.hpp"
#include "../../InventoryHolder/header/DeckCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../Player/header/Player.hpp"
#include "../../GameState/header/GameState.hpp"

Abilityless::Abilityless() 
{
    this->abilityCard = "Abilityless";
}

void Abilityless::useAbilityCard(Player& player)
{
    AbilityCard::useAbilityCard();
    AbilityCard* ability = player.getAbility();
    ability->setOffAbilityCard();
    player.setAbility(ability);
}