#pragma once

#include <iostream>
#include <vector>

class CombatManager
{
public:
    void display(int x, int y);
    std::vector<std::string> createMainMenu();
    std::vector<std::string> createMagicMenu();
    std::vector<std::string> createItemMenu();
    
private:
    void printMenu(const std::vector<std::string>& menu, int x, int y, int& rowNum);
    bool magicMenuActive = false;
    bool itemMenuActive = false;
};
