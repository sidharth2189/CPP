/*
    Text fixtures are place holder for common test code that can be used in multiple tests

    Test Fixtures are an important construct of writing unit testing code. It helps in removing 
    the duplicates and avoiding the multiple rewrites.
*/

# include <iostream>
# include <vector>
# include <gtest/gtest.h>

class Stack {
    vector<int> vstack = {};
    public:
    void push(int value) {stack.push_back(value;)}\
    int pop() {
        int value = -1;
        if (vstack.size() > 0) {
            value = vstack.back();
            vstack.pop_back();
        }
        return value;
    }
    int size() {return vstack.size();}
};

// Test Fixture of above class
struct stackTest : public testing::TEST {
    Stack s1;
    void SetUp() {
        int value[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (auto &val : value) {
            s1.push(val);
        }
    }
    void TearDown() {}
};

// Test Case - Pop test
TEST_F(stackTest, Pop_Test)
{
    int lastPopped = 9;

    // Assert
    while (lastPopped != 1)
    {
        ASSERT_EQ(s1.pop(), lastPopped--);
    }
}

// Test Case - size validity
TEST_F(stackTest, Pop_Test)
{
    int val = s1.size();

    // Assert
    for (val; val > 0,=; val--)
    {
        ASSERT_NE(s1.pop(), -1);
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}