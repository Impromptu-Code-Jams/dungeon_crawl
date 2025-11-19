#pragma once
#include "Items/Item.hpp"
#include "Items/Weapon.hpp"
#include "Items/Spell.hpp"
#include "Items/Consumable.hpp"
#include "Items/Shield.hpp"
#include "Entity.h"
#include <vector>
#include <iostream>

struct Inventory
{
	std::vector<Consumable> consumables; 
	std::vector<Weapon> weapons; 
	std::vector<Shield> shields;
	std::vector<Spell> spells;
};

class Player : Entity
{
	Player(); 

	// Inherited functions
	std::optional<int> attack();
	std::optional<int> castSpell(int index);
	Status applyDamage(const int damageAmount);

	// Player attributes & inventory
	void addXp(int xpAdd);
	void addItem(Item& item);
	void changeWeapon(int weaponIndex);
	void useConsumable(int consumeIndex); 
	void blockNextAttack() { block = true; }

	const std::vector<Spell>& getSpells() const { return inventory.spells; }
	const std::vector<Weapon>& getWeapons() const { return inventory.weapons; }
	const std::vector<Consumable>& getConsumables() const { return inventory.consumables; }
	const std::vector<Shield>& getShields() const { return inventory.shields; }
private: 
	int xp; 
	Inventory inventory;
	std::optional<Weapon> currentWeapon;
	std::optional<Shield> currentShield;
	
	bool block = false;
};