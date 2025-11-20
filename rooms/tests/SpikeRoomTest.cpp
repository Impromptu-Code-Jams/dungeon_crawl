#ifndef SPIKE_ROOM_H
#define SPIKE_ROOM_H

#include <gtest/gtest.h>
#include "SpikeTrapRoom.h"

TEST(SpikeRoomTest, Creation) {
    SpikeTrapRoom room;
    EXPECT_STREQ(room.name().c_str(), "SpikeTrapRoom");
}

#endif
