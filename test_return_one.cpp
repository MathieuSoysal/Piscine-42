// test_return_one.cpp
#include "gtest/gtest.h"
extern "C" {
#include "return_one.h"
}

TEST(t_return_one, returns_1)
{
    EXPECT_EQ(1,return_one());  
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}