#pragma once
#include "Item.hpp"
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

class Enemy : Entity
{
public:
	Enemy(); 

	// Inherited functions
	std::optional<int> attack();
	std::optional<int> castSpell(int index);
	Status applyDamage(const int damageAmount);
	void updatePosition(int playerX, int playerY);
	// Enemy attributes & inventory
	
	void useConsumable(int consumeIndex); 
	void blockNextAttack() { block = true; }

	const std::vector<Spell>& getSpells() const { return inventory.spells; }
	const std::vector<Weapon>& getWeapons() const { return inventory.weapons; }
	const std::vector<Consumable>& getConsumables() const { return inventory.consumables; }
	const std::vector<Shield>& getShields() const { return inventory.shields; }

	enum Type { GOBLIN, SPIKES };
	Type type{};
private: 
	int xp; 
	Inventory inventory;
	std::optional<Weapon> currentWeapon;
	bool canUseWeapon{ true };

	std::optional<Shield> currentShield;
	bool canUseShield{ true };
	
	bool block = false;
};