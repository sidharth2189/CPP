/*
    One of the primary use-cases for lvalue references is the pass-by-reference 
    semantics in function calls.

    The function myFunction in code below, has an lvalue reference as a parameter, 
    which establishes an alias to the integer i which is passed to it in main.
*/

#include <iostream>

void myFunction(int &val)
{
    ++val;
}

int main()
{
    int i = 1; 
    myFunction(i);

    std::cout << "i = " << i << std::endl;

    return 0;
}