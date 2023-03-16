#ifndef __PLAYER__
#define __PLAYER__

#include "StandardPlayer.hpp"
#include "../../Cards/header/Card.hpp"
#include "../../AbilityCard/header/AbilityCard.hpp"
#include "../../InventoryHolder/header/PlayerCard.hpp"
#include "../../Cards/header/Combo.hpp"

#include "../../InventoryHolder/header/DeckCard.hpp"

#include <iostream>
using namespace std;

class Player : public StandardPlayer{
    private: 
    static int playerCount;
    bool played;
    // Combo MyCombo;
    PlayerCard MyCard;
    Combo<Card> Hand;
    vector<Combo<Card>> listFinalCombo;
    
    public:
    // 
    Player();
    Player(Card card1, Card card2);

    // getter and setter
    void setCombo(Combo<Card> &MyCombo);
    Combo<Card> getCombo();
    void setListFinalCombo(vector<Combo<Card>> listFinalCombo);
    vector<Combo<Card>> getListFinalCombo();
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
    Player& operator=(Player player);
};

#endif