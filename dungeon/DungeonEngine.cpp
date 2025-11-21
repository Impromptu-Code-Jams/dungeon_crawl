#include <iostream>
#include <chrono>
#include <utility>
#include <thread>

#include "DungeonEngine.h"
#include "IRoom.h"
#include "GetCh.h"
#include "ProcGenRoom.h"

DungeonEngine::DungeonEngine() :
	running(false),
	quit(false),
	inCombat(false),
	currentRoomIndex(0),
	hasInput(false),
	inputBuffer()
{
	combatManager = std::make_unique<CombatManager>();
	player = std::make_shared<Player>();
	enemy = std::make_shared<Enemy>();
}

void DungeonEngine::addRoom(std::unique_ptr<IRoom> room)
{
	rooms.push_back(std::move(room));
}

void DungeonEngine::start()
{
	if (rooms.empty())
	{
		std::cout << "No rooms, no dungeon..." << std::endl;
		return;
	}

	// The starting room is always at index 0.
	enterRoom(0);

	running = true;
	std::thread t1(&DungeonEngine::loop, this);
	std::thread t2(&DungeonEngine::getInput, this);

	t1.join();
	t2.join();
}

void DungeonEngine::enterRoom(int roomIndex)
{
	currentRoomIndex = roomIndex;
	rooms[currentRoomIndex]->onEnter(roomApi);
}

void DungeonEngine::getInput()
{
    while (!quit)
    {
        inputBuffer = getSingleChar();

		if (inputBuffer == 'q')
		{
			quit = true;
		}
		else if (inputBuffer == 'n'){
			rooms[0].reset();
			roomApi.getEnemyList().clear();
			rooms[0] = std::make_unique<ProcGenRoom>();
			rooms[0]->onEnter(roomApi);
		}
		else
		{
			hasInput = true;
		}
	}
}

void DungeonEngine::handleInput()
{
	if (hasInput)
	{
		if (inCombat)
		{
			if (!combatManager->handleInput(inputBuffer, roomApi, player, enemy))
			{
				//inCombat = false;
			}
		}
		else {
			if (inputBuffer == 'w') {
				player->y--;
				player->moves--;
			}
			else if (inputBuffer == 'a') {
				player->x--;
				player->moves--;
			}
			else if (inputBuffer == 's') {
				player->y++;
				player->moves--;
			}
			else if (inputBuffer == 'd') {
				player->x++;
				player->moves--;
			}
		}
		if (inputBuffer == 'm')
		{
			static int x = 1;
			roomApi.showMessage("Hello There! " + std::to_string(x));
			x++;
		}
		inputBuffer = 0;
		hasInput = false;
	}
}

void DungeonEngine::render()
{
	//
	// Clear the screen.
	//

#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif

	std::cout << std::endl;

	//
	// Merge the tile maps.
	//

	auto tileMap = rooms[currentRoomIndex]->getTileMap();
	auto enemyList = roomApi.getEnemyList();

    for (auto enemy : enemyList)
    {
        tileMap[enemy.y][enemy.x] = enemy.glyph;
    }

	tileMap[player->y][player->x] = player->glyph;

	//
	// Render the current room.
	//

	for (int y = 0; y < tileMap.size(); y++)
	{
		std::cout << tileMap[y] << std::endl;
	}

	std::cout << std::endl;

	//
	// Render text logs.
	//

	std::cout << "----------- Text Log -----------" << std::endl;

	std::vector<std::string> messages = roomApi.getMessages();

	for (int i = 4; i > 0; i--)
	{
		if (static_cast<int>(messages.size()) - i >= 0)
		{
			std::cout << messages[messages.size() - i] << std::endl;
		}
		else
		{
			std::cout << "" << std::endl;
		}
	}

	std::cout << "--------------------------------" << std::endl;

	//
	// Render player info.
	//

	std::cout << "----------- Player -------------" << std::endl;

	std::cout << "HP: " << std::endl;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;

	std::cout << "--------------------------------" << std::endl;

	std::cout << std::endl;

	//
	// Render action menu.
	//

	std::cout << "test msg: [m] | quit: [q] " << std::endl;

	if (inCombat)
	{
		combatManager->display(65, 0);
	}
}

void DungeonEngine::loop()
{
	auto last = std::chrono::steady_clock::now();

	while (running)
	{
		auto now = std::chrono::steady_clock::now();

		int delta = std::chrono::duration_cast<std::chrono::milliseconds>(now - last).count();

		int ENGINE_FRAME_MILLISECONDS = 1000;
		int ENGINE_SLEEP_TIME_MILLISECONDS = 100;

		if (delta < ENGINE_FRAME_MILLISECONDS)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(ENGINE_SLEEP_TIME_MILLISECONDS));
			continue;
		}

		last = now;

	
		handleInput();
		if (player->moves == 0) {
			roomApi.updateEnemies(player->x, player->y);
			player->moves = player->speed;
		}
		
		if (roomApi.checkCollisions(player->x, player->y)) {
			inCombat = true;
			combatManager->display(35, 0);
		}
        

		if (quit)
		{
			running = false;
			break;
		}

		render();
	}
}

