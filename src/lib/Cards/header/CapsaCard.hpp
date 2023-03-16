#ifndef CAPSACARD_HPP
#define CAPSACARD_HPP

#include "StandardCard.hpp"
#include "../../color.h"

using namespace std;
class CapsaCard : public StandardCard{
    private:
        string interface; // Biar masukin J,Q,K,A
        string kind;
        static map<string, float> kindFactor;
        static map<string, float> interfaceValue;
    public: 
    // Constructor
        CapsaCard();
        CapsaCard(string interface, string kind); 

    // Methods
        string getColor();
        string interfaceVal();
        float value();
        float weightValue();
        static map<string, float> getKindFactor();
        static map<string, float> getInterfaceValue();
        bool operator>(CapsaCard& card);
        bool operator==(CapsaCard& card);
        bool operator<(CapsaCard& card);
        void print(); // Print kartu dalam bentuk kartu
        // Contoh
        // .------..------..------..------.
        // |C.--. ||A.--. ||R.--. ||D.--. |
        // | :/\: || (\/) || :(): || :/\: |
        // | :\/: || :\/: || ()() || (__) |
        // | '--'C|| '--'A|| '--'R|| '--'D|
        // `------'`------'`------'`------'
};

#endif