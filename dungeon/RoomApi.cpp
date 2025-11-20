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

        enemyList.push_back(e);
    }
}

std::vector<Enemy> RoomApi::getEnemyList()
{
    return enemyList;
}
