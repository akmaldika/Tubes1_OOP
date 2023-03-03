// Create Abstract Class Ability
#ifndef ABILITY_HPP
#define ABILITY_HPP

#include <iostream>
#include <cstring>
#include "../../Cards/header/Card.hpp"

using namespace std;

class Ability
{
protected:
    const string ABILITY_DEFAULT = "unknown";
    string ability;

    virtual ~Ability() = 0;

    // Method

    // Setter
    // menggunakan Ability sesuai dengan jenis kartu
    virtual void useAbility() = 0;

    // Getter
    // mengembalikan ability
    string getAbility();
};

#endif