#pragma once
#include "CombatManager.h"
#include "IRoom.h"
#include "RoomApi.h"
#include "entities/Player.hpp"
#include "entities/Entity.h"

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
	bool inCombat{false};

	int currentRoomIndex{};
	std::vector<std::unique_ptr<IRoom>> rooms{};
	RoomApi roomApi{};
	std::unique_ptr<CombatManager> combatManager{};
	std::shared_ptr<Player> player;
	std::shared_ptr<Player> enemy;
	bool hasInput{};
	char inputBuffer{};
	bool combat;
};

