#pragma once
#include "Item.hpp"
#include "Entity.h"
#include <vector>
#include <iostream>
#include <optional>

struct Inventory
{
	std::vector<Consumable> consumables; 
	std::vector<Weapon> weapons; 
	std::vector<Shield> shields;
	std::vector<Spell> spells;
};

class Player : public Entity
{
public: 
	Player();
	// Inherited functions
	std::optional<int> attack() override;
	std::optional<int> castSpell(int index) override;
	Status applyDamage(const int damageAmount) override;

	// Player attributes & inventory
	void addXp(int xpAdd);
	void addItem(Item& item);
	void changeWeapon(int weaponIndex);
	void changeShield(int shieldIndex);
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
	bool canUseWeapon{ true };

	std::optional<Shield> currentShield;
	bool canUseShield{ true };
	
	bool block = false;
};