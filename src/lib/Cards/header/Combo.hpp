#ifndef COMBO_HPP
#define COMBO_HPP

#include "Valuable.hpp"
#include "Card.hpp"
#include "CapsaCard.hpp"
#include <vector>
#include <set>

template <class C>
class Combo: public Valuable{
    private:
        vector<C> combination;
        float valueCombo; 
        string type;
        static map<string, float> thresholdCombo;

    public:
        Combo();
        Combo(vector<C>& combination); // Combination sudah terurut sesuai besar nilai kartu
        ~Combo();
        string getType();
        bool isFlush();
        bool isStraight();
        pair<int,float> getPair();
        pair<int,float> getNOfKind();
        vector<C> getCombination();
        void setComboType();
        float value();
        bool operator>(Combo<C>& combo);
        bool operator>=(Combo<C>& combo);
        bool operator==(Combo<C>& combo);
        bool operator<(Combo<C>& combo);
        // Combo& operator=(Combo& combo);
        void print();
};
#endif
