#ifndef __PLAYER_CARD_HPP__
#define __PLAYER_CARD_HPP__

#include "../../AbilityCard/header/AbilityCard.hpp"
#include "InventoryHolder.hpp"

// Class PlayerCard
class PlayerCard : public InventoryHolder{
    private:
        pair<Card, Card> playerCard;
        AbilityCard* abilityCard;
        int ID; // id player pemilik kartu ini
        int playerCardCount;

    public:
        // Constructor
        PlayerCard();
        PlayerCard(Card card1, Card card2, AbilityCard* abilityCard, int ID);

        // Copy Constructor
        PlayerCard(const PlayerCard& playerCard);

        // Destructor
        ~PlayerCard();

        // Setter and Getter
        void setFirstPlayerCard(Card card);
        void setSecondPlayerCard(Card card);
        void setAbilityCard(AbilityCard* card);
        void setID(int ID);
        Card getFirstPlayerCard() const;
        Card getSecondPlayerCard() const;
        AbilityCard* getAbilityCard();
        int getID();
        int getPlayerCardCount();

        // Method
        PlayerCard& operator+(Card card);                       // Operator Overloading (add card)
        PlayerCard& operator-(Card card);                       // Operator Overloading (remove card)
        PlayerCard& operator=(const PlayerCard& playerCard);    // Operator Overloading (assignment)
        void printCard();
};

#endif