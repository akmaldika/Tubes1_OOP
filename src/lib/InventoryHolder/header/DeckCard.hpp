#ifndef __DECK_CARD_HPP__
#define __DECK_CARD_HPP__

#include <iostream>
#include "InventoryHolder.hpp"

using namespace std;

// Class DeckCard
class DeckCard : public InventoryHolder{
    private:
        // Attribute
        vector<Card> deckCard;
        int deckCardCount;

    public:
        // Constructor
        /*
            ini aku bingung, kalo gasalah card dalam decknya tuh
            bisa digenerate random atau dari .txt kan yah

            buat skrg aku bikin dulu default constnya (aku anggap di
            generate random dulu) biar gamestate ga error aja sih

            -Naufal
        */
        DeckCard(); 
        DeckCard(vector<Card> deckCard);

        // Copy Constructor
        DeckCard(const DeckCard& deckCard);

        // Destructor
        ~DeckCard();

        // Setter and Getter
        void setDeckCard(vector<Card> deckCard);
        vector<Card> getDeckCard();
        int getDeckCardCount();

        // Method
        DeckCard& operator+(Card card);                 // Operator Overloading (add card)
        DeckCard& operator-(Card card);                 // Operator Overloading (remove card)
        DeckCard& operator=(const DeckCard& deckCard);  // Operator Overloading (assignment)
        void printCard();

        /*
            ambil kartu dari deck, terus dihapus dari deck
            buat pembagian kartu ke pemain sama ke table.
        */
        Card takeCard();
};

#endif