#include "../header/Quarter.hpp"

Quarter::Quarter()
{
    this->ability = "Quarter";
}

void Quarter::useAbility(int& score)
{
    score /= 4;
}