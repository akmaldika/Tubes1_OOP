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
    this->ID = playerCount;
    this->name = to_string(playerCount);
    this->point = 0;   
    this->played = false;
    playerCount++;
}
void Player::setCombo(Combo &MyCombo){
    Hand = MyCombo;
}
Combo Player::getCombo(){
    return Hand;
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
// void Player::status() const{
//     cout << "Status Player" << endl;
//     cout << "ID : " << this->ID << endl;
//     cout << "Nama : " << this->name << endl;
//     cout << "Point : " << this->point << endl;
//     cout << "Kartu : " << endl;
//     MyCard.getFirstPlayerCard().print();
//     MyCard.getSecondPlayerCard().print();

//     cout << endl;
// }

void Player::status(){
    cout << "    .///\\.        " << endl;
    cout << "   //////\\\\     \n";
    cout << "  (.)(.)-||    ID    : " << this->ID << endl;
    cout << "  | L    )|    Name  : " << this->name << endl;
    cout << "  | _    /     Point : " << this->point << endl;
    cout << "  |____.'      Hand  : " << this->Hand.getType() << endl;
    cout << "  ___| |__     Value : " << this->Hand.value() << endl;

    cout << " __________________________YOUR CARD______________________________\n";
    MyCard.printCard();
    // print ability card


}
void Player::setPlayed(bool played){
    this->played = played;
}
bool Player::getPlayed(){
    return played;
}
bool Player::operator>(Player& enemy){
    return (this->point > enemy.point);
}
bool Player::operator==(const Player& enemy){
    return (this->point == enemy.ID);
}
bool Player::operator<(Player& enemy){
    return (this->point < enemy.point);
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
    //cout << "Otw kasih ability" << endl;
    MyCard.setAbilityCard(ini);
}

AbilityCard* Player::getAbility(){
    return MyCard.getAbilityCard();
}

PlayerCard Player::getMyCard() const
{
    return this->MyCard;
}

Player& Player::operator=(Player player){
    ID = player.ID;
    name = player.name;
    point = player.point;
    played = player.played;
    MyCard = player.MyCard;
    Hand = player.Hand;

    return *this;
}