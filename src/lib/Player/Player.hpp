#ifndef __PLAYER__
#define __PLAYER__

#include "../Cards/header/Card.hpp"
// #include "../Ability/header/Ability.hpp"
#include "../InventoryHolder/header/PlayerCard.hpp"

#include <iostream>
using namespace std;

class Player {
    private:
    int ID; // id satu player yang diambil dari playerCount -Naufal
    string name;
    int point;  // point kayanya gapake static deh, biar tiap player bisa
                // punya point berbeda -Naufal
    PlayerCard MyCard;

    static int playerCount;

    public:
    // Player(); // temp biar gameState ga error
    Player(Card card1, Card card2, Card abilityCard);

    // Player(string name);
    void setPlayerName(string name);
    string getPlayerName();

    int getID();

    void setPlayerPoint(int point);
    int getPlayerPoint();

    // void addOne(Card one);
    // void addTwo(Card two);
    Card getCardOne();
    Card getCardTwo();

    void pointDouble();
    void pointHalf();
    void playerNext();
    void highestCombination();
};

#endif
