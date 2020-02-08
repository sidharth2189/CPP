/*
    1-Passing values like this improves performance as no temporary copy needs to be made anymore and
    2-ownership changes, since the object the reference binds to has been abandoned by the caller and
    now binds to a handle which is available only to the receiver. This could not have been achieved
    with lvalue references as any change to the object that binds to the lvalue reference would also
    be visible on the caller side.
*/

#include <iostream>

void myFunction(int &&val)
{
    val++;
    std::cout << "val = " << val << std::endl;
}

int main()
{
    myFunction(42);

    return 0; 
}