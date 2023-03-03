#include "../header/SwapCard.hpp"

SwapCard::SwapCard()
{
    this->ability = "SwapCard";
}

void SwapCard::useAbility(Card& playerLain1, Card& playerLain2)
{
    setAbilityOff();
    Card temp = playerLain1;
    playerLain1 = playerLain2;
    playerLain2 = temp;
}