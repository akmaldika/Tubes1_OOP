#include "../header/PlayerCard.hpp"

PlayerCard::PlayerCard() {
    this->playerCard.first = Card();
    this->playerCard.second = Card();
    this->abilityCard = new AbilityCard();
    this->ID = 0;
    this->playerCardCount = 0;
}

PlayerCard::PlayerCard(Card card1, Card card2, AbilityCard* abilityCard, int ID) {
    this->playerCard.first = card1;
    this->playerCard.second = card2;
    this->abilityCard = abilityCard;
    this->ID = ID;
    this->playerCardCount = 2;
}

PlayerCard::PlayerCard(const PlayerCard& playerCard) {
    this->playerCard.first = playerCard.playerCard.first;
    this->playerCard.second = playerCard.playerCard.second;
    this->abilityCard = playerCard.abilityCard;
    this->ID = playerCard.ID;
    this->playerCardCount = 2;
}

PlayerCard::~PlayerCard() {
    
}

void PlayerCard::setFirstPlayerCard(Card card) {
    this->playerCard.first = card;
}

void PlayerCard::setSecondPlayerCard(Card card) {
    this->playerCard.second = card;
}

void PlayerCard::setAbilityCard(AbilityCard* card) {
    cout << "Apa lah itu lah" << endl;
    this->abilityCard = card;
    cout << "Apa lah ya iya lah" << endl;
}

void PlayerCard::setID(int ID) {
    this->ID = ID;
}

Card PlayerCard::getFirstPlayerCard() const{
    return this->playerCard.first;
}

Card PlayerCard::getSecondPlayerCard() const{
    return this->playerCard.second;
}

AbilityCard* PlayerCard::getAbilityCard() {
    return this->abilityCard;
}

int PlayerCard::getID() {
    return this->ID;
}

int PlayerCard::getPlayerCardCount() {
    return this->playerCardCount;
}

PlayerCard& PlayerCard::operator+(Card card) {
    if (playerCard.first.getColor() == "unknown") {
        playerCard.first = card;
        this->playerCardCount++;
    } else if (playerCard.second.getColor() == "unknown") {
        playerCard.second = card;
        this->playerCardCount++;
    }
    return *this;
}

PlayerCard& PlayerCard::operator-(Card card) {
    if (this->playerCard.first == card) {
        playerCard.first = Card();
        this->playerCardCount--;
    } else if (this->playerCard.second == card) {
        playerCard.second = Card();
        this->playerCardCount--;
    }
    return *this;
}

PlayerCard& PlayerCard::operator=(const PlayerCard& playerCard) {
    this->playerCard.first = playerCard.playerCard.first;
    this->playerCard.second = playerCard.playerCard.second;
    this->abilityCard = playerCard.abilityCard;
    this->ID = playerCard.ID;
    this->playerCardCount = 2;
    return *this;
}

void PlayerCard::printCard() {
    // ASCII Code coloring
    string colorInterfaceC1;
    string colorInterfaceC2;
    // Value and Position on card
    string pos1C1;
    string pos2C1;
    string pos1C2;
    string pos2C2;
    // Center of Card
    char symbolC1;
    char symbolC2;

    // Coloring dan symbol Card 1
    if (this->playerCard.first.getColor()=="hijau"){
        colorInterfaceC1 = LIGHT_GREEN;
        symbolC1 = 'G';
    } else if (this->playerCard.first.getColor()=="biru"){
        colorInterfaceC1 = LIGHT_BLUE;
        symbolC1 = 'B';
    } else if(this->playerCard.first.getColor()=="kuning"){
        colorInterfaceC1 = YELLOW;
        symbolC1 = 'Y';
    } else if (this->playerCard.first.getColor()=="merah"){
        colorInterfaceC1 = LIGHT_RED;
        symbolC1 = 'R';
    }

    // Format Value pada posisi
    pos1C1= pos2C1 = to_string(int(this->playerCard.first.value()));
    if (this->playerCard.first.value() < 10){
        // Satu digit
        pos1C1 += " ";
        pos2C1 = " " + pos2C1;
    } 
    // Coloring dan symbol Card 2
    if (this->playerCard.second.getColor()=="hijau"){
        colorInterfaceC2 = LIGHT_GREEN;
        symbolC2 = 'G';
    } else if (this->playerCard.second.getColor()=="biru"){
        colorInterfaceC2 = LIGHT_BLUE;
        symbolC2 = 'B';
    } else if(this->playerCard.second.getColor()=="kuning"){
        colorInterfaceC2 = YELLOW;
        symbolC2 = 'Y';
    } else if (this->playerCard.second.getColor()=="merah"){
        colorInterfaceC2 = LIGHT_RED;
        symbolC2 = 'R';
    }

    // Format Value pada posisi
    pos1C2= pos2C2 = to_string(int(this->playerCard.second.value()));
    if (this->playerCard.second.value() < 10){
        // Satu digit
        pos1C2 += " ";
        pos2C2 = " " + pos2C2;
    } 

    // Output
    cout<<colorInterfaceC1<<".---------."               <<"     "<<colorInterfaceC2<<".---------."              <<endl;
    cout<<colorInterfaceC1<<"|"<<pos1C1<<"       |"     <<"     "<<colorInterfaceC2<<"|"<<pos1C2<<"       |"    <<endl;
    cout<<colorInterfaceC1<<"|  .---.  |"               <<"     "<<colorInterfaceC2<<"|  .---.  |"              <<endl;
    cout<<colorInterfaceC1<<"|  : "<<symbolC1<<" :  |"  <<"     "<<colorInterfaceC2<<"|  : "<<symbolC2<<" :  |" <<endl;
    cout<<colorInterfaceC1<<"|  '---'  |"               <<"     "<<colorInterfaceC2<<"|  '---'  |"              <<endl;
    cout<<colorInterfaceC1<<"|       "<<pos2C1<<"|"     <<"     "<<colorInterfaceC2<<"|       "<<pos2C2<<"|"    <<endl;
    cout<<colorInterfaceC1<<"`---------'"               <<"     "<<colorInterfaceC2<<"`---------'";
    cout<<RESET<<endl;
}