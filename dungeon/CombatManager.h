#pragma once

#include <iostream>
#include <vector>

class CombatManager
{
public:
    void display(int x, int y);
    std::vector<std::string> createMainMenu();
    std::vector<std::string> createItemMenu();

    bool itemMenuActive = false;
};
