#include "../header/Switch.hpp"

#include "../../Cards/header/Card.hpp"
#include "../../InventoryHolder/header/DeckCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../Player/header/Player.hpp"
#include "../../GameState/header/GameState.hpp"

using namespace std;

// Card tempCard1, tempCard2;

// pair<Card*,Card*> Switch::tempPlayerCard(nullptr,nullptr);

Switch::Switch() 
{
    this->abilityCard = "Switch";
}

void Switch::useAbilityCard(Player& player1, Player& player2, const Player _player1)
{
    AbilityCard::useAbilityCard();
    // pair<Card*,Card*> tempPlayerCard;
    // tempPlayerCard.first  = &player1.getCardOne(); 
    // tempPlayerCard.second = &player1.getCardTwo();
    player1.setCardOne(player2.getCardOne());
    player1.setCardTwo(player2.getCardTwo());
    player2.setCardOne(_player1.getMyCard().getFirstPlayerCard());
    player2.setCardTwo(_player1.getMyCard().getSecondPlayerCard());
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