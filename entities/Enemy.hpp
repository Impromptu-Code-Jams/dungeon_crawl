#pragma once

#include "Entity.h"

#include <iostream>
#include <random>

class Enemy : public Entity
{
public: 
	Enemy(); 

    // Inherited functions
    std::optional<int> attack();
    std::optional<int> castSpell();
    Status applyDamage(int damageAmount);

    Effect getNextPlay(); 

private: 
    double healPercent{ 0.2 };
    double manaPercent{ 0.2 };
    double blockChance{ 0.3 }; 
    double spellChance{ 0.5 };

    std::random_device rd;
};