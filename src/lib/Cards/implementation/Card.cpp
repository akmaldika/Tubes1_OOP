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
}

Card::Card(int value, string color){
    this->valueCard = value;
    this->color = color;
}

string Card::getColor(){
    return this->color;
}

float Card::value(){
    return this->valueCard;
}

float Card::weightValue(){
    return this->valueCard*0.1+0.03*colorFactor[this->color];
}

map<string,float> Card::getColorFactor(){
    return colorFactor;
}

bool Card::operator>(Card& card){
    return (this->weightValue()) > (card.weightValue());
}

bool Card::operator==(Card& card){
    return (this->color == card.color)  && (this->valueCard == card.valueCard);
}
bool Card::operator<(Card& card){
    return (this->weightValue()) < (card.weightValue());
}
void Card::print(){
    // ASCII Code coloring
    string colorInterface;
    // Value and Position on card
    string pos1;
    string pos2;
    // Center of Card
    char symbol;

    // Coloring dan symbol
    if (this->color=="hijau"){
        colorInterface = LIGHT_GREEN;
        symbol = 'G';
    } else if (this->color=="biru"){
        colorInterface = LIGHT_BLUE;
        symbol = 'B';
    } else if(this->color=="kuning"){
        colorInterface = YELLOW;
        symbol = 'Y';
    } else if (this->color=="merah"){
        colorInterface = LIGHT_RED;
        symbol = 'R';
    }

    // Format Value pada posisi
    pos1= pos2 = to_string(this->valueCard);
    if (this->valueCard < 10){
        // Satu digit
        pos1 += " ";
        pos2 = " " + pos2;
    } 

    // Output
    cout<<colorInterface;
    cout<<".---------."<<endl;
    cout<<"|"<<pos1<<"       |"<<endl;
    cout<<"|  .---.  |"<<endl;
    cout<<"|  : "<<symbol<<" :  |"<<endl;
    cout<<"|  '---'  |"<<endl;
    cout<<"|       "<<pos2<<"|"<<endl;
    cout<<"`---------'";
    cout<<RESET<<endl;
} 