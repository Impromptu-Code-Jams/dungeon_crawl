#pragma once
#include "Item.hpp"
#include "Entity.h"
#include <vector>
#include <iostream>


class Player : Entity
{
public: 
	Player(); 

	// Inherited functions
	std::optional<int> attack();
	std::optional<int> castSpell(int index);
	Status applyDamage(const int damageAmount);

	// Player attributes & inventory
	void addXp(int xpAdd);
	void changeWeapon(int weaponIndex);
	void changeShield(int shieldIndex); 

private: 
	int xp{};
};