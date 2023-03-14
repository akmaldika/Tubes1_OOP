#include "../header/AbilityCard.hpp"
#include "../header/Abilityless.hpp"
#include "../header/Quadruple.hpp"
#include "../header/Quarter.hpp"
#include "../header/Reroll.hpp"
#include "../header/ReverseDirection.hpp"
#include "../header/SwapCard.hpp"
#include "../header/Switch.hpp"

#include "../../Cards/header/Card.hpp"
#include "../../InventoryHolder/header/DeckCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../Player/header/Player.hpp"
#include "../../GameState/header/GameState.hpp"

using namespace std;

int main()
{

    Card a1(2, "merah");
    Card a2(3, "biru");
    pair<Card,Card> a;
    a.first = a1;
    a.second = a2;

    Card b1(4, "kuning");
    Card b2(5, "hijau");
    pair<Card,Card> b;
    b.first = b1;
    b.second = b2;

    Player player1(Card1, Card2);

    Abilityless abilityless;
    Quadruple quadruple;
    Quarter quarter;
    Reroll reroll;
    ReverseDirection reverseDirection;
    SwapCard swapCard;
    Switch _switch;

    int point(36);

    cout << "=========== Driver Game State ===========" << endl;
    abilityless.useAbilityCard(player1);

    return 0;
}