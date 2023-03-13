// Create Abstract Class AbilityCard
#ifndef ABILITYCARD_HPP
#define ABILITYCARD_HPP

#include "../../Cards/header/Card.hpp"

using namespace std;

class AbilityCard
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
        virtual void useAbilityCard() = 0;

};

#endif