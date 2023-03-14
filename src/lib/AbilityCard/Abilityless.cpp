#include "header/Abilityless.hpp"

#include "../Cards/header/Card.hpp"
#include "../InventoryHolder/header/DeckCard.hpp"
#include "../InventoryHolder/header/PlayerCard.hpp"
#include "../Player/header/Player.hpp"
#include "../GameState/header/GameState.hpp"

Abilityless::Abilityless() 
{
    this->abilityCard = "Abilityless";
}

void Abilityless::useAbilityCard()
{
    cout << "Using ability Card: " << this->abilityCard << endl;
    setAbilityCard(ABILITYCARD_DEFAULT);
}

void Abilityless::useAbilityCard(Player& player)
{
    useAbilityCard();
    player.getAbility()->setAbilityCard(ABILITYCARD_DEFAULT);
}