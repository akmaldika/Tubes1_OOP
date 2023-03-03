#include "../header/Quadruple.hpp"


Quadruple::Quadruple()
{
    this->ability = "Quadruple";
}

void Quadruple::useAbility(int& score)
{
    score *= 4;
}