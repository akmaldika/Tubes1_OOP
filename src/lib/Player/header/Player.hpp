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
    long long int point;  
    static int playerCount;
    bool played;
    // Combo MyCombo;
    PlayerCard MyCard;
    Combo Hand;
    
    public:
    // 
    Player();
    Player(Card card1, Card card2);

    // getter and setter
    void setCombo(Combo MyCombo);
    Combo getCombo();
    void setPlayerName(string name);
    string getPlayerName();
    void setPlayerPoint(long long int point);
    long long int getPlayerPoint();
    void setPlayerID(int ID);
    int getPlayerID();
    void setCardOne(Card card1);
    Card getCardOne();
    void setCardTwo(Card card2);
    Card getCardTwo();
    void setPlayed(bool);
    bool getPlayed();
    //void setCombo(Combo);
    //Combo getCombo();
    PlayerCard getMyCard() const;
    void setAbility(AbilityCard*);
    AbilityCard* getAbility();

    void status() ;

    void addPoint(long long int amount);


    // operator
    bool operator>(Player& enemy);
    bool operator==(const Player& enemy);
    bool operator<(Player& enemy);
    Player& operator=(Player player);
};

#endif