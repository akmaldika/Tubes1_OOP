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
    Card card1(isKiri1 ? Player2.getCardOne() : Player2.getCardTwo());

    isKiri1 ? Player2.setCardOne(isKiri2 ? Player1.getCardOne() : Player1.getCardTwo()) : Player2.setCardTwo(isKiri2 ? Player1.getCardOne() : Player1.getCardTwo());

    isKiri2 ? Player1.setCardOne(card1) : Player1.setCardTwo(card1);

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