#ifndef __PLAYER_CARD_HPP__
#define __PLAYER_CARD_HPP__

#include <iostream>
#include "InventoryHolder.hpp"

using namespace std;

// Class PlayerCard
class PlayerCard : public InventoryHolder{
    private:
        pair<Card, Card> playerCard;
        string owner;
        static int playerCardCount;

    public:
        // Constructor
        PlayerCard(Card card1, Card card2, string owner);

        // Copy Constructor
        PlayerCard(const PlayerCard& playerCard);

        // Destructor
        ~PlayerCard();

        // Setter and Getter
        void setFirstPlayerCard(Card card);
        void setSecondPlayerCard(Card card);
        void setOwner(string owner);
        Card getFirstPlayerCard();
        Card getSecondPlayerCard();
        string getOwner();
        static int getPlayerCardCount();

        // Method
        PlayerCard& operator+(Card card);    // Operator Overloading (add card)
        PlayerCard& operator-(Card card);    // Operator Overloading (remove card)
        void printCard();
};

#endif