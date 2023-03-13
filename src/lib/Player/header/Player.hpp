#ifndef __PLAYER__
#define __PLAYER__

#include "../../Cards/header/Card.hpp"
#include "../../AbilityCard/header/AbilityCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../InventoryHolder/header/DeckCard.hpp"

#include <iostream>
using namespace std;

class Player {
    private:
    int ID; 
    string name;
    int point;  

    static int playerCount;
    bool played;

    public:
    // construktor
    Player(); // temp biar gameState ga error
    Player(Card card1, Card card2);

    // getter and setter
    void setPlayerName(string name);
    string getPlayerName();
    void setPlayerPoint(int point);
    int getPlayerPoint();
    void setPlayerID(int ID);
    int getPlayerID();
    void setPlayed(bool);
    bool getPlayed();
    void status() const;

    // operator
    bool operator>(Player& enemy);
    bool operator==(Player& enemy);
    bool operator<(Player& enemy);
};

#endif