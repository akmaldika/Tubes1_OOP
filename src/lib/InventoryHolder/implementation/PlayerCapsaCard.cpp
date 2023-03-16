#include "../header/PlayerCapsaCard.hpp"

PlayerCapsaCard::PlayerCapsaCard() {
    this->deckCapsa = vector<CapsaCard>();
    this->front = Combo<CapsaCard>();
    this->middle = Combo<CapsaCard>();
    this->back = Combo<CapsaCard>();
    this->ID = 0;
}

PlayerCapsaCard::PlayerCapsaCard(vector<CapsaCard> deckCapsa, int ID) {
    this->deckCapsa = deckCapsa;
    this->back = calculateCombo();
    this->eraseFromDeck(this->back.getCombination());
    this->middle = calculateCombo();
    this->eraseFromDeck(this->middle.getCombination());
    this->front = this->deckCapsa;
    this->deckCapsa = vector<CapsaCard>();
    this->ID = ID;
}

PlayerCapsaCard::PlayerCapsaCard(const PlayerCapsaCard& playerCard) {
    this->deckCapsa = playerCard.deckCapsa;
    this->front = playerCard.front;
    this->middle = playerCard.middle;
    this->back = playerCard.back;
    this->ID = playerCard.ID;
}

PlayerCapsaCard::~PlayerCapsaCard() {
    
}

void PlayerCapsaCard::setDeckCapsa(vector<CapsaCard> deckCapsa) {
    this->deckCapsa = deckCapsa;
}

void PlayerCapsaCard::setFrontCombo(Combo<CapsaCard> front) {
    this->front = front;
}

void PlayerCapsaCard::setMiddleCombo(Combo<CapsaCard> middle) {
    this->middle = middle;
}

void PlayerCapsaCard::setBackCombo(Combo<CapsaCard> back) {
    this->back = back;
}

void PlayerCapsaCard::setID(int ID) {
    this->ID = ID;
}

vector<CapsaCard> PlayerCapsaCard::getDeckCapsa() const{
    return this->deckCapsa;
}

Combo<CapsaCard> PlayerCapsaCard::getFrontCombo() const{
    return this->front;
}

Combo<CapsaCard> PlayerCapsaCard::getMiddleCombo() const{
    return this->middle;
}

Combo<CapsaCard> PlayerCapsaCard::getBackCombo() const{
    return this->back;
}

int PlayerCapsaCard::getID() const{
    return this->ID;
}

Combo<CapsaCard> PlayerCapsaCard::calculateCombo() {
    vector<CapsaCard> possibleCombination;      // kombinasi kartu yang mungkin
    vector<Combo<CapsaCard>> listPossibleCombination; // list semua kombinasi kartu yang mungkin

    for (int i = 0; i < (deckCapsa.size() - 4); i++)
        {
            for (int j = i + 1; j < (deckCapsa.size() - 3); j++)
            {
                for (int k = j + 1; k < (deckCapsa.size() - 2); k++)
                {
                    for (int l = k + 1; l < (deckCapsa.size() - 1); l++)
                    {
                        for (int m = l + 1; m < deckCapsa.size(); m++)
                        {
                            possibleCombination = {deckCapsa[i], deckCapsa[j], deckCapsa[k], deckCapsa[l], deckCapsa[m]};
                            Combo<CapsaCard> possibleCombo(deckCapsa);
                            float tempVal = possibleCombo.value(); // Supaya evaluasi tipeya
                            listPossibleCombination.push_back(possibleCombination);
                        }
                    }
                }
            }
        }

    return max<Combo<CapsaCard>>(listPossibleCombination);
}

void PlayerCapsaCard::eraseFromDeck(vector<CapsaCard> cards) {
    for (int i = 0; i < cards.size(); i++) {
        for (int j = 0; j < deckCapsa.size(); j++) {
            if (cards[i] == deckCapsa[j]) {
                deckCapsa.erase(deckCapsa.begin() + j);
            }
        }
    }
}

void PlayerCapsaCard::printCard() {
    cout << "Player " << this->ID << endl;
    cout << "Front: " << endl;
    for (int i = 0; i < this->front.getCombination().size(); i++) {
        this->front.getCombination()[i].print();
    }
    cout << "Middle: " << endl;
    for (int i = 0; i < this->middle.getCombination().size(); i++) {
        this->middle.getCombination()[i].print();
    }
    cout << "Back: " << endl;
    for (int i = 0; i < this->back.getCombination().size(); i++) {
        this->back.getCombination()[i].print();
    }
}