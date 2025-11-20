#include <gtest/gtest.h>

#include "DungeonEngine.h"
#include "SpikeTrapRoom.h"

//TEST(DungeonEngineTests, addRoom_TEST)
//{
//	DungeonEngine engine{};
//
//	EXPECT_EQ(engine.getRooms().size(), 0);
//	
//	engine.addRoom(std::make_unique<SpikeTrapRoom>());
//
//	EXPECT_EQ(engine.getRooms().size(), 1);
//}
//
//TEST(DungeonEngineTests, enterRoom_TEST)
//{
//	DungeonEngine engine{};
//
//	engine.addRoom(std::make_unique<SpikeTrapRoom>());
//
//	engine.enterRoom(1);
//
//	// check if room api was modified by adding SpikeTrapRoom
//	EXPECT_EQ(engine.roomApi.getMessages().size(), 1);
//	EXPECT_EQ(engine.roomApi.getEnemyList().size(), 1);
//}