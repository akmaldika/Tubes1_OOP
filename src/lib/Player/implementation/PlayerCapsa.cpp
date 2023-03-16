#include "../header/PlayerCapsa.hpp"

PlayerCapsa::PlayerCapsa(){
    this->ID = 0;
    this->name = "NaN";
    this->point = 0;
}

PlayerCapsa::PlayerCapsa(int ID, string name, vector<CapsaCard> cards):
    MyHands(cards)
{
    this->ID = ID;
    this->name = name;
    this->point = 10000;
}

PlayerCapsaCard PlayerCapsa::getMyCard() const{
    return this->MyHands;
}

void PlayerCapsa::setMyCard(PlayerCapsaCard newHands){
    this->MyHands = newHands;
}

void PlayerCapsa::status(){
        cout << "    .///\\.        " << endl;
        cout << "   //////\\\\     \n";
        cout << "  (.)(.)-||    ID    : " << this->ID << endl;
        cout << "  | L    )|    Name  : " << this->name << endl;
        cout << "  | _    /     Point : " << this->point << endl;
        cout << "  |____.'     " << endl;
        cout << "  ___| |__     " << endl;
}

void PlayerCapsa::addPoint(long long int amount){
    this->point += amount;   
}

PlayerCapsa& PlayerCapsa::operator=(PlayerCapsa player){
    ID = player.ID;
    name = player.name;
    point = player.point;
    return *this;
}