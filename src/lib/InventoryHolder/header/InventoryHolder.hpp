#ifndef __INVENTORY_HOLDER_HPP__
#define __INVENTORY_HOLDER_HPP__

#include "../../Cards/header/Card.hpp"
#include <vector>

// Abstract Class InventoryHolder
class InventoryHolder{
    protected:
        // Destructor
        virtual ~InventoryHolder() = 0;

        // Method
        virtual InventoryHolder& operator+(Card card) = 0;
        virtual InventoryHolder& operator-(Card card) = 0;
        virtual void printCard() = 0;
};

#endif