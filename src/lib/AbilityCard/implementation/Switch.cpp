#include "../header/Switch.hpp"

#include "../../Cards/header/Card.hpp"
#include "../../InventoryHolder/header/DeckCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../Player/header/Player.hpp"
#include "../../GameState/header/GameState.hpp"

Switch::Switch() 
{
    this->abilityCard = "Switch";
}
void Switch::useAbilityCard(Player& player1, Player& player2)
{
    pair<Card,Card> tempPlayerCard(player1.getMyCard().getPlayerCard());
    AbilityCard::useAbilityCard();
    player1.setCardOne(player2.getMyCard().getFirstPlayerCard());
    player1.setCardTwo(player2.getMyCard().getSecondPlayerCard());
    player2.setCardOne(tempPlayerCard.first);
    player2.setCardTwo(tempPlayerCard.second);
}