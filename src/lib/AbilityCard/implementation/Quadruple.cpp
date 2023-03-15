#include "../header/Quadruple.hpp"

#include "../../Cards/header/Card.hpp"
#include "../../InventoryHolder/header/DeckCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../Player/header/Player.hpp"
#include "../../GameState/header/GameState.hpp"

Quadruple::Quadruple() 
{
    this->abilityCard = "Quadruple";
}

void Quadruple::useAbilityCard(unsigned long long& prize)
{
    AbilityCard::useAbilityCard();
    prize *= 4;
}

void Quadruple::printAbilityCard(){
    cout<<".---------."<<endl;
    cout<<"|Quadruple|"<<endl;
    cout<<"|  .---.  |"<<endl;
    cout<<"|  : A :  |"<<endl;
    cout<<"|  '---'  |"<<endl;
    cout<<"|Quadruple|"<<endl;
    cout<<"`---------'"<<endl;

}