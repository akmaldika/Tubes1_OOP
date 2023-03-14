#include "header/Quadruple.hpp"

#include "../Cards/header/Card.hpp"
#include "../InventoryHolder/header/DeckCard.hpp"
#include "../InventoryHolder/header/PlayerCard.hpp"
#include "../Player/header/Player.hpp"
#include "../GameState/header/GameState.hpp"

Quadruple::Quadruple() 
{
    this->abilityCard = "Quadruple";
}

void Quadruple::useAbilityCard()
{
    cout << "Using ability Card: " << this->abilityCard << endl;
    setAbilityCard(ABILITYCARD_DEFAULT);
}

void Quadruple::useAbilityCard(GameState& gameState)
{
    useAbilityCard();
    gameState.setPrize(gameState.getPrize() * 4);
}