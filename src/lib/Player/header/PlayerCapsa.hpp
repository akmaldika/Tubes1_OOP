#ifndef __PLAYERCAPSA__
#define __PLAYERCAPSA__

#include "StandardPlayer.hpp"
#include "../../Cards/header/CapsaCard.hpp"
#include "../../InventoryHolder/header/PlayerCapsaCard.hpp"
#include "../../Cards/header/Combo.hpp"

#include <iostream>
#include <vector>
using namespace std;

class PlayerCapsa : public StandardPlayer{
    private: 
    PlayerCapsaCard MyHands;
    
    public:
    // 
    PlayerCapsa();
    PlayerCapsa(int ID, string name,  vector<CapsaCard> cards);
    // getter and setter
    PlayerCapsaCard getMyCard() const;
    void setMyCard(PlayerCapsaCard newHands);
    void status();

    void addPoint(long long int amount);


    // operator
    PlayerCapsa& operator=(PlayerCapsa player);
};

#endif