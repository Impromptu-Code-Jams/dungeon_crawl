#pragma once
#include "CombatManager.h"
#include "IRoom.h"
#include "RoomApi.h"

#include <vector>
#include <memory>

class DungeonEngine
{
public:
	DungeonEngine();

	void addRoom(std::unique_ptr<IRoom> room);
	void start();

private:
	void enterRoom(int roomIndex);

	void handleInput();
	void render();

	void getInput();
	void loop();

	bool running{};
	bool quit{};
	bool inCombat{};

	int currentRoomIndex{};
	std::vector<std::unique_ptr<IRoom>> rooms{};
	RoomApi roomApi{};
	std::unique_ptr<CombatManager> combatManager{};

	bool hasInput{};
	char inputBuffer{};
};

