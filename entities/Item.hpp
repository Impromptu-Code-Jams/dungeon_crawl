#pragma once
#include <string>
#include "Effect.hpp"


struct Item
{
public:
	enum Type { WEAPON, CONSUMABLE, SPELL, SHIELD };

	virtual ~Item() = default; 
	std::string name{};
	Type type{};
};

struct Weapon : public Item
{
public:
	Weapon() { type = WEAPON; }
	int damage{};
	double critChance{};

};

struct Shield : public Item
{
public:
	Shield() { type = SHIELD; }
	int blockPercent{};

};

struct Spell : public Item
{
public:
	Spell() { type = SPELL; }
	Effect effect; // applies to the enemy
	int manaCost{};
};

struct Consumable : public Item
{
public:
	Consumable() { type = CONSUMABLE; }
	Effect effect; 
};
