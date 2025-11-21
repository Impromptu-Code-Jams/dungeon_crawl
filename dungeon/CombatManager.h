#pragma once
#include "RoomApi.h"

#include <vector>
#include <string>
#include <memory>
#include "RoomApi.h"
#include <iostream>
#include "entities/Action.h"
#include "entities/Player.hpp"
#include "entities/Entity.h"

class CombatManager
{
public:
	CombatManager() = default;
	RoomApi roomApi{};

	std::optional<Action> handleInput(char input, RoomApi& api, std::shared_ptr<Player> player, std::shared_ptr<Enemy> enemy);
    void display(int x, int y);
    std::vector<std::string> createMainMenu();
    std::vector<std::string> createMagicMenu();
    std::vector<std::string> createItemMenu();

private:
	bool magicMenuActive{ true };
	bool itemMenuActive{ false };

    void printMenu(const std::vector<std::string>& menu, int x, int y, int& rowNum);
};
