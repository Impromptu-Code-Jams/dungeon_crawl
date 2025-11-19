#pragma once
#include "Item.hpp"

class Shield : public Item
{
public: 
	Shield() { type = SHIELD; }
	int blockPercent{};

};