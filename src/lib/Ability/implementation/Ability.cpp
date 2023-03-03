#include "../header/Ability.hpp"

Ability::Ability()
{
    this->ability = this->ABILITY_DEFAULT;
}

string Ability::getAbility()
{
    return this->ability;
}

void Ability::setAbilityOff()
{
    this->ability = this->ABILITY_DEFAULT;
}