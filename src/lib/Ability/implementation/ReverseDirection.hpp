#include "../header/ReverseDirection.hpp"

ReverseDirection::ReverseDirection()
{
    this->ability = "ReverseDirection";
}

void ReverseDirection::useAbility(vector<Player>& urutanPlayer)
{
    reverse(urutanPlayer.begin(), urutanPlayer.end());
}

