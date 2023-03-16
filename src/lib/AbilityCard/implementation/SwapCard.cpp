#include "../header/SwapCard.hpp"

#include "../../Cards/header/Card.hpp"
#include "../../InventoryHolder/header/DeckCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../Player/header/Player.hpp"
#include "../../GameState/header/GameState.hpp"

SwapCard::SwapCard() 
{
    this->abilityCard = "SwapCard";
}

void SwapCard::useAbilityCard(Player& Player1, const bool& isKiri1, Player& Player2, const bool& isKiri2)
{
    AbilityCard::useAbilityCard();
    Card card1;
    
    Player1.getMyCard().printCard();
    Player2.getMyCard().printCard();
    card1 = isKiri1 ? Player2.getMyCard().getFirstPlayerCard() : Player2.getCardTwo();
    cout << "================================= card1 " << card1.getColor() << endl;
    if(isKiri1)
    {
        Player2.setCardOne(isKiri2 ? Player1.getCardOne() : Player1.getCardTwo());
    }
    else
    {
        Player2.setCardTwo(isKiri2 ? Player1.getCardOne() : Player1.getCardTwo());
    }
    if (isKiri2)
    {
        Player1.setCardOne(card1);
    }
    else
    {
        Player1.setCardTwo(card1);
    }
    Player1.getMyCard().printCard();
    Player2.getMyCard().printCard();
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