#include "../header/DeckCard.hpp"

DeckCard::DeckCard() {
    // Random Card
    this->deckCardCount = 52;
    vector<Card> deckCard;
    for (int i = 1; i <= 13; i++) {
        for (int j = 0; j < 4; j++) {
            if (j == 0) {
                deckCard.push_back(Card(i, "Merah"));
            }
            else if (j == 1) {
                deckCard.push_back(Card(i, "Kuning"));
            }
            else if (j == 2) {
                deckCard.push_back(Card(i, "Hijau"));
            }
            else if (j == 3) {
                deckCard.push_back(Card(i, "Biru"));
            }
        }
    }
    random_device rd;
    mt19937 g(rd());
    shuffle(deckCard.begin(), deckCard.end(), g);

    this->deckCard = deckCard;
}

DeckCard::DeckCard(string filename) {
    // Read from file
    ifstream file;
    file.open(filename);

    if (file.is_open()) {
        string line;
        vector<Card> deckCard;
        while (getline(file, line)) {
            int value = stoi(line.substr(0, line.find(" ")));
            string color = line.substr(line.find(" ") + 1, line.length());
            deckCard.push_back(Card(value, color));
        }
        this->deckCard = deckCard;
        this->deckCardCount = deckCard.size();
    }
    else {
        cout << "File not found" << endl;
    }
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

Card DeckCard::takeCard() {
    Card taken = deckCard.back();

    deckCardCount--;
    deckCard.pop_back();

    return taken;
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

Card DeckCard::takeCard(){
    Card tempCard = deckCard.back();

    deckCardCount--;
    deckCard.pop_back();

    return tempCard;
}