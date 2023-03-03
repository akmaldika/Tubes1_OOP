<<<<<<< HEAD
#ifndef __DECK_CARD_HPP__
#define __DECK_CARD_HPP__

#include <iostream>
#include "InventoryHolder.hpp"

using namespace std;

// Class DeckCard
class DeckCard : public InventoryHolder{
    public:
        // Attribute
        vector<Card> deckCard;
        static int deckCardCount;

        // Constructor
        DeckCard(vector<Card> deckCard);

        // Copy Constructor
        DeckCard(const DeckCard& deckCard);

        // Destructor
        ~DeckCard();

        // Setter and Getter
        void setDeckCard(vector<Card> deckCard);
        vector<Card> getDeckCard();
        static int getDeckCardCount();

        // Method
        DeckCard& operator+(Card card);     // Operator Overloading (add card)
        DeckCard& operator-(Card card);     // Operator Overloading (remove card)
        void printCard();
};

=======
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
};

>>>>>>> 95786990c5ba5c95a3f1d0bab2e4b8e875713d27
#endif