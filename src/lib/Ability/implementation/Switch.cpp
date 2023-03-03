#include "../header/Switch.hpp"

Switch::Switch()
{
    this->ability = "Switch";
}

void Switch::useAbility(Card& playerLain1, Card& playerLain2)
{
    setAbilityOff();
    Card temp = playerLain1;
    playerLain1 = playerLain2;
    playerLain2 = temp;
}