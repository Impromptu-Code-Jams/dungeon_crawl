#pragma once
#include "RoomApi.h"

#include <vector>
#include <string>
#include <memory>
#include <iostream>

#include "entities/Player.hpp"
#include "entities/Enemy.hpp"
#include "entities/Entity.h"

class CombatManager
{
public:
	CombatManager() = default;
	RoomApi roomApi{};

	bool handleInput(char input, RoomApi& api);
    void display(int x, int y);
    std::vector<std::string> createMainMenu();
    std::vector<std::string> createMagicMenu();
    std::vector<std::string> createItemMenu();

private:
	bool magicMenuActive{ true };
	bool itemMenuActive{ false };
	bool playerIsBlocking{ false };
	std::unique_ptr<Player> player;
	std::unique_ptr<Entity> enemy;

    void printMenu(const std::vector<std::string>& menu, int x, int y, int& rowNum);
};
