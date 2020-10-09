#include "fast_power.hpp"
#include <gtest/gtest.h>

TEST(Power, Test_1)
    {
        EXPECT_EQ(fast_power(0ull,0ull), 1ull);
    }
TEST(Power, Test_2)
    {
        EXPECT_EQ(fast_power(2ull,10ull), 1024ull);
    }
TEST(Power, Test_3)
    {
        EXPECT_EQ(fast_power(13ull,8ull), 815730721ull);
    }
TEST(Power, Test_4)
    {
        EXPECT_EQ(fast_power(12ull,13ull), 106993205379072ull);
    }