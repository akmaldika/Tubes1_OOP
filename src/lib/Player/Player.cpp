#include "Player.hpp"
#include <iostream>
using namespace std;

int Player::playerCount = 0;

// construktor
Player::Player(Card card1, Card card2) 
: MyCard(card1, card2, NULL, (playerCount%7)+1)
{  
    ID = (playerCount%7)+1;
    name = "NaN";
    point = 0;   
    played = false;
    playerCount++;
}
void Player::setPlayerName(string name){
    this->name = name;
}
string Player::getPlayerName(){
    return name;
}
int Player::getID(){
    return ID;
}
void Player::setPlayerPoint(int p){
    point = p;
}
int Player::getPlayerPoint(){
    return point;
}

void Player::setPlayed(bool played){
    this->played = played;
}

bool Player::getPlayed(){
    return played;
}



void Player::status() const{
    cout << "Status Player" << endl;
    cout << "ID : " << this->ID << endl;
    cout << "Nama : " << this->name << endl;
    cout << "Point : " << this->point << endl;
    // cout << "Kartu 1 : " << (this->MyCard)->getFirstPlayerCard().getColor() << endl;
    // cout << "Kartu 2 : " << (this->MyCard).getSecondPlayerCard().getColor() << endl;
    cout << endl;
}
bool Player::operator>(Player& enemy){
    return (getPlayerPoint() > enemy.getPlayerPoint());
}
bool Player::operator==(Player& enemy){
    return (getPlayerPoint() == enemy.getPlayerPoint());
}
bool Player::operator<(Player& enemy){
    return (getPlayerPoint() < enemy.getPlayerPoint());
}
