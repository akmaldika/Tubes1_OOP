#include "../header/DeckCard.hpp"

DeckCard::DeckCard() {
    // Random Card
    this->deckCardCount = 52;
    vector<Card> deckCard;
    for (int i = 1; i <= 13; i++) {
        for (int j = 0; j < 4; j++) {
            if (j == 0) {
                deckCard.push_back(Card(i, "merah"));
            }
            else if (j == 1) {
                deckCard.push_back(Card(i, "kuning"));
            }
            else if (j == 2) {
                deckCard.push_back(Card(i, "hijau"));
            }
            else if (j == 3) {
                deckCard.push_back(Card(i, "biru"));
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
    try{
        if (file.is_open()) {
            string line;
            vector<Card> deckCard;
            int value;
            string color;
            while (file >> value >> color) {
                deckCard.push_back(Card(value, color));
            }
            this->deckCard = deckCard;
            this->deckCardCount = deckCard.size();
        }
        else {
            throw FileNotFoundException(filename);
        }
    } catch(FileNotFoundException& err){
        cout<<err.what()<<endl;
    }
}

DeckCard::DeckCard(const DeckCard& deckCard) {
    this->deckCard = deckCard.deckCard;
    this->deckCardCount = deckCard.deckCard.size();
}

DeckCard::~DeckCard() {

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
    
    Card taken(deckCard.back().value(), deckCard.back().getColor());
    
    
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
        cout << WHITE << "Deck Card " << i + 1 << RESET << endl;
        deckCard[i].print();
        cout << endl;
    }
}