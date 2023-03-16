#include "../header/StandardPlayer.hpp"
#include <iostream>
using namespace std;


void StandardPlayer::setPlayerName(string name){
    this->name = name;
}
string StandardPlayer::getPlayerName(){
    return name;
}
void StandardPlayer::setPlayerPoint(long long int p){
    this->point = p;
}
long long int StandardPlayer::getPlayerPoint(){
    return point;
}
void StandardPlayer::setPlayerID(int ID){
    this->ID = ID;
}
int StandardPlayer::getPlayerID(){
    return ID;
}
// void StandardPlayer::status() const{
//     cout << "Status StandardPlayer" << endl;
//     cout << "ID : " << this->ID << endl;
//     cout << "Nama : " << this->name << endl;
//     cout << "Point : " << this->point << endl;
//     cout << "Kartu : " << endl;
//     MyCard.getFirstPlayerCard().print();
//     MyCard.getSecondPlayerCard().print();

//     cout << endl;
// }
bool StandardPlayer::operator>(StandardPlayer& enemy){
    return (this->point > enemy.point);
}
bool StandardPlayer::operator==(const StandardPlayer& enemy){
    return (this->point == enemy.point);
}
bool StandardPlayer::operator<(StandardPlayer& enemy){
    return (this->point < enemy.point);
}

void StandardPlayer::addPoint(long long int amount){
    point += amount;
}

// void StandardPlayer::setCombo(Combo paket){
//     MyCombo = paket;
// }

// Combo StandardPlayer::getCombo(){
//     return MyCombo;
// }