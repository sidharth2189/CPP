# include <iostream>
# include <gtest/gtest.h>
using namespace std;

TEST( Testname, SubTest1)
{
    ASSERT_TRUE(1 == 1);
    ASSERT_FALSE(1 == 2);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}