#include <gtest/gtest.h>

#include "RoomApi.h"

TEST(RoomApiTests, messages_TEST)
{
	RoomApi api{};

	EXPECT_EQ(api.getMessages().size(), 0);

	api.showMessage("Test message");

	EXPECT_EQ(api.getMessages().size(), 1);
}

TEST(RoomApiTests, enemySpawn_TEST)
{
	RoomApi api{};

	EXPECT_EQ(api.getEnemyList().size(), 0);

	api.spawnEnemy(1, 1, EnemyType::Goblin);

	EXPECT_EQ(api.getEnemyList().size(), 1);
}