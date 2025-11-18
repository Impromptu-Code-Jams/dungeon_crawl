#include "Item.hpp"
#include "Entity.hpp"
#include <vector>

struct Inventory
{
	std::vector<Item> consumables; 
	std::vector<Item> weapons; 
	std::vector<Item> spells;
};

class Player : Entity
{
	Player(); 

	// Inherited functions
	void attack();
	int castSpell(int index);
	void applyDamage();

	// Player attributes & inventory
	void addXp(int xpAdd);
	void addItem(Item item);
	void removeItem(int itmRmv);
	void changeWeapon(int weaponIndex);

private: 
	int xp; 
	Inventory inventory;
};