#include <iostream>
#include "../header/Combo.hpp"
#include "../header/Card.hpp"
using namespace std;

int main(){
    Card kartu1(1,"hijau");
    Card kartu2(2,"kuning");
    Card kartu3(3,"hijau");
    Card kartu4(4,"hijau");
    Card kartu5(5,"hijau");

    vector<Card> collectionCard{kartu1,kartu2,kartu3,kartu4,kartu5};
    Combo defCombination;
    Combo combination(collectionCard);
    cout<<"isFlush: "<<combination.isFlush()<<endl;
    cout<<"isStraight: "<<combination.isStraight()<<endl;
    cout<<"nPair: "<<combination.getNumOfPair()<<endl;
    cout<<"nOfKind: "<<combination.getNOfKind()<<endl;
    cout<<combination.value()<<endl;
    cout<<"Type: "<<combination.getType()<<endl;

    return 0;
}