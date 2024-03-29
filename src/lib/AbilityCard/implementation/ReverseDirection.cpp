#include "../header/ReverseDirection.hpp"

#include "../../Cards/header/Card.hpp"
#include "../../InventoryHolder/header/DeckCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../Player/header/Player.hpp"
#include "../../GameState/header/GameState.hpp"

ReverseDirection::ReverseDirection() 
{
    this->abilityCard = "ReverseDirection";
}

void ReverseDirection::useAbilityCard(bool& reverse)
{
    AbilityCard::useAbilityCard();
    reverse = !reverse;
}

void ReverseDirection::printAbilityCard(){
    cout<<".---------."<<endl;
    cout<<"|Reverse  |"<<endl;
    cout<<"|  .---.  |"<<endl;
    cout<<"|  : A :  |"<<endl;
    cout<<"|  '---'  |"<<endl;
    cout<<"|  Reverse|"<<endl;
    cout<<"`---------'"<<endl;
}