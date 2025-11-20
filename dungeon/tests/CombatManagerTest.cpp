#include <gtest/gtest.h>

#include "CombatManager.h"

TEST(CombatManagerTests, Constructor_TEST)
{
	CombatManager combatManager{};

	EXPECT_TRUE(combatManager.magicMenuActive);
	EXPECT_FALSE(combatManager.itemMenuActive);
	EXPECT_FALSE(combatManager.playerIsBlocking);
}