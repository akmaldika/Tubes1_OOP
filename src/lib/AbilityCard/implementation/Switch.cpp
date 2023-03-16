#include "../header/Switch.hpp"

#include "../../Cards/header/Card.hpp"
#include "../../InventoryHolder/header/DeckCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../Player/header/Player.hpp"
#include "../../GameState/header/GameState.hpp"

using namespace std;

// Card tempCard1, tempCard2;

pair<Card*,Card*> Switch::tempPlayerCard;

Switch::Switch() 
{
    this->abilityCard = "Switch";
}

void Switch::useAbilityCard(Player& player1, Player& player2)
{
    AbilityCard::useAbilityCard();
    tempPlayerCard.first  = &player1.getCardOne(); 
    tempPlayerCard.second = &player1.getCardTwo();
    player1.setCardOne(player2.getCardOne());
    player1.setCardTwo(player2.getCardTwo());
    player2.setCardOne(*tempPlayerCard.first);
    player2.setCardTwo(*tempPlayerCard.second);
}

void Switch::printAbilityCard(){
    cout<<".---------."<<endl;
    cout<<"|Switch   |"<<endl;
    cout<<"|  .---.  |"<<endl;
    cout<<"|  : A :  |"<<endl;
    cout<<"|  '---'  |"<<endl;
    cout<<"|   Switch|"<<endl;
    cout<<"`---------'"<<endl;
}