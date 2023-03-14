#include "header/Quarter.hpp"

#include "../Cards/header/Card.hpp"
#include "../InventoryHolder/header/DeckCard.hpp"
#include "../InventoryHolder/header/PlayerCard.hpp"
#include "../Player/header/Player.hpp"
#include "../GameState/header/GameState.hpp"

Quarter::Quarter() 
{
    this->abilityCard = "Quarter";
}

void Quarter::useAbilityCard()
{
    cout << "Using ability Card: " << this->abilityCard << endl;
    setAbilityCard(ABILITYCARD_DEFAULT);
}

void Quarter::useAbilityCard(GameState& GameState)
{
    useAbilityCard();
    GameState.setPrize(GameState.getPrize() / 4);
}