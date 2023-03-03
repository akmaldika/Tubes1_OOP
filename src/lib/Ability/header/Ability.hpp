// Create Abstract Class Ability
#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "../../Cards/header/Card.hpp"
#include "../../Player/Player.hpp"

using namespace std;

class Ability
{
    protected:
        const string ABILITY_DEFAULT = "unknown";
        string ability;
    public :
        Ability();
        virtual ~Ability() = 0;

        // Method

        // Setter ability ke ABILITY_DEFAULT
        void setAbilityOff();

        // menggunakan Ability sesuai dengan jenis kartu
        virtual void useAbility() = 0;
        virtual void useAbility(int&) = 0;
        virtual void useAbility(vector<Player>&) = 0;
        virtual void useAbility(string&) = 0;
        virtual void useAbility(pair<Card,Card>&, pair<Card,Card>);
        virtual void useAbility(pair<Card,Card>&, Card, Card);
        virtual void useAbility(Card&, Card&);

        // Getter
        // mengembalikan ability
        string getAbility();
};

#endif