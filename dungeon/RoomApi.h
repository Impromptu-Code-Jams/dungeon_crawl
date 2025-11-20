#pragma once

#include <memory>
#include <vector>
#include <string>

#include "../entities/Enemy.hpp"

enum EnemyType
{
	Goblin
};

class RoomApi
{
public:
	RoomApi();

	void showMessage(std::string const& message);
	std::vector<std::string> getMessages();

	void spawnEnemy(int x, int y, EnemyType enemyType);
	std::vector<Enemy> getEnemyList();

private:
	std::vector<std::string> messages;
	std::vector<Enemy> enemyList;
};

