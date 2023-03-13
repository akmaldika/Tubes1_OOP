#ifndef __INVENTORY_HOLDER_HPP__
#define __INVENTORY_HOLDER_HPP__

#include "../../Cards/header/Card.hpp"
#include "../../color.h"
#include <iostream>

using namespace std;

// Abstract Class InventoryHolder
class InventoryHolder{
    public:
        // Method
        virtual void printCard() = 0;
};

#endif