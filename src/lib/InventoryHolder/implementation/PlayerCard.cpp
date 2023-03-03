#include "PlayerCard.hpp"

int PlayerCard::playerCardCount = 0;

PlayerCard::PlayerCard(Card card1, Card card2, string owner) {
    this->playerCard.first = card1;
    this->playerCard.second = card2;
    this->owner = owner;
    playerCardCount = 2;
}

PlayerCard::PlayerCard(const PlayerCard& playerCard) {
    this->playerCard.first = playerCard.playerCard.first;
    this->playerCard.second = playerCard.playerCard.second;
    this->owner = playerCard.owner;
    playerCardCount = 2;
}

PlayerCard::~PlayerCard() {
    playerCardCount = 0;
}

void PlayerCard::setFirstPlayerCard(Card card) {
    this->playerCard.first = card;
}

void PlayerCard::setSecondPlayerCard(Card card) {
    this->playerCard.second = card;
}

void PlayerCard::setOwner(string owner) {
    this->owner = owner;
}

Card PlayerCard::getFirstPlayerCard() {
    return this->playerCard.first;
}

Card PlayerCard::getSecondPlayerCard() {
    return this->playerCard.second;
}

string PlayerCard::getOwner() {
    return this->owner;
}

int PlayerCard::getPlayerCardCount() {
    return playerCardCount;
}

PlayerCard& PlayerCard::operator+(Card card) {
    if (playerCard.first.getCategory() == "unknown") {
        playerCard.first = card;
    } else if (playerCard.second.getCategory() == "unknown") {
        playerCard.second = card;
    } else {
        cout << "Player Card is Full" << endl;
    }
    return *this;
}

PlayerCard& PlayerCard::operator-(Card card) {
    if (playerCard.first.getCategory() == card.getCategory() && playerCard.first.getColor() == card.getColor() && playerCard.first.getAbility() == card.getAbility()) {
        playerCard.first = Card();
    } else if (playerCard.second.getCategory() == card.getCategory() && playerCard.second.getColor() == card.getColor() && playerCard.second.getAbility() == card.getAbility()) {
        playerCard.second = Card();
    } else {
        cout << "Card not found" << endl;
    }
    return *this;
}

void PlayerCard::printCard() {
    cout << "Player Card" << endl;
    cout << "Owner: " << owner << endl;
    cout << "  Card 1: " << endl;
    cout << "    Category: " << playerCard.first.getCategory() << endl;
    cout << "    Color: " << playerCard.first.getColor() << endl;
    cout << "    Ability: " << playerCard.first.getAbility() << endl;
    cout << "    Value: " << playerCard.first.value() << endl << endl;
    cout << "  Card 2: " << endl;
    cout << "    Category: " << playerCard.second.getCategory() << endl;
    cout << "    Color: " << playerCard.second.getColor() << endl;
    cout << "    Ability: " << playerCard.second.getAbility() << endl;
    cout << "    Value: " << playerCard.second.value() << endl;
    cout << endl;
}