<<<<<<< HEAD
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

=======
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
        int tableCardCount;

        // Constructor
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

>>>>>>> 95786990c5ba5c95a3f1d0bab2e4b8e875713d27
#endif