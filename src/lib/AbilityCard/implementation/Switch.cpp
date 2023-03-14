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
void Switch::useAbilityCard(Player& player1, Player& player2)
{
    AbilityCard::useAbilityCard();
    PlayerCard tempPlayerCard(playerCard1);
    pair<int,int> a;
    a.swap(a);

}