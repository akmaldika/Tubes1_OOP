#include "../header/TableCard.hpp"

TableCard::TableCard() {
    vector<Card> emptyCards;
    this->tableCard = emptyCards;
    this->tableCardCount = 0;
}

TableCard::TableCard(vector<Card> tableCard) {
    this->tableCard = tableCard;
    this->tableCardCount = tableCard.size();
}

TableCard::TableCard(const TableCard& tableCard) {
    this->tableCard = tableCard.tableCard;
    this->tableCardCount = tableCard.tableCard.size();
}

TableCard::~TableCard() {

}

void TableCard::setTableCard(vector<Card> tableCard) {
    this->tableCard = tableCard;
    this->tableCardCount = tableCard.size();
}

vector<Card> TableCard::getTableCard() {
    return this->tableCard;
}

int TableCard::getTableCardCount() {
    return this->tableCardCount;
}

TableCard& TableCard::operator+(Card card) {
    this->tableCard.push_back(card);
    this->tableCardCount++;
    return *this;
}

TableCard& TableCard::operator-(Card card) {
    for (int i = 0; i < tableCard.size(); i++) {
        if (tableCard[i] == card) {
            tableCard.erase(tableCard.begin() + i);
            this->tableCardCount--;
            break;
        }
    }
    return *this;
}

TableCard& TableCard::operator=(const TableCard& tableCard) {
    this->tableCard = tableCard.tableCard;
    this->tableCardCount = tableCard.tableCard.size();
    return *this;
}

void TableCard::printCard() {
    for (int i = 0; i < tableCard.size(); i++) {
        cout << WHITE << "Table Card " << i + 1 << RESET << endl;
        tableCard[i].print();
        cout << endl;
    }
}