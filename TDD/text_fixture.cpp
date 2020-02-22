/*
    Text fixtures are place holder for common test code that can be used in multiple tests

    Test Fixtures are an important construct of writing unit testing code. It helps in removing 
    the duplicates and avoiding the multiple rewrites.
*/

# include <iostream>
# include <gtest/gtest.h>

class MyClass {
    MyClass (int _bv) : baseValue(_bv) {}
    void Increment (int byValue) {
        baseValue += byValue;
    }
    int getValue() {return baseValue;}
};

// Test Fixture of above class
struct MyClassTest : public testing::TEST {
    MyClass *mc;
    void SetUp() { mc = new MyClass(100);}
    void TearDown() {delete mc;}
};

// Test Case - Incrment by 5
TEST_F(MyClassTest, IncrmentBy5)
{
    // Act
    mc->Increment(5);

    // Assert
    ASSERT_EQ(mc->getValue(), 105);
}

// Test Case - Incrment by 5
TEST_F(MyClassTest, IncrmentBy10)
{
    // Act
    mc->Increment(10);

    // Assert
    ASSERT_EQ(mc->getValue(), 110);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}