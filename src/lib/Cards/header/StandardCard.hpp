#ifndef STANDARDCARD_HPP
#define STANDARDCARD_HPP

#include "Valuable.hpp"
#include <iostream>
#include <map>
using namespace std;
class StandardCard : public Valuable{
    protected:
        int valueCard;
    public: 
    // Methods
        virtual float value()=0;
        virtual float weightValue()=0;
        virtual void print() = 0; // Print kartu dalam bentuk kartu
};

#endif
