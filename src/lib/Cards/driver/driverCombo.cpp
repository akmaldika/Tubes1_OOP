#include <iostream>
#include "../header/Combo.hpp"
#include "../header/Card.hpp"
using namespace std;

int main(){
    Card kartu1(1,"hijau");
    Card kartu2(2,"hijau");
    Card kartu3(3,"hijau");
    Card kartu4(4,"hijau");
    Card kartu5(5,"hijau");
    Card kartu6(6,"hijau");
    Card kartu7(7,"hijau");

    vector<Card> collectionCard1{kartu3,kartu4,kartu5,kartu6,kartu7};
    vector<Card> collectionCard2{kartu3, kartu4, kartu5, kartu6, kartu7};
    Combo defCombination;
    Combo combination1(collectionCard1);
    Combo combination2(collectionCard2);
    cout<<"isFlush: "<<combination1.isFlush()<<endl;
    cout<<"isStraight: "<<combination1.isStraight()<<endl;
    cout<<"nPair: "<<combination1.getNumOfPair()<<endl;
    cout<<"nOfKind: "<<combination1.getNOfKind()<<endl;
    cout<<combination1.value()<<endl;
    cout<<"Type: "<<combination1.getType()<<endl;

    if (combination1>combination2){
        cout<< "Kombinasi pertama lebih besar daripada kombinasi kedua"<<endl;
    } else if (combination1==combination2){
        cout<<"Kombinasi pertama sama dengan kombinasi kedua"<<endl;
    } else if(combination1<combination2){
        cout<<"Kombinasi pertama lebih kecil daripada kombinasi kedua"<<endl;
    }

    return 0;
}