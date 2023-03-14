#include "../header/SwapCard.hpp"

#include "../../Cards/header/Card.hpp"
#include "../../InventoryHolder/header/DeckCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../Player/header/Player.hpp"
#include "../../GameState/header/GameState.hpp"

SwapCard::SwapCard() 
{
    this->abilityCard = "SwapCard";
}

void SwapCard::useAbilityCard()
{
    cout << "Using ability Card: " << this->abilityCard << endl;
    setAbilityCard(ABILITYCARD_DEFAULT);
}

void SwapCard::useAbilityCard(Card& Card1, Card& Card2)
{
    Card tempCard(Card1);
    Card1 = Card2;
    Card2 = tempCard;
}