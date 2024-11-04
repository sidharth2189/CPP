# include <gtest/gtest.h>
# include "sum.h"

TEST(TestSum, InputAsVector)
{
    
    // Initialize vector with elements
    vector<int> v{1, 2, 3, 5};
    int expected = 11;

    // Compute sum of elements in vector
    auto total = ComputeSum(v);

    // Expect
    EXPECT_EQ(total, expected);
}

TEST(TestSum, InputAsTwoElements)
{
    // Initialize elements
    float x = 3.2, y = 5.1;
    float expected = 8.3;

    // Compute sum of elements in vector
    float total = ComputeSum(x, y);

    // Expect
    EXPECT_EQ(total, expected);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
