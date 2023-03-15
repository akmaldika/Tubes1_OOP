#include "../header/Combo.hpp"
#include "../../utilityFunction.cpp"
/*Static*/
map<string, float> Combo::thresholdCombo {
    {"High Card", 0.0},
    {"Pair", 1.39}, // highcard single: 1.39
    {"Two Pair", 2.78}, // highest pair : 1.39 + thresholdPair
    {"Three of a Kind", 4.17}, // highest two pair: 1.39 + thresholdTwoPair
    {"Straight", 5.56}, // highest three of a kind: 1.39 + thresholdThreeOfAKind 
    {"Flush", 6.95}, // highest straight: 1.39 + thresholdStraight
    {"Full House", 8.34}, // highest flush: 1.39 + thresholdFlush
    {"Four of a Kind", 9.73}, // highest full house: 1.39 + thresholdFullHouse
    {"Straight Flush", 11.12} // highest four of a kind: 1.39 + thresHoldFourOfAKind
    };

/*Non-Static*/
Combo::Combo(){
    this->type = "unknown";
    this->valueCombo = 0;
}

Combo::Combo(vector<Card>& combination){
    if(combination.size() > 0){
        for (auto i= combination.begin(); i!=combination.end(); i++){
            this->combination.push_back(*i);
        }
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
    float weightPivot;
    float weightNonPivot;
    pairData.second = 0; // Max nilai dari pair (perhitungan single card)
    for (int i=0; i<4; i++){
        weightPivot = this->combination[i].weightValue();
        for (int j=i+1; j<5; j++){
            if (this->combination[i].value() == this->combination[j].value()){
                if (pairValue.count(this->combination[j].value()) == 0){
                    weightNonPivot = this->combination[j].weightValue();
                    
                    if (weightNonPivot > weightPivot){
                        weightPivot = weightNonPivot;
                    }
                    
                    if (weightPivot > pairData.second){
                        pairData.second = weightPivot;
                    }

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
    float weightPivot;
    float weightNonPivot;
    // collect the data
    for (int i=0; i<4; i++){
        int nTemp = 1; // menyimpan sementara nOfKind untuk evaluasi setiap card 
        weightPivot = this->combination[i].weightValue();
        for (int j=i+1; j<5; j++){
            if (this->combination[i].value() == this->combination[j].value()){
                weightNonPivot = this->combination[j].weightValue();
                
                if (weightNonPivot > weightPivot){
                    weightPivot = weightNonPivot;
                }
                    
                nTemp++;
            }
        }
        if (nTemp>NOfKindData.first){ // Jika ditemukan angka sama lebih banyak
            NOfKindData.first=nTemp;
            NOfKindData.second = weightPivot;
        } 
    }
    return NOfKindData;
}

void Combo::setComboType(){
    // Mencari jenis combinasi
    pair<int,float> nOfKindData = getNOfKind(); // <NOfKind, weightValue>
    pair<int,float> pairData{0,0}; // <NPair, weightValue>
    if (nOfKindData.first>=2){
        pairData = getPair(); //Jika nOfKind>=2, minimal ada satu pair, lakukan pengecekan pair
    }
    if (isFlush()){
        if(isStraight()){
            this->type="Straight Flush";
            this->valueCombo = max<Card>(this->combination).weightValue();
        } else {
            this->type="Flush";
            this->valueCombo = max<Card>(this->combination).value();
        }
    } else if (nOfKindData.first==4){
        this->type="Four of a Kind";
        this->valueCombo = nOfKindData.second;
    } else if (nOfKindData.first==3){
        this->valueCombo = nOfKindData.second;
        if (pairData.first==2){ // Dalam kasus ini, akan terbaca dua pair => three of kind dan pair
            this->type="Full House";
        } else {
            this->type="Three of a Kind";
        }
    } else if (isStraight()){
        this->type="Straight";
        this->valueCombo = max<Card>(this->combination).weightValue();
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
    if (this->type == "unknown" && (this->combination.size()>0)){
        setComboType();
        this->valueCombo += thresholdCombo[this->type];
    }
    return this->valueCombo;
}

bool Combo::operator>(Combo& combo){
    if (*this==combo){ // Kasus untuk flush, saat angka tertinggi sama
        vector<Card> sortedThisCombination = sort<Card>(this->combination);
        vector<Card> sortedComboCombination = sort<Card>(combo.combination);
        // Bandingkan angka tertinggi berikutnya
        if (sortedThisCombination[3].value() == sortedComboCombination[3].value()){
            if(sortedThisCombination[2].value() == sortedComboCombination[2].value()){
                if (sortedThisCombination[1].value() == sortedComboCombination[1].value()){
                    if (sortedThisCombination[0].value() == sortedComboCombination[0].value()){
                        // Jika semua angka pada kedua kombinasi adalah sama, bandingkan dengan warna (terwakili oleh weight value)
                        return (sortedThisCombination[0].weightValue() > sortedComboCombination[0].weightValue());
                    }
                    return (sortedThisCombination[0].value() > sortedComboCombination[0].value());
                }
                return (sortedThisCombination[1].value() > sortedComboCombination[1].value());
            }
            return (sortedThisCombination[2].value() > sortedComboCombination[2].value());
        }
        return (sortedThisCombination[3].value() > sortedComboCombination[3].value());
    }
    return (this->value() > combo.value());
}

bool Combo::operator>=(Combo& combo){
    return (this->value() >= combo.value());
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