#include "../header/Player.hpp"
#include <iostream>
using namespace std;

int Player::playerCount = 0;

// construktor
Player::Player(){
    this->ID = 0;
    this->name = "NaN";
    this->point = 0;
}
Player::Player(Card card1, Card card2) 
: MyCard(card1, card2, NULL, (playerCount%7)+1)
{  
    this->ID = (playerCount%7)+1;
    this->name = "NaN";
    this->point = 0;   
    this->played = false;
    playerCount++;
}
void Player::setPlayerName(string name){
    this->name = name;
}
string Player::getPlayerName(){
    return name;
}
void Player::setPlayerPoint(long long int p){
    this->point = p;
}
long long int Player::getPlayerPoint(){
    return point;
}
void Player::setPlayerID(int ID){
    this->ID = ID;
}
int Player::getPlayerID(){
    return ID;
}
void Player::status() const{
    cout << "Status Player" << endl;
    cout << "ID : " << this->ID << endl;
    cout << "Nama : " << this->name << endl;
    cout << "Point : " << this->point << endl;
    cout << "Kartu : " << endl;
    MyCard.getFirstPlayerCard().print();
    MyCard.getSecondPlayerCard().print();

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

void Player::addPoint(long long int amount){
    point += amount;
}

// void Player::setCombo(Combo paket){
//     MyCombo = paket;
// }

// Combo Player::getCombo(){
//     return MyCombo;
// }


void Player::setCardOne(Card card1){
    MyCard.setFirstPlayerCard(card1);
}

Card Player::getCardOne(){
    return MyCard.getFirstPlayerCard();
}

void Player::setCardTwo(Card card2){
    MyCard.setSecondPlayerCard(card2);
}

Card Player::getCardTwo(){
    return MyCard.getSecondPlayerCard();
}

void Player::setAbility(AbilityCard *ini){
    MyCard.setAbilityCard(ini);
}

AbilityCard Player::getAbility(){
    return MyCard.getAbilityCard()[0];
}

PlayerCard Player::getMyCard() const
{
    return this->MyCard;
}