#include "../header/DeckAbilityCard.hpp"

DeckAbilityCard::DeckAbilityCard() {
    // Random Card
    this->deckAbilityCardCount = 7;
    vector<AbilityCard*> deckAbilityCard;
    deckAbilityCard.push_back(new Abilityless());
    deckAbilityCard.push_back(new Quadruple());
    deckAbilityCard.push_back(new Quarter());
    deckAbilityCard.push_back(new Reroll());
    deckAbilityCard.push_back(new ReverseDirection());
    deckAbilityCard.push_back(new SwapCard());
    deckAbilityCard.push_back(new Switch());

    random_device rd;
    mt19937 g(rd());
    shuffle(deckAbilityCard.begin(), deckAbilityCard.end(), g);

    this->deckAbilityCard = deckAbilityCard;
}

DeckAbilityCard::DeckAbilityCard(string filename) {
    // Read from file
    ifstream file;
    file.open(filename);
    try{
        if (file.is_open()) {
            string line;
            vector<AbilityCard*> deckAbilityCard;
            string ability;
            while (file >> ability) {
                if (ability == "Abilityless") {
                    deckAbilityCard.push_back(new Abilityless());
                }
                else if (ability == "Quadruple") {
                    deckAbilityCard.push_back(new Quadruple());
                }
                else if (ability == "Quarter") {
                    deckAbilityCard.push_back(new Quarter());
                }
                else if (ability == "Reroll") {
                    deckAbilityCard.push_back(new Reroll());
                }
                else if (ability == "ReverseDirection") {
                    deckAbilityCard.push_back(new ReverseDirection());
                }
                else if (ability == "SwapCard") {
                    deckAbilityCard.push_back(new SwapCard());
                }
                else if (ability == "Switch") {
                    deckAbilityCard.push_back(new Switch());
                }
            }
            this->deckAbilityCard = deckAbilityCard;
            this->deckAbilityCardCount = deckAbilityCard.size();
        }
        else {
            throw FileNotFoundException(filename);
        }
    }
    catch(FileNotFoundException& err){
        cout<<err.what()<<endl;
    }
}

DeckAbilityCard::DeckAbilityCard(const DeckAbilityCard& deckAbilityCard) {
    this->deckAbilityCard = deckAbilityCard.deckAbilityCard;
    this->deckAbilityCardCount = deckAbilityCard.deckAbilityCard.size();
}

DeckAbilityCard::~DeckAbilityCard() {
    this->deckAbilityCard.clear();
}

void DeckAbilityCard::setDeckAbilityCard(vector<AbilityCard*> deckAbilityCard) {
    this->deckAbilityCard = deckAbilityCard;
    this->deckAbilityCardCount = deckAbilityCard.size();
}

vector<AbilityCard*> DeckAbilityCard::getDeckAbilityCard() {
    cout << "Makan nih ability"<<endl;
    return this->deckAbilityCard;
}

int DeckAbilityCard::getDeckAbilityCardCount() {
    return this->deckAbilityCardCount;
}

AbilityCard* DeckAbilityCard::takeCard() {
    AbilityCard* taken = deckAbilityCard.back();

    deckAbilityCardCount--;
    deckAbilityCard.pop_back();

    return taken;
}

DeckAbilityCard& DeckAbilityCard::operator+(AbilityCard* abilityCard) {
    this->deckAbilityCard.push_back(abilityCard);
    this->deckAbilityCardCount++;

    return *this;
}

DeckAbilityCard& DeckAbilityCard::operator-(AbilityCard* abilityCard) {
    for (int i = 0; i < this->deckAbilityCard.size(); i++) {
        if (this->deckAbilityCard[i]->getAbilityCard() == abilityCard->getAbilityCard()) {
            this->deckAbilityCard.erase(this->deckAbilityCard.begin() + i);
            this->deckAbilityCardCount--;
            break;
        }
    }

    return *this;
}

DeckAbilityCard& DeckAbilityCard::operator=(const DeckAbilityCard& deckAbilityCard) {
    this->deckAbilityCard = deckAbilityCard.deckAbilityCard;
    this->deckAbilityCardCount = deckAbilityCard.deckAbilityCard.size();

    return *this;
}

void DeckAbilityCard::printCard() {
    for (int i = 0; i < this->deckAbilityCard.size(); i++) {
        cout << WHITE << "Deck Ability Card " << i + 1 << RESET << endl;
        cout << WHITE << "  Ability: " << YELLOW << this->deckAbilityCard[i]->getAbilityCard() << RESET << endl;
        cout << endl;
    }
}