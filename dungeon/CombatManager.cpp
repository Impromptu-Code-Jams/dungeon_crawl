#include "CombatManager.h"

bool CombatManager::handleInput(char input, RoomApi& api)
{
	bool inCombat = true;
	bool inputIsNumber = true;
	int numInput = -1;

	switch (std::toupper(input)) {
	case 'A':
		api.showMessage("You attacked!");
		break;
	case 'D':
		api.showMessage("You defended!");
		break;
	case 'M':
		magicMenuActive = true;
		itemMenuActive = false;
		api.showMessage("You cast a spell!");
		break;
	case 'I':
		itemMenuActive = true;
		magicMenuActive = false;
		api.showMessage("You used an item!");
		// setting this to false for now, need to make it false when defeat or victory conditions happen
		inCombat = false;
		break;
	default:
		api.showMessage("Please enter a valid action!");
		break;

	// try to convert the input to an integer
	try {
		numInput = std::stoi(input);
	}
	catch (const std::invalid_argument& e) {
		inputIsNumber = false;
	}
	catch (const std::out_of_range& e) {
		inputIsNumber = false;
	}

	if (magicMenuActive && inputIsNumber)
	{
		int damage = player->castSpell(numInput);
		if (damage > -1)
		{
			enemy->applyDamage(damage);
			if (enemy->health <= 0)
			{
				inCombat = false;
			}
			magicMenuActive = false;
		}
	}
	else if (itemMenuActive && inputIsNumber)
	{
		int item = player->getItem(numInput);
		if (item > -1)
		{
			player->useItem(item);
			itemMenuActive = false;
		}
	}

	return inCombat;
}
