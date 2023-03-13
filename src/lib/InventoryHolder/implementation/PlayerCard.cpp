#include "../header/PlayerCard.hpp"

PlayerCard::PlayerCard(Card card1, Card card2, AbilityCard* abilityCard, int ID) {
    this->playerCard.first = card1;
    this->playerCard.second = card2;
    this->abilityCard = abilityCard;
    this->ID = ID;
    this->playerCardCount = 2;
}

PlayerCard::PlayerCard(const PlayerCard& playerCard) {
    this->playerCard.first = playerCard.playerCard.first;
    this->playerCard.second = playerCard.playerCard.second;
    this->abilityCard = playerCard.abilityCard;
    this->ID = playerCard.ID;
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

void PlayerCard::setAbilityCard(AbilityCard* card) {
    this->abilityCard = card;
}

void PlayerCard::setID(int ID) {
    this->ID = ID;
}

Card PlayerCard::getFirstPlayerCard() {
    return this->playerCard.first;
}

Card PlayerCard::getSecondPlayerCard() {
    return this->playerCard.second;
}

AbilityCard* PlayerCard::getAbilityCard() {
    return this->abilityCard;
}

int PlayerCard::getID() {
    return this->ID;
}

int PlayerCard::getPlayerCardCount() {
    return this->playerCardCount;
}

PlayerCard& PlayerCard::operator+(Card card) {
    if (playerCard.first.getColor() == "unknown") {
        playerCard.first = card;
        this->playerCardCount++;
    } else if (playerCard.second.getColor() == "unknown") {
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
    this->ID = playerCard.ID;
    this->playerCardCount = 2;
    return *this;
}

void PlayerCard::printCard() {
    cout << "Player Card" << endl;
    cout << "Owner ID: " << ID << endl;
    cout << "  Card 1: " << endl;
    cout << "    Color: " << playerCard.first.getColor() << endl;
    cout << "    Value: " << playerCard.first.value() << endl << endl;
    cout << "  Card 2: " << endl;
    cout << "    Color: " << playerCard.second.getColor() << endl;
    cout << "    Value: " << playerCard.second.value() << endl << endl;
    cout << "  Ability Card: " << endl;
    cout << "    Ability: " << abilityCard->getAbilityCard() << endl;
    cout << endl;
}