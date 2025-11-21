#include "CombatManager.h"

std::optional<Action> CombatManager::handleInput(char input, RoomApi& api, std::shared_ptr<Player> player, std::shared_ptr <Player> enemy)
{
	std::optional<Action> playerAction;
	switch (std::toupper(input)) {
	case 'A': {
		//playerAction = player->attackAction();
		break;
	}
	case 'D':
		//playerAction = player->defendAction();
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
		//playerAction = player->castSpell(static_cast<int>(input));
		
		if (playerAction.has_value())
		{
			magicMenuActive = false;
		}
		
	}
	else if (itemMenuActive && isdigit(static_cast<int>(input)))
	{
		//playerAction = player->useConsumable(static_cast<int>(input));
		if (playerAction.has_value())
		{
			itemMenuActive = false;
		}
	}

	return playerAction;
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

std::vector<std::string> CombatManager::createMagicMenu(std::shared_ptr<Player> player)
{
    std::vector<std::string> menu;
    menu.push_back("|              Spells             |");
    menu.push_back("|                                 |");
    menu.push_back("+---------------------------------+");
    return menu;
}

std::vector<std::string> CombatManager::createItemMenu(std::shared_ptr<Player> player)
{
    std::vector<Consumable> items;
    if (player != nullptr)
    {
        items = player->getConsumables();
    }
    std::vector<std::string> menu;
    menu.push_back("|              Items              |");
    if (items.empty())
    {
        menu.push_back("|                                 |");
    }
    else
    {
        for (std::size_t i = 0; i < items.size() && i < 10; i++)
        {
            std::string effectString = "";
            switch (items.at(i).effect.type)
            {
                case Effect::HEALTH_EFFECT:
                    effectString = /*std::to_string(static_cast<HealthEffect>(items.at(i).effect).modifierValue) + */"HP";
                    break;
                case Effect::MANA_EFFECT:
                    effectString = /*std::to_string(static_cast<ManaEffect>(items.at(i).effect).modifierValue) + */"MP";
                    break;
                case Effect::DEFENSE_EFFECT:
                    effectString = /*std::to_string(static_cast<DefenseEffect>(items.at(i).effect).modifierValue) + */"DEF";
                    break;
                case Effect::STRENGTH_EFFECT:
                    effectString = /*std::to_string(static_cast<StrengthEffect>(items.at(i).effect).modifierValue) + */"STR";
                    break;
                default:
                    effectString = "?";
            }
            menu.push_back("| [" + std::to_string(i) + "]" + " " + items.at(i).name + ": " + effectString + "          |" );
        }
    }
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

void CombatManager::display(int x, int y, std::shared_ptr<Player> player, std::shared_ptr<Entity> enemy)
{   
    std::vector<std::string> mainMenu = createMainMenu();
    int rowNum = 0;
    printMenu(mainMenu, x, y, rowNum);
    if (magicMenuActive)
    {
        std::vector<std::string> magicMenu = createMagicMenu(player);
        printMenu(magicMenu, x, y, rowNum);
    }
    if (itemMenuActive)
    {
        std::vector<std::string> itemMenu = createItemMenu(player);
        printMenu(itemMenu, x, y, rowNum);
    }
    goto_xy(0, 0);
}
