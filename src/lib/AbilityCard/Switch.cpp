#include "header/Switch.hpp"

#include "../Cards/header/Card.hpp"
#include "../InventoryHolder/header/DeckCard.hpp"
#include "../InventoryHolder/header/PlayerCard.hpp"
#include "../Player/header/Player.hpp"
#include "../GameState/header/GameState.hpp"

Switch::Switch() 
{
    this->abilityCard = "Switch";
}

void Switch::useAbilityCard()
{
    cout << "Using ability Card: " << this->abilityCard << endl;
    setAbilityCard(ABILITYCARD_DEFAULT);
}

void Switch::useAbilityCard(PlayerCard& playerCard1, PlayerCard& playerCard2)
{
    useAbilityCard();
    PlayerCard tempPlayerCard(playerCard1);
    playerCard1.setFirstPlayerCard(playerCard2.getFirstPlayerCard());
    playerCard1.setSecondPlayerCard(playerCard2.getSecondPlayerCard());
    playerCard2.setFirstPlayerCard(tempPlayerCard.getFirstPlayerCard());
    playerCard2.setSecondPlayerCard(tempPlayerCard.getSecondPlayerCard());
}