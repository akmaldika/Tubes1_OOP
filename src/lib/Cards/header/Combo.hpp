#ifndef COMBO_HPP
#define COMBO_HPP

#include "Valuable.hpp"
#include "Card.hpp"
#include <vector>
#include <set>
#include <map>

class Combo: public Valuable{
    private:
        vector<Card> combination; 
        string type;
        static map<string, float> thresholdCombo;
        static map<string, float> colorFactor;

    public:
        Combo();
        Combo(vector<Card>& combination); // Combination sudah terurut sesuai besar nilai kartu
        ~Combo();
        string getType();
        bool isFlush();
        bool isStraight();
        int getNumOfPair();
        int getNOfKind();
        void setComboType();
        double value();
        double basicValue();
};



#endif
