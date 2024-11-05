# include <gtest/gtest.h>
# include "sum.h"

TEST(TestSum, InputAsVectorInt)
{
    
    // Initialize vector with elements
    vector<int> v{1, 2, 3, 5};
    int expected = 11;

    // Compute sum of elements in vector
    auto total = ComputeSum(v);

    // Expect
    EXPECT_EQ(total, expected);
}

TEST(TestSum, InputAsVectorFloat)
{
    
    // Initialize vector with elements
    vector<float> v{1.1, 2.2, 3.3, 5.5};
    float expected = 12.1;

    // Compute sum of elements in vector
    auto total = ComputeSum(v);

    // Expect
    EXPECT_EQ(total, expected);
}

TEST(TestSum, InputAsTwoElementsInt)
{
    // Initialize elements
    int x = 3, y = 5;
    int expected = 8;

    // Compute sum of elements in vector
    auto total = ComputeSum(x, y);

    // Expect
    EXPECT_EQ(total, expected);
}

TEST(TestSum, InputAsTwoElementsFloat)
{
    // Initialize elements
    float x = 3.2, y = 5.1;
    float expected = 8.3;

    // Compute sum of elements in vector
    auto total = ComputeSum(x, y);

    // Expect
    EXPECT_EQ(total, expected);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
