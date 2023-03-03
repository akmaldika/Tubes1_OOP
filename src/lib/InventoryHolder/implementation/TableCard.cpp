#include "TableCard.hpp"

int TableCard::tableCardCount = 0;

TableCard::TableCard(vector<Card> tableCard) {
    this->tableCard = tableCard;
    tableCardCount = tableCard.size();
}

TableCard::TableCard(const TableCard& tableCard) {
    this->tableCard = tableCard.tableCard;
    tableCardCount = tableCard.tableCard.size();
}

TableCard::~TableCard() {
    tableCardCount = 0;
}

void TableCard::setTableCard(vector<Card> tableCard) {
    this->tableCard = tableCard;
    this->tableCardCount = tableCard.size();
}

vector<Card> TableCard::getTableCard() {
    return this->tableCard;
}

int TableCard::getTableCardCount() {
    return tableCardCount;
}

TableCard& TableCard::operator+(Card card) {
    this->tableCard.push_back(card);
    tableCardCount++;
    return *this;
}

TableCard& TableCard::operator-(Card card) {
    for (int i = 0; i < tableCard.size(); i++) {
        if (tableCard[i].getAbility() == card.getAbility() && tableCard[i].getColor() == card.getColor() && tableCard[i].getCategory() == card.getCategory() && tableCard[i].value() == card.value()) {
            tableCard.erase(tableCard.begin() + i);
            tableCardCount--;
            break;
        }
    }
    return *this;
}

void TableCard::printCard() {
    for (int i = 0; i < tableCard.size(); i++) {
        cout << "Table Card " << i + 1 << endl;
        cout << "  Color: " << tableCard[i].getColor() << endl;
        cout << "  Category: " << tableCard[i].getCategory() << endl;
        cout << "  Ability: " << tableCard[i].getAbility() << endl;
        cout << "  Value: " << tableCard[i].value() << endl;
        cout << endl;
    }
}