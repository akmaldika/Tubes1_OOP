#include <iostream>
#include "../header/Combo.hpp"
#include "../header/Card.hpp"
using namespace std;

int main(){
    Card kartu1h(1,"hijau");
    Card kartu2h(2,"hijau");
    Card kartu3h(3,"hijau");
    Card kartu3k(3,"kuning");
    Card kartu4h(4,"hijau");
    Card kartu5h(5,"hijau");
    Card kartu6h(6,"hijau");
    Card kartu7h(7,"hijau");
    Card kartu7k(7,"kuning");

    vector<Card> collectionCard1{kartu3h,kartu3k,kartu5h,kartu2h,kartu7k};
    vector<Card> collectionCard2{kartu3k, kartu4h, kartu6h, kartu1h, kartu7h};
    Combo defCombination;
    Combo combination1(collectionCard1);
    Combo combination2(collectionCard2);
    cout<<"isFlush: "<<combination1.isFlush()<<endl;
    cout<<"isStraight: "<<combination1.isStraight()<<endl;
    cout<<"nPair: "<<combination1.getPair().first<<endl;
    cout<<"nOfKind: "<<combination1.getNOfKind().first<<endl;
    cout<<combination1.value()<<endl;
    cout<<"Type1: "<<combination1.getType()<<endl;
    combination1.print();

    if (combination1>combination2){
        cout<< "Kombinasi pertama lebih besar daripada kombinasi kedua"<<endl;
    } else if (combination1==combination2){
        cout<<"Kombinasi pertama sama dengan kombinasi kedua"<<endl;
    } else if(combination1<combination2){
        cout<<"Kombinasi pertama lebih kecil daripada kombinasi kedua"<<endl;
    }
    cout<<"Type2: "<<combination2.getType()<<endl;
    combination2.print();
    cout<<combination2.value()<<endl;
    return 0;
}