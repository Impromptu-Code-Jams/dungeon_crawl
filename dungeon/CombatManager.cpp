#include "CombatManager.h"

bool CombatManager::handleInput(char input, RoomApi& api)
{
	bool inCombat = true;

	switch (std::toupper(input)) {
	case 'A':
		api.showMessage("You attacked!");
		break;
	case 'D':
		api.showMessage("You defended!");
		break;
	case 'M':
		api.showMessage("You cast a spell!");
		break;
	case 'I':
		api.showMessage("You used an item!");
		// setting this to false for now, need to make it false when defeat or victory conditions happen
		inCombat = false;
		break;
	default:
		api.showMessage("Please enter a valid action!");
		break;

		return inCombat;
	}
}