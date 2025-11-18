#pragma once
#include "Item.hpp"

class Weapon : Item
{
public: 
	int damage{};
	double critChance{};
};