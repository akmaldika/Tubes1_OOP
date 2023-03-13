#ifndef __DECK_CARD_HPP__
#define __DECK_CARD_HPP__

#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
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
        DeckCard();                     // Default Constructor (Random Card)
        DeckCard(string filename);      // Constructor (Read from file)

        // Copy Constructor
        DeckCard(const DeckCard& deckCard);

        // Destructor
        ~DeckCard();

        // Setter and Getter
        void setDeckCard(vector<Card> deckCard);
        vector<Card> getDeckCard();
        int getDeckCardCount();

        // Method
        Card takeCard();                                // Take card from deck (top card)
        DeckCard& operator+(Card card);                 // Operator Overloading (add card)
        DeckCard& operator-(Card card);                 // Operator Overloading (remove card)
        DeckCard& operator=(const DeckCard& deckCard);  // Operator Overloading (assignment)
        void printCard();
};

#endif