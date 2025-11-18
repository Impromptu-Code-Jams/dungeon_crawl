#include "CombatManager.h"

bool CombatManager::handleInput(std::string input, RoomApi& api)
{
	bool inCombat = true;

	if (input == "A" || input == "a")
	{
		api.showMessage("You attacked!");
	}
	else if (input == "D" || input == "d")
	{
		api.showMessage("You defended!");
	}
	else if (input == "M" || input == "m")
	{
		api.showMessage("You cast a spell!");
	}
	else if (input == "I" || input == "i")
	{
		api.showMessage("You used an item!");
		inCombat = false;
	}

	return inCombat;
}