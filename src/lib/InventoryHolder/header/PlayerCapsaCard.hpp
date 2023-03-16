#ifndef __PLAYER_CAPSA_CARD_HPP__
#define __PLAYER_CAPSA_CARD_HPP__

#include "../../Cards/header/CapsaCard.hpp"
#include "../../Cards/header/Combo.hpp"
#include "../../utilityFunction.cpp"
#include "InventoryHolder.hpp"
#include <vector>

class PlayerCapsaCard : public InventoryHolder {
    private:
        vector<CapsaCard> deckCapsa;
        Combo<CapsaCard> front;     // 3
        Combo<CapsaCard> middle;    // 5
        Combo<CapsaCard> back;      // 5
        int ID; // id player pemilik kartu ini

    public:
        // Constructor
        PlayerCapsaCard();
        PlayerCapsaCard(vector<CapsaCard> deckCapsa, int ID);

        // Copy Constructor
        PlayerCapsaCard(const PlayerCapsaCard& playerCard);

        // Destructor
        ~PlayerCapsaCard();

        // Setter and Getter
        void setDeckCapsa(vector<CapsaCard> deckCapsa);
        void setFrontCombo(Combo<CapsaCard> front);
        void setMiddleCombo(Combo<CapsaCard> middle);
        void setBackCombo(Combo<CapsaCard> back);
        void setID(int ID);
        vector<CapsaCard> getDeckCapsa() const;
        Combo<CapsaCard> getFrontCombo() const;
        Combo<CapsaCard> getMiddleCombo() const;
        Combo<CapsaCard> getBackCombo() const;
        int getID() const;

        // Method
        void eraseFromDeck(vector<CapsaCard>);
        Combo<CapsaCard> calculateCombo();
        void printCard();
};

#endif