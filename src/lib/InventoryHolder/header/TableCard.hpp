#ifndef __TABLE_CARD_HPP__
#define __TABLE_CARD_HPP__

#include <iostream>
#include "InventoryHolder.hpp"

using namespace std;

// Class TableCard
class TableCard : public InventoryHolder{
    public:
        // Attribute
        vector<Card> tableCard;
        static int tableCardCount;

        // Constructor
        TableCard(vector<Card> tableCard);

        // Copy Constructor
        TableCard(const TableCard& tableCard);

        // Destructor
        ~TableCard();

        // Setter and Getter
        void setTableCard(vector<Card> tableCard);
        vector<Card> getTableCard();
        static int getTableCardCount();

        // Method
        TableCard& operator+(Card card);     // Operator Overloading (add card)
        TableCard& operator-(Card card);     // Operator Overloading (remove card)
        void printCard();
};

#endif