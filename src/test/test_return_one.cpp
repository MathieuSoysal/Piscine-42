// test_return_one.cpp
#include "gtest/gtest.h"
extern "C" {
#include "../main/return_one.h"
}

TEST(t_return_one, returns_1)
{
    GTEST_ASSERT_EQ(return_one(),1);  
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}