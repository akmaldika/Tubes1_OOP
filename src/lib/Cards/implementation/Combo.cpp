#include "../header/Combo.hpp"
#include "../../utilityFunction.cpp"
/*Static*/
template <class C>
map<string, float> Combo<C>::thresholdCombo {
    {"High Card", 0.0},
    {"Pair", 1.49}, // highcard single: 1.39
    {"Two Pair", 2.98}, // highest pair : 1.39 + thresholdPair
    {"Three of a Kind", 4.47}, // highest two pair: 1.39 + thresholdTwoPair
    {"Straight", 5.96}, // highest three of a kind: 1.39 + thresholdThreeOfAKind 
    {"Flush", 7.45}, // highest straight: 1.39 + thresholdStraight
    {"Full House", 8.94}, // highest flush: 1.39 + thresholdFlush
    {"Four of a Kind", 10.43}, // highest full house: 1.39 + thresholdFullHouse
    {"Straight Flush", 11.92} // highest four of a kind: 1.39 + thresHoldFourOfAKind
    };

/*Non-Static*/
template <class C>
Combo<C>::Combo(){
    this->type = "unknown";
    this->valueCombo = 0;
}

template <class C>
Combo<C>::Combo(vector<C>& combination){
    if(combination.size() > 0){
        for (auto i= combination.begin(); i!=combination.end(); i++){
            this->combination.push_back(*i);
        }
    }
    this->type = "unknown";
    this->valueCombo = 0;
}

template <class C>
Combo<C>::~Combo(){
    this->combination.clear();
}

template <class C>
string Combo<C>::getType(){
    return this->type;
}

template <class C>
bool Combo<C>::isFlush(){ 
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

template <class C>
bool Combo<C>::isStraight(){
    if (this->combination.size() == 5){
        vector<C> orderedCombination = sort(this->combination);
        for (int i=0; i<4;i++){
            if (orderedCombination[i].value()!=(orderedCombination[i+1].value()-1)){
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class C>
pair<int,float> Combo<C>::getPair(){
    set<int> pairValue;
    pair<int,float> pairData; // <nPair, weightValue>
    float weightPivot;
    float weightNonPivot;
    int size = this->combination.size();
    pairData.second = 0; // Max nilai dari pair (perhitungan single card)
    for (int i=0; i<(size-1); i++){
        weightPivot = this->combination[i].weightValue();
        for (int j=i+1; j<size; j++){
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

template <class C>
pair<int,float> Combo<C>:: getNOfKind(){
    pair<int,float> NOfKindData; // <nKind, weightValue>
    // default
    NOfKindData.first = 1; 
    NOfKindData.second = 0;
    float weightPivot;
    float weightNonPivot;
    int size = this->combination.size();
    // collect the data
    for (int i=0; i<(size-1); i++){
        int nTemp = 1; // menyimpan sementara nOfKind untuk evaluasi setiap card 
        weightPivot = this->combination[i].weightValue();
        for (int j=i+1; j<size; j++){
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

template <class C>
vector<C> Combo<C>::getCombination(){
    return this->combination;
}

template <class C>
void Combo<C>::setComboType(){
    // Mencari jenis combinasi
    pair<int,float> nOfKindData = getNOfKind(); // <NOfKind, weightValue>
    pair<int,float> pairData{0,0}; // <NPair, weightValue>
    if (nOfKindData.first>=2){
        pairData = getPair(); //Jika nOfKind>=2, minimal ada satu pair, lakukan pengecekan pair
    }
    if (isFlush()){
        if(isStraight()){
            this->type="Straight Flush";
            this->valueCombo = max<C>(this->combination).weightValue();
        } else {
            this->type="Flush";
            this->valueCombo = max<C>(this->combination).value() * 0.1;
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
        this->valueCombo = max<C>(this->combination).weightValue();
    } else if(pairData.first==2){
        this->type="Two Pair";
        this->valueCombo = pairData.second;
    } else if(pairData.first==1){
        this->type="Pair";
        this->valueCombo = pairData.second;
    } else {
        this->type="High Card";
        this->valueCombo = (max<C>(this->combination)).weightValue();
    }
}

template <class C>
float Combo<C>::value(){
    if (this->type == "unknown" && (this->combination.size()>0)){
        setComboType();
        this->valueCombo += thresholdCombo[this->type];
    }
    return this->valueCombo;
}

template <class C>
bool Combo<C>::operator>(Combo<C>& combo){
    if (*this==combo){ // Kasus untuk flush, saat angka tertinggi sama
        vector<C> sortedThisCombination = sort<C>(this->combination);
        vector<C> sortedComboCombination = sort<C>(combo.combination);
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

template <class C>
bool Combo<C>::operator>=(Combo<C>& combo){
    return (this->value() >= combo.value());
}

template <class C>
bool Combo<C>::operator==(Combo<C>& combo){
    return (this->value() == combo.value());
}
template <class C>
bool Combo<C>::operator<(Combo<C>& combo){
    return (this->value() < combo.value());
}
template <class C>
void Combo<C>::print(){
    for (int i=0; i< this->combination.size();i++){
        this->combination[i].print();
        cout<<endl;
    }
}

// Combo& Combo::operator=(Combo &combo){
//     combination = combo.combination;
//     valueCombo = combo.valueCombo;
//     type = combo.type;

//     return *this;
// }

template class Combo<Card>;
template class Combo<CapsaCard>;