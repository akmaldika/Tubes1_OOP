#include "../header/PlayerCard.hpp"

PlayerCard::PlayerCard() {
    this->playerCard.first = Card();
    this->playerCard.second = Card();
    this->abilityCard = new AbilityCard();
    this->ID = 0;
    this->playerCardCount = 0;
}

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

Card PlayerCard::getFirstPlayerCard() const{
    return this->playerCard.first;
}

Card PlayerCard::getSecondPlayerCard() const{
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
    cout << LIGHT_RED << UNDERLINE << "Player Card" << RESET << endl;
    cout << WHITE << "Owner ID: " << YELLOW << ID << RESET << endl;
    cout << WHITE << "Card 1: " << RESET << endl;
    playerCard.first.print();
    cout << WHITE << "Card 2: " << RESET << endl;
    playerCard.second.print();
    cout << WHITE << "Ability Card: " << RESET << endl;
    cout << WHITE << "  Ability: " << YELLOW << abilityCard->getAbilityCard() << RESET << endl;
    cout << endl;
}