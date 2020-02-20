/* 
    In computer programming, unit testing is a software testing method by which individual units 
    of source code, sets of one or more computer program modules together with associated control 
    data, usage procedures, and operating procedures, are tested to determine whether they are fit 
    for use
    
    Below is an example of multiple tests in google test

    Assertions can lead to success, non-fatal failure and fatal failure.
    In fatal failure, the execution of tests in a code stops where as that is not the case for
    non-fatal failures.

    Other than ASSERT_TRUE() and ASSERT_FALSE(), there are other assertion mechanism in google test
    like EXPECT_EQ() and ASSERT_EQ(). On failure, EXPECT_EQ() is non-fatal where as ASSERT_EQ() is fatal.
    
    Equal              -> EXPECT_EQ() ASSERT_EQ()
    Not equal          -> EXPECT_NE() ASSERT_NE()
    Less than          -> EXPECT_LT() ASSERT_LT()
    Less than equal    -> EXPECT_LE() ASSERT_LE()
    Greater than       -> EXPECT_GT() ASSERT_GT()
    Greater than equal -> EXPECT_GE() ASSERT_GE()
*/

# include <iostream>
# include <gtest/gtest.h>
using namespace std;
using std::cout;

TEST(Testname, SubTest1)
{
    ASSERT_TRUE(1 == 1);
    ASSERT_EQ(1,1)
}

TEST(Testname, SubTest2)
{
    ASSERT_EQ(1,2)
    cout << "Hello test" << endl; // printed because above failure is non-fatal
    ASSERT_TRUE(1 == 2);
    cout << "After assertion" << endl; // doesn't execute this line because failure above is fatal
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}