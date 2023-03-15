#include "../header/TableCard.hpp"

TableCard::TableCard() {
    vector<Card> emptyCards;
    this->tableCard = emptyCards;
    this->tableCardCount = 0;
}

TableCard::TableCard(vector<Card> tableCard) {
    this->tableCard = tableCard;
    this->tableCardCount = tableCard.size();
}

TableCard::TableCard(const TableCard& tableCard) {
    this->tableCard = tableCard.tableCard;
    this->tableCardCount = tableCard.tableCard.size();
}

TableCard::~TableCard() {

}

void TableCard::setTableCard(vector<Card> tableCard) {
    this->tableCard = tableCard;
    this->tableCardCount = tableCard.size();
}

vector<Card> TableCard::getTableCard() {
    return this->tableCard;
}

int TableCard::getTableCardCount() {
    return this->tableCardCount;
}

TableCard& TableCard::operator+(Card card) {
    this->tableCard.push_back(card);
    this->tableCardCount++;
    return *this;
}

TableCard& TableCard::operator-(Card card) {
    for (int i = 0; i < tableCard.size(); i++) {
        if (tableCard[i] == card) {
            tableCard.erase(tableCard.begin() + i);
            this->tableCardCount--;
            break;
        }
    }
    return *this;
}

TableCard& TableCard::operator=(const TableCard& tableCard) {
    this->tableCard = tableCard.tableCard;
    this->tableCardCount = tableCard.tableCard.size();
    return *this;
}

