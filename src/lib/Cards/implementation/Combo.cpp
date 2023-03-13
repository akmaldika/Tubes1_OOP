#include "../header/Combo.hpp"

/*Static*/
map<string, float> Combo::thresholdCombo {
    {"High Card", 0.0},
    {"Pair", 5.82},
    // Masih default 
    {"Two Pair",12.14},
    {"Three of a Kind", 18.63},
    {"Straight", 25.19},
    {"Flush", 31.21 },
    {"Full House", 37.06},
    {"Four of a Kind", 43.69},
    {"Straight Flush", 50.36}
    };

/*Non-Static*/
Combo::Combo(){
    this->type = "unknown";
}

Combo::Combo(vector<Card>& combination){
    for (auto i= combination.begin(); i!=combination.end(); i++){
        this->combination.push_back(*i);
    }
    this->type = "unknown";
}

Combo::~Combo(){
    this->combination.clear();
}

string Combo::getType(){
    return this->type;
}

bool Combo::isFlush(){ 
    for (int i=0; i<4;i++){
        if (this->combination[i].getColor() != this->combination[i+1].getColor()){
            return false;
        }
    }
    return true;
}

bool Combo::isStraight(){
    for (int i=0; i<4;i++){
        if (this->combination[i].value()!=(this->combination[i+1].value()-1)){
            return false;
        }
    }
    return true;
}


int Combo::getNumOfPair(){
    set<int> pairValue;
    for (int i=0; i<4; i++){
        for (int j=i+1; j<5; j++){
            if (this->combination[i].value() == this->combination[j].value()){
                pairValue.insert(this->combination[i].value());
            }
        }
    }
    return pairValue.size();    
}

int Combo:: getNOfKind(){
    int nOfKind = 1;
    for (int i=0; i<4; i++){
        int nTemp = 1; // menyimpan sementara nOfKind untuk evaluasi setiap card 
        for (int j=i+1; j<5; j++){
            if (this->combination[i].value() == this->combination[j].value()){
                nTemp++;
            }
        }
        if (nTemp>nOfKind){ // Jika ditemukan angka sama lebih banyak
            nOfKind=nTemp;
        } 
    }
    return nOfKind;
}

void Combo::setComboType(){
    // Mencari jenis combinasi
    int nOfKind = getNOfKind(); // Maksimal banyak angka yang sama
    int nPair = 0; // Banyak pair default
    if (nOfKind==2){
        nPair = getNumOfPair(); //Jika nOfKind=2, minimal ada satu pair, lakukan pengecekan 
    }
    if (isFlush()){
        if(isStraight()){
            this->type="Straight Flush";
        } else {
            this->type="Flush";
        }
    } else if (nOfKind==4){
        this->type="Four of a Kind";
    } else if (nOfKind==3){
        if (nPair==2){ // Dalam kasus ini, akan terbaca dua pair => three of kind dan pair
            this->type="Full House";
        } else {
            this->type="Three of a Kind";
        }
    } else if (isStraight()){
        this->type="Straight";
    } else if(nPair==2){
        this->type="Two Pair";
    } else if(nPair==1){
        this->type="Pair";
    } else {
        this->type="High Card";
    }
}

double Combo::value(){
    if (this->type == "unknown"){
        setComboType();
    }
    return thresholdCombo[this->type] + basicValue();
}

double Combo::basicValue(){
    double basicVal=0;
    for (int i=0; i<this->combination.size();i++){
        basicVal+= (this->combination[i].value()*0.1+0.03*Card::getColorFactor()[this->combination[i].getColor()]);
    }
    return basicVal;
}

bool Combo::operator>(Combo& combo){
    return (this->value() > combo.value());
}

bool Combo::operator==(Combo& combo){
    return (this->value() == combo.value());
}

bool Combo::operator<(Combo& combo){
    return (this->value() < combo.value());
}
void Combo::print(){
    for (int i=0; i< this->combination.size();i++){
        this->combination[i].print();
        cout<<endl;
    }
}