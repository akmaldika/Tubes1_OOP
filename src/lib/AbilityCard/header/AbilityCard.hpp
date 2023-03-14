// AbilityCard.hpp

#ifndef ABILITYCARD_HPP
#define ABILITYCARD_HPP

#include "Ability.hpp"

class Card;
class DeckCard;
class PlayerCard;
class Player;
class GameState;

// #include "../../Cards/header/Card.hpp"
// #include "../../InventoryHolder/header/DeckCard.hpp"
// #include "../../InventoryHolder/header/PlayerCard.hpp"
// #include "../../Player/header/Player.hpp"
// #include "../../GameState/header/GameState.hpp"

using namespace std;

class AbilityCard : public Ability
{
    protected :
        const string ABILITYCARD_DEFAULT = "unknown";
        string abilityCard;
    public :
        // Method

        // Setter abilityCard ke ABILITYCard_DEFAULT
        void setAbilityCard(const string&);
        
        // Getter
        // mengembalikan abilityCard
        string getAbilityCard() const;

        // menggunakan AbilityCard sesuai dengan jenis kartu (child)
        virtual void useAbilityCard();

};

#endif