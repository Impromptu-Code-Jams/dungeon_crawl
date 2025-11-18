#pragma once
#include "Item.hpp"
#include "Weapon.hpp"
#include "Spell.hpp"
#include "Consumable.hpp"
#include "Entity.h"
#include <vector>

struct Inventory
{
	std::vector<Consumable> consumables; 
	std::vector<Weapon> weapons; 
	std::vector<Spell> spells;
};

class Player : Entity
{
	Player(); 

	// Inherited functions
	void attack();
	int castSpell(int index);
	void applyDamage();

	// Player attributes & inventory
	void addXp(int xpAdd);
	void addItem(Item& item);
	void removeItem(int itmRmv);
	void changeWeapon(int weaponIndex);

	const std::vector<Spell>& getSpells() const { return inventory.spells; }
	const std::vector<Weapon>& getWeapons() const { return inventory.weapons; }
	const std::vector<Consumable>& getConsumables() const { return inventory.consumables; }
private: 
	int xp; 
	Inventory inventory;
};