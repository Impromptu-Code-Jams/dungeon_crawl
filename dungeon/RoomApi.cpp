#include "RoomApi.h"
#pragma once

#include <string>
#include <vector>
#include "RoomApi.h"

RoomApi::RoomApi()
{
}

void RoomApi::showMessage(std::string const & message)
{
    messages.push_back(message);
}

std::vector<std::string> RoomApi::getMessages()
{
    return messages;
}

void RoomApi::spawnEnemy(int x, int y, EnemyType enemyType)
{
    if (enemyType == EnemyType::Goblin)
    {
        Enemy e;
        e.x = x;
        e.y = y;
        e.atk = 2;
        e.def = 0;
        e.hp = 10;
        e.type = enemyType;
        e.glyph = 'g';

        enemyList.push_back(e);
    } else if (enemyType == EnemyType::Wolf)
    {
        Enemy e;
        e.x = x;
        e.y = y;
        e.atk = 1;
        e.def = 1;
        e.hp = 8;
        e.type = enemyType;
        e.glyph = 'w';

        enemyList.push_back(e);
    }
    else if (enemyType == EnemyType::Ogre)
    {
        Enemy e;
        e.x = x;
        e.y = y;
        e.atk = 4;
        e.def = 5;
        e.hp = 15;
        e.type = enemyType;
        e.glyph = 'O';

        enemyList.push_back(e);
    }
}

std::vector<Enemy>& RoomApi::getEnemyList()
{
    return enemyList;
}

void RoomApi::updateEnemies(int playerX, int playerY)
{
    for (auto& enemy : enemyList) {
        enemy.updatePosition(playerX, playerY);
    }
}

bool RoomApi::checkCollisions(int playerX, int playerY)
{
    for (auto& enemy : enemyList) {
        if (playerX == enemy.x && playerY == enemy.y)
            return true;
    }
    return false;
}
