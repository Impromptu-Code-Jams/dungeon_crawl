#pragma once
#include "Item.hpp"

class Spell : public Item
{
public: 
	int damage{};
	int manaCost{}; 
};