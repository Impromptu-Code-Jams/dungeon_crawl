#pragma once
#include "RoomApi.h"

#include <vector>
#include <string>
#include <memory>

class CombatManager
{
public:
	CombatManager() = default;
	RoomApi roomApi{};

	bool handleInput(std::string input, RoomApi& api);
};
