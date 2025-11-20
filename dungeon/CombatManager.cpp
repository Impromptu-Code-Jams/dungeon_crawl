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

void goto_xy(int x, int y)
{
    std::cout << "\033[" << (y + 1) << ";" << (x + 1) << "H";
}

std::vector<std::string> CombatManager::createMainMenu()
{
    std::vector<std::string> menu;
    menu.push_back("+----------------+----------------+");
    menu.push_back("|     Player     |     Enemy      |");
    menu.push_back("| HP:            | HP:            |");
    menu.push_back("| MP:            | MP:            |");
    menu.push_back("| DMG:           | DMG:           |");
    menu.push_back("| DEF:           | DEF:           |");
    menu.push_back("|                |                |");
    menu.push_back("+----------------+----------------+");
    menu.push_back("|    Attack(A)   |     Magic(M)   |");
    menu.push_back("+----------------+----------------+");
    menu.push_back("|    Defend(D)   |     Item(I)    |");
    menu.push_back("+----------------+----------------+");
    return menu;
}

std::vector<std::string> CombatManager::createMagicMenu()
{
    std::vector<std::string> menu;
    menu.push_back("|              Spells             |");
    menu.push_back("|                                 |");
    menu.push_back("+---------------------------------+");
    return menu;
}

std::vector<std::string> CombatManager::createItemMenu()
{
    std::vector<std::string> menu;
    menu.push_back("|              Items              |");
    menu.push_back("|                                 |");
    menu.push_back("+---------------------------------+");
    return menu;
}

void CombatManager::printMenu(const std::vector<std::string>& menu, int x, int y, int& rowNum)
{
    for (const std::string& row : menu)
    {
        rowNum++;
        goto_xy(x, y + rowNum);
        std::cout << row;
    }
}

void CombatManager::display(int x, int y)
{
    itemMenuActive = true; // temp
    magicMenuActive = true; // temp
    
    std::vector<std::string> mainMenu = createMainMenu();
    int rowNum = 0;
    printMenu(mainMenu, x, y, rowNum);
    if (magicMenuActive)
    {
        std::vector<std::string> magicMenu = createMagicMenu();
        printMenu(magicMenu, x, y, rowNum);
    }
    if (itemMenuActive)
    {
        std::vector<std::string> itemMenu = createItemMenu();
        printMenu(itemMenu, x, y, rowNum);
    }
    goto_xy(0, 0);
}
