#ifndef __PLAYER__
#define __PLAYER__

#include "../Cards/header/Card.hpp"
#include "../AbilityCard/header/AbilityCard.hpp"
#include "../InventoryHolder/header/PlayerCard.hpp"

#include <iostream>
using namespace std;

class Player {
    private:
    int ID; // id satu player yang diambil dari playerCount -Naufal
    string name;
    int point;  
    PlayerCard MyCard;
    static int playerCount;
    bool played; // ini buat ngasih tau player ini udah main blm -Naufal 

    public:
    // Player(); // temp biar gameState ga error
    Player(Card card1, Card card2);

    // Player(string name);
    void setPlayerName(string name);
    string getPlayerName();

    int getID();

    void setPlayerPoint(int point);
    int getPlayerPoint();

    void setPlayed(bool);
    bool getPlayed();

    void status() const;

    // void addOne(Card one);
    // void addTwo(Card two);
    bool operator>(Player& enemy);
    bool operator==(Player& enemy);
    bool operator<(Player& enemy);

    void printPlayer();
};

#endif