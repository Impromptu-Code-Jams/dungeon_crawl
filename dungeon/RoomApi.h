#pragma once

#include <memory>
#include <vector>
#include <string>

enum EnemyType
{
	Goblin
};

struct Enemy
{
    EnemyType type;
    int x;
    int y;
    int hp;
    int atk;
    int def;
    char glyph;

    void updatePosition(int playerX, int playerY) {
        if (x > playerX) x--;
        else if (x < playerX) x++;
        else if (y > playerY) y--;
        else if (y < playerY) y++;
    };
};

class RoomApi
{
public:
	RoomApi();

	void showMessage(std::string const& message);
	std::vector<std::string> getMessages();

	void spawnEnemy(int x, int y, EnemyType enemyType);
	std::vector<Enemy> getEnemyList();

        void updateEnemies(int playerX, int playerY);

    private:
        std::vector<std::string> messages;
        std::vector<Enemy> enemyList;
};

