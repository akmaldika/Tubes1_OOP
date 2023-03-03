#include "../header/Card.hpp"

map<string, float> Card::colorFactor{
    {"hijau", 0},
    {"biru", 1},
    {"kuning", 2},
    {"merah", 3}
};

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

map<string, float> Card::getColorFactor(){
    return colorFactor;
}