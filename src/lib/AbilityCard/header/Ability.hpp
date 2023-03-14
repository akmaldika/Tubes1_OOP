// Ability.hpp

#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <iostream>
#include <string>

using namespace std;

class Ability
{
    public:
        // Method

        // Setter abilityCard ke ABILITYCard_DEFAULT
        virtual void setAbilityCard(const string&) = 0;
        
        // Getter
        // mengembalikan abilityCard
        virtual string getAbilityCard() const = 0;

        // menggunakan AbilityCard sesuai dengan jenis kartu (child)
        virtual void useAbilityCard() = 0;
};



#endif