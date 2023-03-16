#include <iostream>
#include "../header/CapsaCard.hpp"
using namespace std;

int main(){
    CapsaCard kartu1;
    CapsaCard kartu2("3","diamond");
    CapsaCard kartu4("K","spade");
    CapsaCard kartu5("J","heart");
    CapsaCard kartu6("1","club");

    cout<<"Color kartu1: "<<kartu1.getColor()<<endl;
    cout<<"value kartu1: "<<kartu1.value()<<endl;
    cout<<"Color kartu2: "<<kartu2.getColor()<<endl;
    cout<<"value kartu2: "<<kartu2.value()<<endl;
    kartu2.print();
    cout<<endl;
    cout<<"Color kartu3: "<<kartu4.getColor()<<endl;
    cout<<"value kartu3: "<<kartu4.value()<<endl;
    kartu4.print();
    cout<<endl;
    kartu5.print();
    cout<<endl;
    kartu6.print();
    cout<<endl;
    kartu1.getColor();    

    if(kartu4==kartu5){
        cout<<"kartu pertama sama dengan kartu kedua"<<endl;
    } else {
        if (kartu4>kartu5){
            cout <<"Kartu pertama lebih besar daripada kartu kedua" <<endl;
        } else if(kartu4<kartu5) {
            cout <<"Kartu pertama lebih kecil daripada kartu kedua" <<endl;
        }
    }       

    return 0;
}