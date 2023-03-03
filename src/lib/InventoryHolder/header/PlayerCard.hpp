#ifndef __PLAYER_CARD_HPP__
#define __PLAYER_CARD_HPP__

#include <iostream>
#include "InventoryHolder.hpp"

using namespace std;

// Class PlayerCard
class PlayerCard : public InventoryHolder{
    private:
        pair<Card, Card> playerCard;
        Card abilityCard;
        string owner;
        int playerCardCount;

    public:
        // Constructor
        PlayerCard(Card card1, Card card2, Card abilityCard, string owner);

        // Copy Constructor
        PlayerCard(const PlayerCard& playerCard);

        // Destructor
        ~PlayerCard();

        // Setter and Getter
        void setFirstPlayerCard(Card card);
        void setSecondPlayerCard(Card card);
        void setAbilityCard(Card card);
        void setOwner(string owner);
        Card getFirstPlayerCard();
        Card getSecondPlayerCard();
        Card getAbilityCard();
        string getOwner();
        int getPlayerCardCount();

        // Method
        PlayerCard& operator+(Card card);                       // Operator Overloading (add card)
        PlayerCard& operator-(Card card);                       // Operator Overloading (remove card)
        PlayerCard& operator=(const PlayerCard& playerCard);    // Operator Overloading (assignment)
        void printCard();
};

#endif