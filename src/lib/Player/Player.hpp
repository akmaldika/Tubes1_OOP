#ifndef __PLAYER__
#define __PLAYER__

#include "../../Cards/header/Card.hpp"
#include "../../Ability/Ability.hpp"

#include <iostream>
using namespace std;

class Player {
    private:
    string name;
    static int point;


    public:
    Player();
    // Player(string name);
    void setPlayerName(string name);
    string getPlayerName();

    void setPlayerPoint(int point);
    static int getPlayerPoint();

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