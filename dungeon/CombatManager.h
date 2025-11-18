#pragma once
#include "RoomApi.h"

#include <vector>
#include <string>
#include <memory>
#include "RoomApi.h"
#include <iostream>

class CombatManager
{
public:
	CombatManager() = default;
	RoomApi roomApi{};

	bool handleInput(char input, RoomApi& api);

private:
	bool magicMenuActive{ false };
	bool itemMenuActive{ false };

	std::unique_ptr<Enemy> player;
	std::unique_ptr<Enemy> enemy;
};
