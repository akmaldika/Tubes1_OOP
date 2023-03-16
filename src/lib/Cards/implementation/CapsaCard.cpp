#include "../header/CapsaCard.hpp"


map<string, float> CapsaCard::interfaceValue{
    {"0", 0},
    {"2", 2},
    {"3", 3},
    {"4", 4},
    {"5", 5},
    {"6", 6},
    {"7", 7},
    {"8", 8},
    {"9", 9},
    {"10", 10},
    {"J", 11},
    {"Q", 12},
    {"K", 13},
    {"A", 14}
};

map<string, float> CapsaCard::kindFactor{
    {"diamond", 0}, // wajik
    {"club", 1}, // keriting
    {"heart", 2}, // hati
    {"spade", 3} // sekop
};

CapsaCard::CapsaCard(){
    this->interface = "0";
    this->valueCard = interfaceValue[this->interface];
    this->kind="unknown";
}

CapsaCard::CapsaCard(string interface , string kind){
    this->interface = interface;
    this->valueCard = interfaceValue[this->interface];
    this->kind = kind;
}

string CapsaCard::getColor(){
    return this->kind;
}

string CapsaCard::interfaceVal(){
    return this->interface;
}

float CapsaCard::value(){
    return this->valueCard;
}

float CapsaCard::weightValue(){
    return this->valueCard*0.1+0.03*kindFactor[this->kind];
}

map<string,float> CapsaCard::getKindFactor(){
    return kindFactor;
}
map<string,float> CapsaCard::getInterfaceValue(){
    return interfaceValue;
}

bool CapsaCard::operator>(CapsaCard& card){
    return (this->weightValue()) > (card.weightValue());
}

bool CapsaCard::operator==(CapsaCard& card){
    return (this->kind == card.kind)  && (this->valueCard == card.valueCard);
}
bool CapsaCard::operator<(CapsaCard& card){
    return (this->weightValue()) < (card.weightValue());
}
void CapsaCard::print(){
    // ASCII Code coloring
    string colorInterface;
    // Value and Position on card
    string pos1;
    string pos2;
    char symbol;

    // Coloring dan symbol
    if (this->kind=="diamond"){
        colorInterface = LIGHT_RED;
        symbol = 'D';
    } else if (this->kind=="club"){
        colorInterface = WHITE;
        symbol = 'C';
    } else if(this->kind=="heart"){
        colorInterface = LIGHT_RED;
        symbol = 'H';
    } else if (this->kind=="spade"){
        colorInterface = WHITE;
        symbol = 'S';
    }

    // Format Value pada posisi
    pos1= pos2 = this->interface;
    if (this->valueCard < 10 || (this->interface=="A") || (this->interface=="K") || (this->interface=="Q") || (this->interface=="J")){
        // Satu digit
        pos1 += " ";
        pos2 = " " + pos2;
    } 

    // Output

    // switch(symbol){
    //     case 'D':
    cout<<colorInterface;
    cout<<".---------."<<endl;
    cout<<"|"<<pos1<<"       |"<<endl;
    cout<<"|  .---.  |"<<endl;
    cout<<"|  : "<<symbol<<" :  |"<<endl;
    cout<<"|  '---'  |"<<endl;
    cout<<"|       "<<pos2<<"|"<<endl;
    cout<<"`---------'";
    cout<<RESET<<endl;
    //         break;
    // }
} 