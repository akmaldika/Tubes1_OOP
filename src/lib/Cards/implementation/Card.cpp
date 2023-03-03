#include "../header/Card.hpp"

Card::Card(){
    this->valueCard = 0;
    this->color="unknown";
    this->category = "unknown";
    this->ability = "unknown";
}

Card::Card(int value, string color){
    this->valueCard = value;
    this->color = color;
    this->category = "regular";
    this->ability = "unknown";
}

Card::Card(string ability){
    this->valueCard = 0;
    this->color = "unknown";
    this->category = "ability";
    this->ability = ability;
}

string Card::getColor(){
    return this->color;
}

string Card::getCategory(){
    return this->category;
}

string Card::getAbility(){
    return this->ability;
}

double Card::value(){
    return this->valueCard;
}

bool Card::operator==(Card& card){
    if(this->color == card.color && this->category == card.category && this->ability == card.ability && this->valueCard == card.valueCard){
        return true;
    }
    return false;
}