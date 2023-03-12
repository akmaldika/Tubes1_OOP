#include "Player.hpp"
#include <iostream>
using namespace std;

int Player::playerCount = 0;

// construktor
Player::Player(Card card1, Card card2, Card abilityCard) 
: MyCard(card1, card2, abilityCard, playerCount+1)   
{  
    playerCount++;

    ID = playerCount;
    name = "NaN";
    point = 0;
    
}
void Player::setPlayerName(string name){
    this->name = name;
}
string Player::getPlayerName(){
    return name;
}
void Player::setPlayerPoint(int p){
    this->point = p;
}
int Player::getPlayerPoint(){
    return point;
}



template <class T>
T highestCombination(int card){
    
}