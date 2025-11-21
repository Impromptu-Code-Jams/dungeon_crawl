#include "ProcGenRoom.h"

#include <random>
#include <chrono>

ProcGenRoom::ProcGenRoom()
{
	std::mt19937 engine(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> distributionX(5, 15);
	std::uniform_int_distribution<int> distributionY(5, 10);
	xMax = distributionX(engine);
	yMax = distributionY(engine);

	generateTileMap(xMax, yMax);
}

std::string ProcGenRoom::name() const
{
	return "Cool Room";
}

std::vector<std::string> ProcGenRoom::getTileMap() const
{
	return tileMap;
}

void ProcGenRoom::onEnter(RoomApi& api)
{
	srand(time(NULL));
	EnemyType randomEnemy = static_cast<EnemyType>(rand() % EnemyType::LAST_ENEMY);
	std::string msg{};
	switch (randomEnemy) {
	case EnemyType::Goblin:
		msg = "A Goblin appears! He's goblin for a fight!";
		break;
	case EnemyType::Wolf:
		msg = "A wolf hairily appears. Show him your bit is worse than his bark";
		break;
	case EnemyType::Ogre:
		msg = "An ogre ogreishly appears. Time to get into his swamp!";
		break;
	}

	api.showMessage(msg);
	std::mt19937 engine(std::chrono::system_clock::now().time_since_epoch().count());
	std::uniform_int_distribution<int> xPos(1, xMax - 2);
	std::uniform_int_distribution<int> yPos(1, yMax - 2);
	api.spawnEnemy(xPos(engine), yPos(engine), randomEnemy);
}

void ProcGenRoom::generateTileMap(int x, int y)
{
	tileMap.clear();
	tileMap.push_back(std::string(x, '#'));
	for (int i = 0; i < y - 2; ++i)
	{
		tileMap.push_back("#" + std::string(x - 2, '.') + "#");
	}
	tileMap.push_back(std::string(x, '#'));
}
