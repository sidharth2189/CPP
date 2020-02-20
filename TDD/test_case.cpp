/*
    How to write unit test case:

    1) Unit test must run fast (within milliseconds)
    2) Must be able to run independently
    3) Doesn't depend on any external input.

    Any unit test case must have 3 aspects:
    - arrange (arrange every thing required to run test)
    - act (place where we run the test)
    - assert (place where we validate output)

    Equal           -> EXPECT_STREQ()   ASSERT_STREQ()
    Not equal       -> EXPECT_STRNE()   ASSERT_STRNE()
    Case equal      -> EXPECT_STRCASEEQ()   ASSERT_STRCASEEQ()
    Case not equal  -> EXPECT_STRCASENE()   ASSERT_STRCASENE()
*/

# include <iostream>
# include <gtest/gtest.h>
using namespace std;
using std::cout;

class MyClass {
    string _id;
    public:
    MyClass (string id) : _id(id) {}
    string GetID() {return _id;}
};

TEST(Testname, SubTest1)
{
    // Arrange
    MyClass mc("root");

    // Act
    string value = mc.GetID();

    // Assert
    ASSERT_EQ(value.c_str(), "root"); // fails because it compares value not string
    ASSERT_STREQ(value.c_str(), "root"); // compares string
}

TEST(Testname, SubTest2)
{
    // Arrange
    int value = 100;
    int increment = 5;

    // Act
    value = value + increment;

    // Assert
    ASSERT_EQ(value, 105);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}