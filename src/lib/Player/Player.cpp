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
    point = p;
}
int Player::getPlayerPoint(){
    return point;
}
void Player::status() const{
    cout << "Status Player" << endl;
    cout << "ID : " << this->ID << endl;
    cout << "Nama : " << this->name << endl;
    cout << "Point : " << this->point << endl;
    cout << endl;
}
bool Player::operator>(Player& enemy){
    return (getPlayerPoint() > enemy.getPlayerPoint());
}
bool Player::operator==(Player& enemy){
    return (getPlayerPoint() == enemy.getPlayerPoint())
}
bool Player::operator<(Player& enemy){
    return (getPlayerPoint() < enemy.getPlayerPoint());
}
