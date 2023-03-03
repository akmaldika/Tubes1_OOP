#include "../header/Abilityless.hpp"

Abilityless::Abilityless()
{
    this->ability = "Abilityless";
}

void Abilityless::setAbility()
{
    this->ability = "Abilityless";
}

void Abilityless::useAbility(string& ability)
{
    
    ability = this->ABILITY_DEFAULT;
}