#include "../header/Combo.hpp"
#include "../../utilityFunction.cpp"
/*Static*/
map<string, float> Combo::thresholdCombo {
    {"High Card", 0.0},
    {"Pair", 1.39}, // highcard single
    {"Two Pair",4.14}, // highest pair
    {"Three of a Kind", 9.44}, // highest two pair
    {"Straight", 13.52}, // highest three of a kind
    {"Flush", 19.44}, // highest straight
    {"Full House", 25.29}, // highest flush
    {"Four of a Kind", 31.92}, // highest full house
    {"Straight Flush", 38.59} // highest four of a kind
    };

/*Non-Static*/
Combo::Combo(){
    this->type = "unknown";
    this->valueCombo = 0;
}

Combo::Combo(vector<Card>& combination){
    for (auto i= combination.begin(); i!=combination.end(); i++){
        this->combination.push_back(*i);
    }
    this->type = "unknown";
    this->valueCombo = 0;
}

Combo::~Combo(){
    this->combination.clear();
}

string Combo::getType(){
    return this->type;
}

bool Combo::isFlush(){ 
    if (this->combination.size() == 5){
        for (int i=0; i<4;i++){
            if (this->combination[i].getColor() != this->combination[i+1].getColor()){
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Combo::isStraight(){
    if (this->combination.size() == 5){
        vector<Card> orderedCombination = sort(this->combination);
        for (int i=0; i<4;i++){
            if (orderedCombination[i].value()!=(orderedCombination[i+1].value()-1)){
                return false;
            }
        }
        return true;
    }
    return false;
}


pair<int,float> Combo::getPair(){
    set<int> pairValue;
    pair<int,float> pairData; // <nPair, weightValue>
    pairData.second = 0;
    for (int i=0; i<4; i++){
        for (int j=i+1; j<5; j++){
            if (this->combination[i].value() == this->combination[j].value()){
                if (pairValue.count(this->combination[j].value()) == 0){
                    pairData.second += this->combination[j].weightValue();
                    pairValue.insert(this->combination[i].value());
                }
            }
        }
    }
    pairData.first = pairValue.size();    
    return pairData;
}

pair<int,float> Combo:: getNOfKind(){
    pair<int,float> NOfKindData; // <nKind, weightValue>
    // default
    NOfKindData.first = 1; 
    NOfKindData.second = 0;
    // collect the data
    for (int i=0; i<4; i++){
        int nTemp = 1; // menyimpan sementara nOfKind untuk evaluasi setiap card 
        float weightValue = 0;
        for (int j=i+1; j<5; j++){
            if (this->combination[i].value() == this->combination[j].value()){
                weightValue+= this->combination[j].weightValue();
                nTemp++;
            }
        }
        weightValue+=this->combination[i].weightValue();
        if (nTemp>NOfKindData.first){ // Jika ditemukan angka sama lebih banyak
            NOfKindData.first=nTemp;
            NOfKindData.second = weightValue;
        } 
    }
    return NOfKindData;
}

void Combo::setComboType(){
    // Mencari jenis combinasi
    pair<int,float> nOfKindData = getNOfKind(); // <NOfKind, weightValue>
    pair<int,float> pairData{0,0}; // <NPair, weightValue>
    if (nOfKindData.first==2){
        pairData = getPair(); //Jika nOfKind=2, minimal ada satu pair, lakukan pengecekan pair
    }
    if (isFlush()){
        if(isStraight()){
            this->type="Straight Flush";
        } else {
            this->type="Flush";
        }
        this->valueCombo = this->basicValue();
    } else if (nOfKindData.first==4){
        this->type="Four of a Kind";
        this->valueCombo = nOfKindData.second;
    } else if (nOfKindData.first==3){
        this->valueCombo = nOfKindData.second;
        if (pairData.first==2){ // Dalam kasus ini, akan terbaca dua pair => three of kind dan pair
            this->type="Full House";
            this->valueCombo += pairData.second;
        } else {
            this->type="Three of a Kind";
        }
    } else if (isStraight()){
        this->type="Straight";
        this->valueCombo = this->basicValue();
    } else if(pairData.first==2){
        this->type="Two Pair";
        this->valueCombo = pairData.second;
    } else if(pairData.first==1){
        this->type="Pair";
        this->valueCombo = pairData.second;
    } else {
        this->type="High Card";
        this->valueCombo = (max<Card>(this->combination)).weightValue();
    }
}

float Combo::value(){
    if (this->type == "unknown"){
        setComboType();
        this->valueCombo += thresholdCombo[this->type];
    }
    return this->valueCombo;
}

float Combo::basicValue(){
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