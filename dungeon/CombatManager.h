#pragma once

#include <vector>
#include <string>

class CombatManager
{
public:
	CombatManager() = default;
	bool handleInput(std::string input);
};
