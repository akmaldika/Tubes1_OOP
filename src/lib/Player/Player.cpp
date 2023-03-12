#include "Player.hpp"
#include <iostream>
using namespace std;

// construktor
Player::Player(){
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