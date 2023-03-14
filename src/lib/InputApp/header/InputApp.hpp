// InputApp.hpp

#ifndef IOAPP_HPP
#define IOAPP_HPP

#include <iostream>
#include <string>
#include "../../color.h"
#include "../../Exceptions/header/Exceptions.hpp"

using namespace std;

class InputApp
{
private:
    string strInput;
    int intInput;

public:
    // constructor
    InputApp();
    InputApp(string,int);
    InputApp(const InputApp&);
    
    // getter and setter
    string getStrInput() const;
    int gerIntInput() const;
    void setStrInput(string str);
    void setIntInput(int i);

    /* 
    Meminta Masukan berupa string
    */
    void takeStrInput();

    /* 
    Meminta masukan berupa int bebas
     */
    void takeIntInput();

    /* 
    Meminta masukan berupa integer dengan batas 1 sampai nmaks 
    throw "Input out of range" jika diluar batas nmaks
    throw "Input must be a number from 1 to "+ to_string(nmaks) jika input bukan integer
    */
    void takeIntInput(int nmkas);
}; 

#endif