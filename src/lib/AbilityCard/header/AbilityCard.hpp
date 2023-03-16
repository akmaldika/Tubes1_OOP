// AbilityCard.hpp

#ifndef ABILITYCARD_HPP
#define ABILITYCARD_HPP

#include "Ability.hpp"

class Card;
class DeckCard;
class PlayerCard;
class Player;
class GameState;

using namespace std;

class AbilityCard : public Ability
{
    protected :
        // Attribut
        const string ABILITYCARD_DEFAULT = "unknown";
        string abilityCard;
    public :
        // Constructor      
        AbilityCard();
        AbilityCard(const string& abilityCard);
        // Method

        // Setter abilityCard ke ABILITYCard_DEFAULT
        void setAbilityCard(const string&);
        
        // Getter
        // mengembalikan abilityCard
        string getAbilityCard() const;

        // menggunakan AbilityCard sesuai dengan jenis kartu (child)
        // setter abilityCard ke ABILITYCard_DEFAULT
        virtual void useAbilityCard();

        // mengembaliakn ABILITYCard_DEFAULT
        string getAbilityCardOff();

        // mengembalikan benar jika Ability == ABILITYCARD_DEFAULT
        bool isAbilityOff() const;

        bool operator==(const AbilityCard& other) const;

        virtual void printAbilityCard();

};

#endif