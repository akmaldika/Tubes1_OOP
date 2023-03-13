#ifndef __TABLE_CARD_HPP__
#define __TABLE_CARD_HPP__

#include <vector>
#include "InventoryHolder.hpp"

// Class TableCard
class TableCard : public InventoryHolder{
    public:
        // Attribute
        vector<Card> tableCard;
        int tableCardCount;

        // Constructor
        TableCard();
        TableCard(vector<Card> tableCard);

        // Copy Constructor
        TableCard(const TableCard& tableCard);

        // Destructor
        ~TableCard();

        // Setter and Getter
        void setTableCard(vector<Card> tableCard);
        vector<Card> getTableCard();
        int getTableCardCount();

        // Method
        TableCard& operator+(Card card);                    // Operator Overloading (add card)
        TableCard& operator-(Card card);                    // Operator Overloading (remove card)
        TableCard& operator=(const TableCard& tableCard);   // Operator Overloading (assignment)
        void printCard();
};

#endif