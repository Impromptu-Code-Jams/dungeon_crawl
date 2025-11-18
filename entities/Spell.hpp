#pragma once
#include "Item.hpp"

class Spell : Item
{
public: 
	int damage{};
	int manaCost{}; 
};