#pragma once

#include <memory>
#include <vector>
#include "RoomApi.h"
#include "IRoom.h"

class DungeonEngine
{
public:
	DungeonEngine();

	void addRoom(std::unique_ptr<IRoom> room);
	void start();
	std::vector<std::unique_ptr<IRoom>>& getRooms();

	void enterRoom(int roomIndex);

	RoomApi roomApi;
private:
	void handleInput();
	void render();

	void getInput();
	void loop();

	bool running;
	bool quit;

	int currentRoomIndex;
	std::vector<std::unique_ptr<IRoom>> rooms;

	bool hasInput;
	char inputBuffer;
};