void TableCard::printTwoCards(){
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
    if (this->tableCard[0].getColor()=="hijau"){
        colorInterfaceC1 = LIGHT_GREEN;
        symbolC1 = 'G';
    } else if (this->tableCard[0].getColor()=="biru"){
        colorInterfaceC1 = LIGHT_BLUE;
        symbolC1 = 'B';
    } else if(this->tableCard[0].getColor()=="kuning"){
        colorInterfaceC1 = YELLOW;
        symbolC1 = 'Y';
    } else if (this->tableCard[0].getColor()=="merah"){
        colorInterfaceC1 = LIGHT_RED;
        symbolC1 = 'R';
    }

    // Format Value pada posisi
    pos1C1= pos2C1 = to_string(int(this->tableCard[0].value()));
    if (this->tableCard[0].value() < 10){
        // Satu digit
        pos1C1 += " ";
        pos2C1 = " " + pos2C1;
    } 
    // Coloring dan symbol Card 2
    if (this->tableCard[1].getColor()=="hijau"){
        colorInterfaceC2 = LIGHT_GREEN;
        symbolC2 = 'G';
    } else if (this->tableCard[1].getColor()=="biru"){
        colorInterfaceC2 = LIGHT_BLUE;
        symbolC2 = 'B';
    } else if(this->tableCard[1].getColor()=="kuning"){
        colorInterfaceC2 = YELLOW;
        symbolC2 = 'Y';
    } else if (this->tableCard[1].getColor()=="merah"){
        colorInterfaceC2 = LIGHT_RED;
        symbolC2 = 'R';
    }

    // Format Value pada posisi
    pos1C2= pos2C2 = to_string(int(this->tableCard[1].value()));
    if (this->tableCard[1].value() < 10){
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
void TableCard::printThreeCards(){
    // ASCII Code coloring
    string colorInterfaceC1;
    string colorInterfaceC2;
    string colorInterfaceC3;
    // Value and Position on card
    string pos1C1;
    string pos2C1;
    string pos1C2;
    string pos2C2;
    string pos1C3;
    string pos2C3;
    // Center of Card
    char symbolC1;
    char symbolC2;
    char symbolC3;

    // Coloring dan symbol Card 1
    if (this->tableCard[0].getColor()=="hijau"){
        colorInterfaceC1 = LIGHT_GREEN;
        symbolC1 = 'G';
    } else if (this->tableCard[0].getColor()=="biru"){
        colorInterfaceC1 = LIGHT_BLUE;
        symbolC1 = 'B';
    } else if(this->tableCard[0].getColor()=="kuning"){
        colorInterfaceC1 = YELLOW;
        symbolC1 = 'Y';
    } else if (this->tableCard[0].getColor()=="merah"){
        colorInterfaceC1 = LIGHT_RED;
        symbolC1 = 'R';
    }

    // Format Value pada posisi
    pos1C1= pos2C1 = to_string(int(this->tableCard[0].value()));
    if (this->tableCard[0].value() < 10){
        // Satu digit
        pos1C1 += " ";
        pos2C1 = " " + pos2C1;
    } 


    // Coloring dan symbol Card 2
    if (this->tableCard[1].getColor()=="hijau"){
        colorInterfaceC2 = LIGHT_GREEN;
        symbolC2 = 'G';
    } else if (this->tableCard[1].getColor()=="biru"){
        colorInterfaceC2 = LIGHT_BLUE;
        symbolC2 = 'B';
    } else if(this->tableCard[1].getColor()=="kuning"){
        colorInterfaceC2 = YELLOW;
        symbolC2 = 'Y';
    } else if (this->tableCard[1].getColor()=="merah"){
        colorInterfaceC2 = LIGHT_RED;
        symbolC2 = 'R';
    }

    // Format Value pada posisi
    pos1C2= pos2C2 = to_string(int(this->tableCard[1].value()));
    if (this->tableCard[1].value() < 10){
        // Satu digit
        pos1C2 += " ";
        pos2C2 = " " + pos2C2;
    } 


    // Coloring dan symbol Card 3
    if (this->tableCard[2].getColor()=="hijau"){
        colorInterfaceC3 = LIGHT_GREEN;
        symbolC3 = 'G';
    } else if (this->tableCard[2].getColor()=="biru"){
        colorInterfaceC3 = LIGHT_BLUE;
        symbolC3 = 'B';
    } else if(this->tableCard[2].getColor()=="kuning"){
        colorInterfaceC3 = YELLOW;
        symbolC3 = 'Y';
    } else if (this->tableCard[2].getColor()=="merah"){
        colorInterfaceC3 = LIGHT_RED;
        symbolC3 = 'R';
    }

    // Format Value pada posisi
    pos1C3= pos2C3 = to_string(int(this->tableCard[2].value()));
    if (this->tableCard[2].value() < 10){
        // Satu digit
        pos1C3 += " ";
        pos2C3 = " " + pos2C3;
    } 

    // Output
    cout<<colorInterfaceC1<<".---------."               <<"     "<<colorInterfaceC2<<".---------."              <<"     "<<colorInterfaceC3<<".---------."              <<endl;
    cout<<colorInterfaceC1<<"|"<<pos1C1<<"       |"     <<"     "<<colorInterfaceC2<<"|"<<pos1C2<<"       |"    <<"     "<<colorInterfaceC3<<"|"<<pos1C3<<"       |"    <<endl;
    cout<<colorInterfaceC1<<"|  .---.  |"               <<"     "<<colorInterfaceC2<<"|  .---.  |"              <<"     "<<colorInterfaceC3<<"|  .---.  |"              <<endl;
    cout<<colorInterfaceC1<<"|  : "<<symbolC1<<" :  |"  <<"     "<<colorInterfaceC2<<"|  : "<<symbolC2<<" :  |" <<"     "<<colorInterfaceC3<<"|  : "<<symbolC3<<" :  |" <<endl;
    cout<<colorInterfaceC1<<"|  '---'  |"               <<"     "<<colorInterfaceC2<<"|  '---'  |"              <<"     "<<colorInterfaceC3<<"|  '---'  |"              <<endl;
    cout<<colorInterfaceC1<<"|       "<<pos2C1<<"|"     <<"     "<<colorInterfaceC2<<"|       "<<pos2C2<<"|"    <<"     "<<colorInterfaceC3<<"|       "<<pos2C3<<"|"    <<endl;
    cout<<colorInterfaceC1<<"`---------'"               <<"     "<<colorInterfaceC2<<"`---------'"              <<"     "<<colorInterfaceC3<<"`---------'";
    cout<<RESET<<endl;
}
void TableCard::printFourCards(){
    // ASCII Code coloring
    string colorInterfaceC1;
    string colorInterfaceC2;
    string colorInterfaceC3;
    string colorInterfaceC4;
    // Value and Position on card
    string pos1C1;
    string pos2C1;
    string pos1C2;
    string pos2C2;
    string pos1C3;
    string pos2C3;
    string pos1C4;
    string pos2C4;
    // Center of Card
    char symbolC1;
    char symbolC2;
    char symbolC3;
    char symbolC4;

    // Coloring dan symbol Card 1
    if (this->tableCard[0].getColor()=="hijau"){
        colorInterfaceC1 = LIGHT_GREEN;
        symbolC1 = 'G';
    } else if (this->tableCard[0].getColor()=="biru"){
        colorInterfaceC1 = LIGHT_BLUE;
        symbolC1 = 'B';
    } else if(this->tableCard[0].getColor()=="kuning"){
        colorInterfaceC1 = YELLOW;
        symbolC1 = 'Y';
    } else if (this->tableCard[0].getColor()=="merah"){
        colorInterfaceC1 = LIGHT_RED;
        symbolC1 = 'R';
    }

    // Format Value pada posisi
    pos1C1= pos2C1 = to_string(int(this->tableCard[0].value()));
    if (this->tableCard[0].value() < 10){
        // Satu digit
        pos1C1 += " ";
        pos2C1 = " " + pos2C1;
    } 


    // Coloring dan symbol Card 2
    if (this->tableCard[1].getColor()=="hijau"){
        colorInterfaceC2 = LIGHT_GREEN;
        symbolC2 = 'G';
    } else if (this->tableCard[1].getColor()=="biru"){
        colorInterfaceC2 = LIGHT_BLUE;
        symbolC2 = 'B';
    } else if(this->tableCard[1].getColor()=="kuning"){
        colorInterfaceC2 = YELLOW;
        symbolC2 = 'Y';
    } else if (this->tableCard[1].getColor()=="merah"){
        colorInterfaceC2 = LIGHT_RED;
        symbolC2 = 'R';
    }

    // Format Value pada posisi
    pos1C2= pos2C2 = to_string(int(this->tableCard[1].value()));
    if (this->tableCard[1].value() < 10){
        // Satu digit
        pos1C2 += " ";
        pos2C2 = " " + pos2C2;
    } 


    // Coloring dan symbol Card 3
    if (this->tableCard[2].getColor()=="hijau"){
        colorInterfaceC3 = LIGHT_GREEN;
        symbolC3 = 'G';
    } else if (this->tableCard[2].getColor()=="biru"){
        colorInterfaceC3 = LIGHT_BLUE;
        symbolC3 = 'B';
    } else if(this->tableCard[2].getColor()=="kuning"){
        colorInterfaceC3 = YELLOW;
        symbolC3 = 'Y';
    } else if (this->tableCard[2].getColor()=="merah"){
        colorInterfaceC3 = LIGHT_RED;
        symbolC3 = 'R';
    }

    // Format Value pada posisi
    pos1C3= pos2C3 = to_string(int(this->tableCard[2].value()));
    if (this->tableCard[2].value() < 10){
        // Satu digit
        pos1C3 += " ";
        pos2C3 = " " + pos2C3;
    } 


    // Coloring dan symbol Card 4
    if (this->tableCard[3].getColor()=="hijau"){
        colorInterfaceC4 = LIGHT_GREEN;
        symbolC4 = 'G';
    } else if (this->tableCard[3].getColor()=="biru"){
        colorInterfaceC4 = LIGHT_BLUE;
        symbolC4 = 'B';
    } else if(this->tableCard[3].getColor()=="kuning"){
        colorInterfaceC4 = YELLOW;
        symbolC4 = 'Y';
    } else if (this->tableCard[3].getColor()=="merah"){
        colorInterfaceC4 = LIGHT_RED;
        symbolC4 = 'R';
    }

    // Format Value pada posisi
    pos1C4= pos2C4 = to_string(int(this->tableCard[3].value()));
    if (this->tableCard[3].value() < 10){
        // Satu digit
        pos1C4 += " ";
        pos2C4 = " " + pos2C4;
    } 

    // Output
    cout<<colorInterfaceC1<<".---------."               <<"     "<<colorInterfaceC2<<".---------."              <<"     "<<colorInterfaceC3<<".---------."              <<"     "<<colorInterfaceC4<<".---------."              <<endl;
    cout<<colorInterfaceC1<<"|"<<pos1C1<<"       |"     <<"     "<<colorInterfaceC2<<"|"<<pos1C2<<"       |"    <<"     "<<colorInterfaceC3<<"|"<<pos1C3<<"       |"    <<"     "<<colorInterfaceC4<<"|"<<pos1C4<<"       |"    <<endl;
    cout<<colorInterfaceC1<<"|  .---.  |"               <<"     "<<colorInterfaceC2<<"|  .---.  |"              <<"     "<<colorInterfaceC3<<"|  .---.  |"              <<"     "<<colorInterfaceC4<<"|  .---.  |"              <<endl;
    cout<<colorInterfaceC1<<"|  : "<<symbolC1<<" :  |"  <<"     "<<colorInterfaceC2<<"|  : "<<symbolC2<<" :  |" <<"     "<<colorInterfaceC3<<"|  : "<<symbolC3<<" :  |" <<"     "<<colorInterfaceC4<<"|  : "<<symbolC4<<" :  |" <<endl;
    cout<<colorInterfaceC1<<"|  '---'  |"               <<"     "<<colorInterfaceC2<<"|  '---'  |"              <<"     "<<colorInterfaceC3<<"|  '---'  |"              <<"     "<<colorInterfaceC4<<"|  '---'  |"              <<endl;
    cout<<colorInterfaceC1<<"|       "<<pos2C1<<"|"     <<"     "<<colorInterfaceC2<<"|       "<<pos2C2<<"|"    <<"     "<<colorInterfaceC3<<"|       "<<pos2C3<<"|"    <<"     "<<colorInterfaceC4<<"|       "<<pos2C4<<"|"    <<endl;
    cout<<colorInterfaceC1<<"`---------'"               <<"     "<<colorInterfaceC2<<"`---------'"              <<"     "<<colorInterfaceC3<<"`---------'"              <<"     "<<colorInterfaceC4<<"`---------'";
    cout<<RESET<<endl;
}
void TableCard::printFiveCards(){
    // ASCII Code coloring
    string colorInterfaceC1;
    string colorInterfaceC2;
    string colorInterfaceC3;
    string colorInterfaceC4;
    string colorInterfaceC5;
    // Value and Position on card
    string pos1C1;
    string pos2C1;
    string pos1C2;
    string pos2C2;
    string pos1C3;
    string pos2C3;
    string pos1C4;
    string pos2C4;
    string pos1C5;
    string pos2C5;
    // Center of Card
    char symbolC1;
    char symbolC2;
    char symbolC3;
    char symbolC4;
    char symbolC5;

    // Coloring dan symbol Card 1
    if (this->tableCard[0].getColor()=="hijau"){
        colorInterfaceC1 = LIGHT_GREEN;
        symbolC1 = 'G';
    } else if (this->tableCard[0].getColor()=="biru"){
        colorInterfaceC1 = LIGHT_BLUE;
        symbolC1 = 'B';
    } else if(this->tableCard[0].getColor()=="kuning"){
        colorInterfaceC1 = YELLOW;
        symbolC1 = 'Y';
    } else if (this->tableCard[0].getColor()=="merah"){
        colorInterfaceC1 = LIGHT_RED;
        symbolC1 = 'R';
    }

    // Format Value pada posisi
    pos1C1= pos2C1 = to_string(int(this->tableCard[0].value()));
    if (this->tableCard[0].value() < 10){
        // Satu digit
        pos1C1 += " ";
        pos2C1 = " " + pos2C1;
    } 


    // Coloring dan symbol Card 2
    if (this->tableCard[1].getColor()=="hijau"){
        colorInterfaceC2 = LIGHT_GREEN;
        symbolC2 = 'G';
    } else if (this->tableCard[1].getColor()=="biru"){
        colorInterfaceC2 = LIGHT_BLUE;
        symbolC2 = 'B';
    } else if(this->tableCard[1].getColor()=="kuning"){
        colorInterfaceC2 = YELLOW;
        symbolC2 = 'Y';
    } else if (this->tableCard[1].getColor()=="merah"){
        colorInterfaceC2 = LIGHT_RED;
        symbolC2 = 'R';
    }

    // Format Value pada posisi
    pos1C2= pos2C2 = to_string(int(this->tableCard[1].value()));
    if (this->tableCard[1].value() < 10){
        // Satu digit
        pos1C2 += " ";
        pos2C2 = " " + pos2C2;
    } 


    // Coloring dan symbol Card 3
    if (this->tableCard[2].getColor()=="hijau"){
        colorInterfaceC3 = LIGHT_GREEN;
        symbolC3 = 'G';
    } else if (this->tableCard[2].getColor()=="biru"){
        colorInterfaceC3 = LIGHT_BLUE;
        symbolC3 = 'B';
    } else if(this->tableCard[2].getColor()=="kuning"){
        colorInterfaceC3 = YELLOW;
        symbolC3 = 'Y';
    } else if (this->tableCard[2].getColor()=="merah"){
        colorInterfaceC3 = LIGHT_RED;
        symbolC3 = 'R';
    }

    // Format Value pada posisi
    pos1C3= pos2C3 = to_string(int(this->tableCard[2].value()));
    if (this->tableCard[2].value() < 10){
        // Satu digit
        pos1C3 += " ";
        pos2C3 = " " + pos2C3;
    } 


    // Coloring dan symbol Card 4
    if (this->tableCard[3].getColor()=="hijau"){
        colorInterfaceC4 = LIGHT_GREEN;
        symbolC4 = 'G';
    } else if (this->tableCard[3].getColor()=="biru"){
        colorInterfaceC4 = LIGHT_BLUE;
        symbolC4 = 'B';
    } else if(this->tableCard[3].getColor()=="kuning"){
        colorInterfaceC4 = YELLOW;
        symbolC4 = 'Y';
    } else if (this->tableCard[3].getColor()=="merah"){
        colorInterfaceC4 = LIGHT_RED;
        symbolC4 = 'R';
    }

    // Format Value pada posisi
    pos1C4= pos2C4 = to_string(int(this->tableCard[3].value()));
    if (this->tableCard[3].value() < 10){
        // Satu digit
        pos1C4 += " ";
        pos2C4 = " " + pos2C4;
    } 


    // Coloring dan symbol Card 5
    if (this->tableCard[4].getColor()=="hijau"){
        colorInterfaceC5 = LIGHT_GREEN;
        symbolC5 = 'G';
    } else if (this->tableCard[4].getColor()=="biru"){
        colorInterfaceC5 = LIGHT_BLUE;
        symbolC5 = 'B';
    } else if(this->tableCard[4].getColor()=="kuning"){
        colorInterfaceC5 = YELLOW;
        symbolC5 = 'Y';
    } else if (this->tableCard[4].getColor()=="merah"){
        colorInterfaceC5 = LIGHT_RED;
        symbolC5 = 'R';
    }

    // Format Value pada posisi
    pos1C5= pos2C5 = to_string(int(this->tableCard[4].value()));
    if (this->tableCard[4].value() < 10){
        // Satu digit
        pos1C5 += " ";
        pos2C5 = " " + pos2C5;
    } 

    // Output
    cout<<colorInterfaceC1<<".---------."               <<"     "<<colorInterfaceC2<<".---------."              <<"     "<<colorInterfaceC3<<".---------."              <<"     "<<colorInterfaceC4<<".---------."              <<"     "<<colorInterfaceC5<<".---------."              <<endl;
    cout<<colorInterfaceC1<<"|"<<pos1C1<<"       |"     <<"     "<<colorInterfaceC2<<"|"<<pos1C2<<"       |"    <<"     "<<colorInterfaceC3<<"|"<<pos1C3<<"       |"    <<"     "<<colorInterfaceC4<<"|"<<pos1C4<<"       |"    <<"     "<<colorInterfaceC5<<"|"<<pos1C5<<"       |"    <<endl;
    cout<<colorInterfaceC1<<"|  .---.  |"               <<"     "<<colorInterfaceC2<<"|  .---.  |"              <<"     "<<colorInterfaceC3<<"|  .---.  |"              <<"     "<<colorInterfaceC4<<"|  .---.  |"              <<"     "<<colorInterfaceC5<<"|  .---.  |"              <<endl;
    cout<<colorInterfaceC1<<"|  : "<<symbolC1<<" :  |"  <<"     "<<colorInterfaceC2<<"|  : "<<symbolC2<<" :  |" <<"     "<<colorInterfaceC3<<"|  : "<<symbolC3<<" :  |" <<"     "<<colorInterfaceC4<<"|  : "<<symbolC4<<" :  |" <<"     "<<colorInterfaceC5<<"|  : "<<symbolC5<<" :  |" <<endl;
    cout<<colorInterfaceC1<<"|  '---'  |"               <<"     "<<colorInterfaceC2<<"|  '---'  |"              <<"     "<<colorInterfaceC3<<"|  '---'  |"              <<"     "<<colorInterfaceC4<<"|  '---'  |"              <<"     "<<colorInterfaceC5<<"|  '---'  |"              <<endl;
    cout<<colorInterfaceC1<<"|       "<<pos2C1<<"|"     <<"     "<<colorInterfaceC2<<"|       "<<pos2C2<<"|"    <<"     "<<colorInterfaceC3<<"|       "<<pos2C3<<"|"    <<"     "<<colorInterfaceC4<<"|       "<<pos2C4<<"|"    <<"     "<<colorInterfaceC5<<"|       "<<pos2C5<<"|"    <<endl;
    cout<<colorInterfaceC1<<"`---------'"               <<"     "<<colorInterfaceC2<<"`---------'"              <<"     "<<colorInterfaceC3<<"`---------'"              <<"     "<<colorInterfaceC4<<"`---------'"              <<"     "<<colorInterfaceC5<<"`---------'";
    cout<<RESET<<endl;
}

void TableCard::printCard() {
    switch (this->tableCard.size())
    {
    case 1:
        this->tableCard[0].print();

        break;
    case 2:
        printTwoCards();
        break;
    case 3:
        printThreeCards();
        break;
    case 4:
        printFourCards();
        break;
    case 5:
        printFiveCards();
        break;
    }
}