#pragma once

#include <memory>
#include <vector>

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
};

class RoomApi
{
    public:
        RoomApi();

        void spawnEnemy(int x, int y, EnemyType enemyType);
        std::vector<Enemy> getEnemyList();

    private:
        std::vector<Enemy> enemyList;
};

