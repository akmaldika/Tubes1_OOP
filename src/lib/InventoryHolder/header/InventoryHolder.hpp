<<<<<<< HEAD
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

=======
#ifndef __INVENTORY_HOLDER_HPP__
#define __INVENTORY_HOLDER_HPP__

#include "../../Cards/header/Card.hpp"
#include <vector>

// Abstract Class InventoryHolder
class InventoryHolder{
    public:
        // Method
        virtual InventoryHolder& operator+(Card card) = 0;
        virtual InventoryHolder& operator-(Card card) = 0;
        virtual void printCard() = 0;
};

>>>>>>> 95786990c5ba5c95a3f1d0bab2e4b8e875713d27
#endif