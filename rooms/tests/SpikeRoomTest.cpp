#ifndef SPIKE_ROOM_H
#define SPIKE_ROOM_H

#include <gtest/gtest.h>
#include "SpikeTrapRoom.h"
#include "RoomApi.h"

TEST(SpikeRoomTest, Creation_TEST) {
	SpikeTrapRoom room;
	EXPECT_STREQ(room.name().c_str(), "SpikeTrapRoom");
}

TEST(SpikeRoomTest, getTileMap_TEST)
{
	std::vector<std::string> testTileMap = {
		"################",
		"#..............#",
		"#..............#",
		"#..............#",
		"################"
	};

	SpikeTrapRoom room{};

	EXPECT_EQ(room.getTileMap(), testTileMap);
}

TEST(SpikeRoomTest, onEnter_TEST)
{
	SpikeTrapRoom room{};
	RoomApi api{};

	EXPECT_EQ(api.getMessages().size(), 0);

	room.onEnter(api);

	EXPECT_EQ(api.getMessages().size(), 1);
}

#endif
