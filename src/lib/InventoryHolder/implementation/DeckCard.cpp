#include "DeckCard.hpp"

int DeckCard::deckCardCount = 0;

DeckCard::DeckCard(vector<Card> deckCard) {
    this->deckCard = deckCard;
    deckCardCount = deckCard.size();
}

DeckCard::DeckCard(const DeckCard& deckCard) {
    this->deckCard = deckCard.deckCard;
    deckCardCount = deckCard.deckCard.size();
}

DeckCard::~DeckCard() {
    deckCardCount = 0;
}

void DeckCard::setDeckCard(vector<Card> deckCard) {
    this->deckCard = deckCard;
    this->deckCardCount = deckCard.size();
}

vector<Card> DeckCard::getDeckCard() {
    return this->deckCard;
}

int DeckCard::getDeckCardCount() {
    return deckCardCount;
}

DeckCard& DeckCard::operator+(Card card) {
    this->deckCard.push_back(card);
    deckCardCount++;
    return *this;
}

DeckCard& DeckCard::operator-(Card card) {
    for (int i = 0; i < deckCard.size(); i++) {
        if (deckCard[i].getAbility() == card.getAbility() && deckCard[i].getColor() == card.getColor() && deckCard[i].getCategory() == card.getCategory() && deckCard[i].value() == card.value()) {
            deckCard.erase(deckCard.begin() + i);
            deckCardCount--;
            break;
        }
    }
    return *this;
}

void DeckCard::printCard() {
    for (int i = 0; i < deckCard.size(); i++) {
        cout << "Deck Card " << i + 1 << endl;
        cout << "  Color: " << deckCard[i].getColor() << endl;
        cout << "  Category: " << deckCard[i].getCategory() << endl;
        cout << "  Ability: " << deckCard[i].getAbility() << endl;
        cout << "  Value: " << deckCard[i].value() << endl;
        cout << endl;
    }
}