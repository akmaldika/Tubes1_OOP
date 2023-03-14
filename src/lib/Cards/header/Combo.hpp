#ifndef COMBO_HPP
#define COMBO_HPP

#include "Valuable.hpp"
#include "Card.hpp"
#include <vector>
#include <set>

class Combo: public Valuable{
    private:
        vector<Card> combination;
        float valueCombo; 
        string type;
        static map<string, float> thresholdCombo;

    public:
        Combo();
        Combo(vector<Card>& combination); // Combination sudah terurut sesuai besar nilai kartu
        ~Combo();
        string getType();
        bool isFlush();
        bool isStraight();
        pair<int,float> getPair();
        pair<int,float> getNOfKind();
        void setComboType();
        float value();
        float basicValue();
        bool operator>(Combo& combo);
        bool operator>=(Combo& combo);
        bool operator==(Combo& combo);
        bool operator<(Combo& combo);
        void print();
};
#endif
