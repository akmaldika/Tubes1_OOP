#include "header/ReverseDirection.hpp"

#include "../Cards/header/Card.hpp"
#include "../InventoryHolder/header/DeckCard.hpp"
#include "../InventoryHolder/header/PlayerCard.hpp"
#include "../Player/header/Player.hpp"
#include "../GameState/header/GameState.hpp"

ReverseDirection::ReverseDirection() 
{
    this->abilityCard = "ReverseDirection";
}

void ReverseDirection::useAbilityCard()
{
    cout << "Using ability Card: " << this->abilityCard << endl;
    setAbilityCard(ABILITYCARD_DEFAULT);
}

void ReverseDirection::useAbilityCard(GameState& gameState)
{
    useAbilityCard();
    if (gameState.getReverse())
    {
        gameState.setReverse(false);
    }
    else
    {
        gameState.setReverse(true);
    }
}