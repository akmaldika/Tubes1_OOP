#include "../header/Abilityless.hpp"

Abilityless::Abilityless()
{
    this->ability = "Abilityless";
}


void Abilityless::useAbility(string& ability)
{
    setAbilityOff();
    ability = this->ABILITY_DEFAULT;
}
    