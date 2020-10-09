#include "fibbonchi_logn.hpp"
#include <gtest/gtest.h>

TEST(Fibbonachi, Test_1)
    {
        Fibbonachi _fib(1ll);
        EXPECT_EQ(_fib.get_result(), 1ll);
    }
TEST(Fibbonachi, Test_2)
    {
        Fibbonachi _fib(20ll);
        EXPECT_EQ(_fib.get_result(), 6765ll);
    }
TEST(Fibbonachi, Test_3)
    {
        Fibbonachi _fib(44ll);
        EXPECT_EQ(_fib.get_result(), 701408733ll);
    }
TEST(Fibbonachi, Test_4)
    {
        Fibbonachi _fib(-10ll);
        EXPECT_EQ(_fib.get_result(), -55ll);
        EXPECT_EQ(_fib.calculate(10ll), 55ll);
    }

