#include "../header/SwapCard.hpp"

#include "../../Cards/header/Card.hpp"
#include "../../InventoryHolder/header/DeckCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../Player/header/Player.hpp"
#include "../../GameState/header/GameState.hpp"


Card* SwapCard::tempCard;

SwapCard::SwapCard() 
{
    this->abilityCard = "SwapCard";
}

void SwapCard::useAbilityCard(Player& Player1, const bool& isKiri1, Player& Player2, const bool& isKiri2)
{
    AbilityCard::useAbilityCard();

    if (isKiri1)
    {
        tempCard = &Player2.getCardOne();
    }
    else
    {
        tempCard = &Player2.getCardTwo();
    }

    if(isKiri1)
    {
        Player2.setCardOne((isKiri2 ? Player1.getCardOne() : Player1.getCardTwo()));
    }
    else
    {
        Player2.setCardTwo((isKiri2 ? Player1.getCardOne() : Player1.getCardTwo()));
    }

    if (isKiri2)
    {
        Player1.setCardOne(*tempCard);
    }
    else
    {
        Player1.setCardTwo(*tempCard);
    }
}

void SwapCard::printAbilityCard(){
    cout<<".---------."<<endl;
    cout<<"|Swap     |"<<endl;
    cout<<"|  .---.  |"<<endl;
    cout<<"|  : A :  |"<<endl;
    cout<<"|  '---'  |"<<endl;
    cout<<"|     Swap|"<<endl;
    cout<<"`---------'"<<endl;
}