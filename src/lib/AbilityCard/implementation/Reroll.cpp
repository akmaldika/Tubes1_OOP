#include "../header/Reroll.hpp"

#include "../../Cards/header/Card.hpp"
#include "../../InventoryHolder/header/DeckCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../Player/header/Player.hpp"
#include "../../GameState/header/GameState.hpp"

Reroll::Reroll() 
{
    this->abilityCard = "Reroll";
}

void Reroll::useAbilityCard()
{
    cout << "Using ability Card: " << this->abilityCard << endl;
    setAbilityCard(ABILITYCARD_DEFAULT);
}

void Reroll::useAbilityCard(DeckCard& deck, Player& player)
{
    useAbilityCard();
    player.setCardOne(deck.takeCard());
    player.setCardTwo(deck.takeCard());
}