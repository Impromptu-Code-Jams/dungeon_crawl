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

	bool handleInput(char input, RoomApi& api);
};
