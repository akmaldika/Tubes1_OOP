#include <iostream>
#include "../header/Card.hpp"
using namespace std;

int main(){
    Card kartu1;
    Card kartu2(3,"hijau");
    Card kartu3("quadruple");

    cout<<"Color kartu1: "<<kartu1.getColor()<<endl;
    cout<<"Category kartu1: "<<kartu1.getCategory()<<endl;
    cout<<"Ability kartu1: "<<kartu1.getAbility()<<endl;
    cout<<"value kartu1: "<<kartu1.value()<<endl;
    cout<<"Color kartu2: "<<kartu2.getColor()<<endl;
    cout<<"Category kartu2: "<<kartu2.getCategory()<<endl;
    cout<<"Ability kartu2: "<<kartu2.getAbility()<<endl;
    cout<<"value kartu2: "<<kartu2.value()<<endl;
    cout<<"Color kartu3: "<<kartu3.getColor()<<endl;
    cout<<"Category kartu3: "<<kartu3.getCategory()<<endl;
    cout<<"Ability kartu3: "<<kartu3.getAbility()<<endl;
    cout<<"value kartu3: "<<kartu3.value()<<endl;

    kartu1.getColor();    


    return 0;
}