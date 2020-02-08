/*
    The function myFunction takes an lvalue reference as its argument. 
    In main, the call myFunction(j) works just fine while myFunction(42) 
    as well as myFunction(j+k) produces error.
    
    While the number 42 is obviously an rvalue, with j+k things 
    might not be so obvious, as j and k are variables and thus 
    lvalues. To compute the result of the addition, the compiler 
    has to create a temporary object to place it in - and this 
    object is an rvalue.
*/

#include <iostream>

void myFunction(int &val)
{
    std::cout << "val = " << val << std::endl;
}

int main()
{
    int j = 42;
    myFunction(j);

    myFunction(42);

    int k = 23; 
    myFunction(j+k);

    return 0; 
}