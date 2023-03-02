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
        PlayerCard(pair<Card, Card> playerCard, string owner);

        // Copy Constructor
        PlayerCard(const PlayerCard& playerCard);

        // Destructor
        ~PlayerCard();

        // Setter and Getter
        void setPlayerCard(pair<Card, Card> playerCard);
        void setOwner(string owner);
        pair<Card, Card> getPlayerCard();
        string getOwner();
        static int getPlayerCardCount();

        // Method
        PlayerCard& operator+(Card card);    // Operator Overloading (add card)
        PlayerCard& operator-(Card card);    // Operator Overloading (remove card)
        void printCard();
};

#endif