#ifndef __DECK_ABILITY_CARD_HPP__
#define __DECK_ABILITY_CARD_HPP__

#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include "InventoryHolder.hpp"
#include "../../AbilityCard/header/AbilityCard.hpp"
#include "../../AbilityCard/header/Abilityless.hpp"
#include "../../AbilityCard/header/Quadruple.hpp"
#include "../../AbilityCard/header/Quarter.hpp"
#include "../../AbilityCard/header/Reroll.hpp"
#include "../../AbilityCard/header/ReverseDirection.hpp"
#include "../../AbilityCard/header/SwapCard.hpp"
#include "../../AbilityCard/header/Switch.hpp"

class DeckAbilityCard : public InventoryHolder{
    private:
        // Attribute
        vector<AbilityCard*> deckAbilityCard;
        int deckAbilityCardCount;

    public:
        // Constructor
        DeckAbilityCard();                     // Default Constructor (Random Card)
        DeckAbilityCard(string filename);      // Constructor (Read from file)

        // Copy Constructor
        DeckAbilityCard(const DeckAbilityCard& deckAbilityCard);

        // Destructor
        ~DeckAbilityCard();

        // Setter and Getter
        void setDeckAbilityCard(vector<AbilityCard*> deckAbilityCard);
        vector<AbilityCard*> getDeckAbilityCard();
        int getDeckAbilityCardCount();

        // Method
        AbilityCard* takeCard();                                              // Take card from deck (top card)
        DeckAbilityCard& operator+(AbilityCard* card);                        // Operator Overloading (add card)
        DeckAbilityCard& operator-(AbilityCard* card);                        // Operator Overloading (remove card)
        DeckAbilityCard& operator=(const DeckAbilityCard& deckAbilityCard);   // Operator Overloading (assignment)
        void printCard();
};

#endif