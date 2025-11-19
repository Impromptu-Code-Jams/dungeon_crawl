#include "Item.hpp"

class Consumable : public Item
{
public: 
	Consumable() { type = CONSUMABLE; }
	int health{}; // TODO: change to effect

};