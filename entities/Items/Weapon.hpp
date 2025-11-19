#pragma once
#include "Item.hpp"

class Weapon : public Item
{
public: 
	Weapon() { type = WEAPON; }
	int damage{};
	double critChance{};
	
};