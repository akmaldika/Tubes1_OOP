#include "../header/Reroll.hpp"

Reroll::Reroll()
{
    this->ability = "Reroll";
}

void Reroll::useAbility(pair<Card,Card>& player, pair<Card,Card> card)
{
    setAbilityOff();
    player = card;
}

void Reroll::useAbility(pair<Card,Card>& player, Card first, Card second)
{
    setAbilityOff();
    player.first = first;
    player.second = second;
}