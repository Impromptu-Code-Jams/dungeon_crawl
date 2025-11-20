#pragma once

#include <memory>
#include <vector>
#include "IRoom.h"
#include "RoomApi.h"
#include "CombatManager.h"

class DungeonEngine
{
public:
	DungeonEngine();

	void addRoom(std::unique_ptr<IRoom> room);
	void start();
	std::vector<std::unique_ptr<IRoom>>& getRooms();

	void enterRoom(int roomIndex);

	RoomApi roomApi{};
private:
	void handleInput();
	void render();

	void getInput();
	void loop();

	bool running{};
	bool quit{};
	bool inCombat{false};

	int currentRoomIndex{};
	std::vector<std::unique_ptr<IRoom>> rooms{};
	std::unique_ptr<CombatManager> combatManager{};

	bool hasInput{};
	char inputBuffer{};
};

