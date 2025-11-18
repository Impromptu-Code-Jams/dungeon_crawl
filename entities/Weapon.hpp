#pragma once
#include "Item.hpp"

class Weapon : public Item
{
public: 
	int damage{};
	double critChance{};
};