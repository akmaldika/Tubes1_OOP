#include "../header/DeckCard.hpp"

DeckCard::DeckCard(vector<Card> deckCard) {
    this->deckCard = deckCard;
    this->deckCardCount = deckCard.size();
}

DeckCard::DeckCard(const DeckCard& deckCard) {
    this->deckCard = deckCard.deckCard;
    this->deckCardCount = deckCard.deckCard.size();
}

DeckCard::~DeckCard() {
    this->deckCard.clear();
}

void DeckCard::setDeckCard(vector<Card> deckCard) {
    this->deckCard = deckCard;
    this->deckCardCount = deckCard.size();
}

vector<Card> DeckCard::getDeckCard() {
    return this->deckCard;
}

int DeckCard::getDeckCardCount() {
    return this->deckCardCount;
}

DeckCard& DeckCard::operator+(Card card) {
    this->deckCard.push_back(card);
    this->deckCardCount++;
    return *this;
}

DeckCard& DeckCard::operator-(Card card) {
    for (int i = 0; i < deckCard.size(); i++) {
        if (deckCard[i] == card) {
            deckCard.erase(deckCard.begin() + i);
            this->deckCardCount--;
            break;
        }
    }
    return *this;
}

DeckCard& DeckCard::operator=(const DeckCard& deckCard) {
    this->deckCard = deckCard.deckCard;
    this->deckCardCount = deckCard.deckCard.size();
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