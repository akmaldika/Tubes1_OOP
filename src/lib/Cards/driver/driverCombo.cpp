#include <iostream>
#include "../header/Combo.hpp"
#include "../header/Card.hpp"
using namespace std;

int main(){
    Card kartu1h(1,"hijau");
    Card kartu2h(2,"hijau");
    Card kartu2m(2,"merah");
    Card kartu2b(2,"biru");
    Card kartu2k(2,"kuning");
    Card kartu3h(3,"hijau");
    Card kartu3k(3,"kuning");
    Card kartu4h(4,"hijau");
    Card kartu4k(4,"kuning");
    Card kartu5h(5,"hijau");
    Card kartu5m(5,"merah");
    Card kartu5k(5,"kuning");
    Card kartu6h(6,"hijau");
    Card kartu6k(6,"kuning");
    Card kartu7h(7,"hijau");
    Card kartu7k(7,"kuning");
    Card kartu7m(7,"merah");
    Card kartu7b(7,"biru");
    Card kartu9m(9, "merah");
    Card kartu9b(9, "biru");
    Card kartu9h(9, "hijau");
    Card kartu9k(9, "kuning");
    Card kartu10h(10, "hijau");
    Card kartu10k(10, "kuning");
    Card kartu10m(10, "merah");
    Card kartu10b(10, "biru");
    Card kartu12h(12,"hijau");
    Card kartu12m(12,"merah");
    Card kartu12k(12,"kuning");
    Card kartu12b(12,"biru");
    Card kartu13m(13,"merah");
    Card kartu13k(13,"kuning");


    vector<Card> collectionCard2{kartu2h,kartu3h,kartu4h,kartu7h, kartu9h};
    vector<Card> collectionCard1{kartu2k, kartu3k, kartu4k, kartu5k,kartu6k};
    Combo<Card> defCombination;
    Combo<Card> combination1(collectionCard1);
    Combo<Card> combination2(collectionCard2);
    cout<<"isFlush: "<<combination1.isFlush()<<endl;
    cout<<"isStraight: "<<combination1.isStraight()<<endl;
    cout<<"nPair: "<<combination1.getPair().first<<endl;
    cout<<"nOfKind: "<<combination1.getNOfKind().first<<endl;
    cout<<combination1.value()<<endl;
    cout<<"Type1: "<<combination1.getType()<<endl;
    combination1.print();

    if (combination1<combination2){
        cout<< "Kombinasi pertama lebih kecil daripada kombinasi kedua"<<endl;
    } else if (combination1==combination2){
        cout<<"Kombinasi pertama sama dengan kombinasi kedua"<<endl;
    } else if(combination1>combination2){
        cout<<"Kombinasi pertama lebih besar daripada kombinasi kedua"<<endl;
    }
    cout<<"Type2: "<<combination2.getType()<<endl;
    combination2.print();
    cout<<combination2.value()<<endl;
    return 0;
}