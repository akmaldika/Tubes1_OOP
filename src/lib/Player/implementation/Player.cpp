#include "../header/Player.hpp"
#include <iostream>
using namespace std;

int Player::playerCount = 0;

// construktor
Player::Player(Card card1, Card card2)
{  
    this->ID = (playerCount%7)+1;
    this->name = "NaN";
    this->point = 0;   
    playerCount++;
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
void Player::setPlayerID(int ID){
    this->ID = ID;
}
int Player::getPlayerID(){
    return ID;
}
Card getCardOne();
void addCardTwo(Card card2);
Card getCardTwo();
void Player::status() const{
    cout << "Status Player" << endl;
    cout << "ID : " << this->ID << endl;
    cout << "Nama : " << this->name << endl;
    cout << "Point : " << this->point << endl;
    // cout << "Kartu 1 : " << (this->MyCard)->getFirstPlayerCard().getAbility() << endl;
    // cout << "Kartu 2 : " << (this->MyCard)->getSecondPlayerCard().getAbility() << endl;
    cout << endl;
}
void Player::setPlayed(bool played){
    this->played = played;
}

bool Player::getPlayed(){
    return played;
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