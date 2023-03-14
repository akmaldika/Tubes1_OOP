#ifndef __PLAYER__
#define __PLAYER__

#include "../../Cards/header/Card.hpp"
#include "../../AbilityCard/header/AbilityCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../Cards/header/Combo.hpp"

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
    // Combo MyCombo;

    PlayerCard MyCard;
    
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
    void addCardOne(Card card1);
    Card getCardOne();
    void addCardTwo(Card card2);
    Card getCardTwo();
    void setPlayed(bool);
    bool getPlayed();
    //void setCombo(Combo);
    //Combo getCombo();

    void setAbility(AbilityCard*);
    AbilityCard* getAbility();

    void status() const;

    void addPoint(int amount);


    // operator
    bool operator>(Player& enemy);
    bool operator==(Player& enemy);
    bool operator<(Player& enemy);
};

#endif