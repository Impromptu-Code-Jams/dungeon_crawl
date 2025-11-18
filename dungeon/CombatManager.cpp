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

std::vector<std::string> CombatManager::createItemMenu()
{
    std::vector<std::string> menu;
    menu.push_back("|              Items              |");
    menu.push_back("|                                 |");
    menu.push_back("+---------------------------------+");
    return menu;
}

void CombatManager::display(int x, int y)
{
    std::vector<std::string> mainMenu = createMainMenu();
    std::size_t rowNum = 0;
    for (const std::string& row : mainMenu)
    {
        rowNum++;
        goto_xy(x, y + rowNum);
        std::cout << row;
    }
    if (itemMenuActive)
    {
        std::vector<std::string> itemMenu = createItemMenu();
        
        for (const std::string& row : itemMenu)
        {
            rowNum++;
            goto_xy(x, y + rowNum);
            std::cout << row;
        }
    }
    goto_xy(0, 0);
}
