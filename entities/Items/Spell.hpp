#pragma once
#include "Item.hpp"

class Spell : public Item
{
public: 
	Spell() { type = SPELL; }
	int damage{};
	int manaCost{}; 
};