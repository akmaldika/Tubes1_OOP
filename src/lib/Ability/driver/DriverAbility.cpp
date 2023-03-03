#include "../header/Ability.hpp"
#include "../header/Abilityless.hpp"
#include "../header/Quadruple.hpp"
#include "../header/Quadruple.hpp"
#include "../header/Quarter.hpp"
#include "../header/Reroll.hpp"
#include "../header/ReverseDirection.hpp"
#include "../header/SwapCard.hpp"
#include "../header/Switch.hpp"

using namespace std;

int main()
{
    int a = 1;
    Quadruple quad;
    quad.useAbility(a);
    cout << a << endl;
    return 0;
}