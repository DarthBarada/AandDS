#include "fibbonchi_logn.hpp"
#include <gtest/gtest.h>

TEST(Fibbonachi_numbers, Fibbonachi_1)
    {
        Fibbonachi _fib(1ll);
        EXPECT_EQ(_fib.get_result(), 1ll);
    }
TEST(Fibbonachi_numbers, Fibbonachi_2)
    {
        Fibbonachi _fib(20ll);
        EXPECT_EQ(_fib.get_result(), 6765ll);
    }
TEST(Fibbonachi_numbers, Fibbonachi_3)
    {
        Fibbonachi _fib(44ll);
        EXPECT_EQ(_fib.get_result(), 701408733ll);
    }
TEST(Fibbonachi_numbers, Fibbonachi_4)
    {
        Fibbonachi _fib(-10ll);
        EXPECT_EQ(_fib.get_result(), -55ll);
    }

