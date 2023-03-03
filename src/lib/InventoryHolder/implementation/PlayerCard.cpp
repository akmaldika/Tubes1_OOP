#include "../header/PlayerCard.hpp"

PlayerCard::PlayerCard(Card card1, Card card2, Card abilityCard, string owner) {
    this->playerCard.first = card1;
    this->playerCard.second = card2;
    this->abilityCard = abilityCard;
    this->owner = owner;
    this->playerCardCount = 2;
}

PlayerCard::PlayerCard(const PlayerCard& playerCard) {
    this->playerCard.first = playerCard.playerCard.first;
    this->playerCard.second = playerCard.playerCard.second;
    this->abilityCard = playerCard.abilityCard;
    this->owner = playerCard.owner;
    this->playerCardCount = 2;
}

PlayerCard::~PlayerCard() {

}

void PlayerCard::setFirstPlayerCard(Card card) {
    this->playerCard.first = card;
}

void PlayerCard::setSecondPlayerCard(Card card) {
    this->playerCard.second = card;
}

void PlayerCard::setAbilityCard(Card card) {
    this->abilityCard = card;
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

Card PlayerCard::getAbilityCard() {
    return this->abilityCard;
}

string PlayerCard::getOwner() {
    return this->owner;
}

int PlayerCard::getPlayerCardCount() {
    return this->playerCardCount;
}

PlayerCard& PlayerCard::operator+(Card card) {
    if (playerCard.first.getCategory() == "unknown") {
        playerCard.first = card;
        this->playerCardCount++;
    } else if (playerCard.second.getCategory() == "unknown") {
        playerCard.second = card;
        this->playerCardCount++;
    }
    return *this;
}

PlayerCard& PlayerCard::operator-(Card card) {
    if (this->playerCard.first == card) {
        playerCard.first = Card();
        this->playerCardCount--;
    } else if (this->playerCard.second == card) {
        playerCard.second = Card();
        this->playerCardCount--;
    }
    return *this;
}

PlayerCard& PlayerCard::operator=(const PlayerCard& playerCard) {
    this->playerCard.first = playerCard.playerCard.first;
    this->playerCard.second = playerCard.playerCard.second;
    this->abilityCard = playerCard.abilityCard;
    this->owner = playerCard.owner;
    this->playerCardCount = 2;
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
    cout << "    Value: " << playerCard.second.value() << endl << endl;
    cout << "  Ability Card: " << endl;
    cout << "    Category: " << abilityCard.getCategory() << endl;
    cout << "    Color: " << abilityCard.getColor() << endl;
    cout << "    Ability: " << abilityCard.getAbility() << endl;
    cout << "    Value: " << abilityCard.value() << endl;
    cout << endl;
}