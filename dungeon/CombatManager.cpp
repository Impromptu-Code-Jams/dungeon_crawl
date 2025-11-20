#include "CombatManager.h"

bool CombatManager::handleInput(char input, RoomApi& api)
{
	bool inCombat = true;

	switch (std::toupper(input)) {
	case 'A': {
		std::optional<int> damage = player->attack();
		if (damage.has_value())
		{
			enemy->applyDamage(damage.value());
			if (enemy->getHealth() <= 0)
			{
				api.showMessage("Enemy defeated!");
				inCombat = false;
			}
			else
			{
				api.showMessage("You attacked the enemy!");
			}
		}
		break;
	}
	case 'D':
		playerIsBlocking = true;
		break;
	case 'M':
		magicMenuActive = true;
		itemMenuActive = false;
		break;
	case 'I':
		itemMenuActive = true;
		magicMenuActive = false;
		break;
	default:
		api.showMessage("Please enter a valid action!");
		break;
	}

	if (magicMenuActive && isdigit(input))
	{
		//int damage = player->castSpell(static_cast<int>(input));
		//if (damage > -1)
		//{
		//	enemy->applyDamage(damage);
		//	if (enemy->health <= 0)
		//	{
		//		api.showMessage("Enemy defeated!");
		//		inCombat = false;
		//	}
		//	api.showMessage("You cast a spell!");
		//	magicMenuActive = false;
		//}
	}
	else if (itemMenuActive && isdigit(input))
	{
		//int item = player->getItem(static_cast<int>(input));
		//if (item > -1)
		//{
		//	player->useItem(item);
		//	itemMenuActive = false;
		//	api.showMessage("You used an item!");
		//}
	}

	return inCombat;
}
