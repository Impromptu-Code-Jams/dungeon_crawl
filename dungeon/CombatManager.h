#pragma once
#include "RoomApi.h"

#include <vector>
#include <string>
#include <memory>
#include "RoomApi.h"
#include <iostream>

#include "entities/Player.hpp"
#include "entities/Entity.h"

class CombatManager
{
public:
	CombatManager() = default;
	RoomApi roomApi{};

	bool handleInput(char input, RoomApi& api);

private:
	bool magicMenuActive{ false };
	bool itemMenuActive{ false };
	bool playerIsBlocking{ false };
	std::unique_ptr<Player> player;
	std::unique_ptr<Entity> enemy;
};
