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
	std::optional<int> castSpell(std::string spellName);
	Status applyDamage(int damageAmount);

	// Player attributes & inventory
	void addXp(int xpAdd);
	void changeWeapon(std::string weaponName);
	void changeShield(std::string shieldName); 

private: 
	int xp{};
};