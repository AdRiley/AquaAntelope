#include "gmock/gmock.h"
#include "Player.h"

using namespace ::testing;

TEST(Player, Constructor)
{
    Player p{0,0};
    ASSERT_EQ(0, p.m_PosX);
    ASSERT_EQ(0, p.m_PosY);
}
