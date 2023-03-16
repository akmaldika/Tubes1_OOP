#include "../header/Quarter.hpp"

#include "../../Cards/header/Card.hpp"
#include "../../InventoryHolder/header/DeckCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../Player/header/Player.hpp"
#include "../../GameState/header/GameState.hpp"

Quarter::Quarter() 
{
    this->abilityCard = "Quarter";
}

void Quarter::useAbilityCard(unsigned long long& prize)
{
    AbilityCard::useAbilityCard();
    prize /= 4;
    if (prize <= 0) 
    {
        prize = 1;
    }
}

void Quarter::printAbilityCard(){
    cout<<".---------."<<endl;
    cout<<"|Quarter  |"<<endl;
    cout<<"|  .---.  |"<<endl;
    cout<<"|  : A :  |"<<endl;
    cout<<"|  '---'  |"<<endl;
    cout<<"|  Quarter|"<<endl;
    cout<<"`---------'"<<endl;
}