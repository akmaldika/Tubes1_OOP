// InputApp.hpp

#ifndef IOAPP_HPP
#define IOAPP_HPP

#include <iostream>
#include <string>
#include <exception>
#include "../../color.h"

using namespace std;

class InputApp
{
private:
    string strInput;
    int intInput;

public:
    /// @brief Default constructor
    InputApp();
    InputApp(string,int);
    
    
    string getStrInput() const;
    int gerIntInput() const;
    void setStrInput(string str);
    void setIntInput(int i);

    void takeStrInput();
    void takeIntInput();
    void takeIntInput(int nmkas);
}; 

#endif