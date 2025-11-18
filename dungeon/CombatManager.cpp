#include "CombatManager.h"

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
