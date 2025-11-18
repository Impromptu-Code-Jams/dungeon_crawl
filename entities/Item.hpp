#pragma once
#include <string>

enum Type { WEAPON, CONSUMABLE, SPELL };

class Item
{
public:
	virtual ~Item() = default; 
	std::string name{};
	Type type{};
};

