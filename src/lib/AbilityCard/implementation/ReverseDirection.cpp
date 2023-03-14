#include "../header/ReverseDirection.hpp"

#include "../../Cards/header/Card.hpp"
#include "../../InventoryHolder/header/DeckCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../Player/header/Player.hpp"
#include "../../GameState/header/GameState.hpp"

ReverseDirection::ReverseDirection() 
{
    this->abilityCard = "ReverseDirection";
}

void ReverseDirection::useAbilityCard(GameState& gameState)
{
    AbilityCard::useAbilityCard();
    if (gameState.getReverse())
    {
        gameState.setReverse(false);
    }
    else
    {
        gameState.setReverse(true);
    }
}