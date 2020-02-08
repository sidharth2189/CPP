/*
    An lvalue reference can be considered as an alternative name for an object. 
    It is a reference that binds to an lvalue and is declared using an optional 
    list of specifiers followed by the reference declarator &. Code below declares 
    an integer i and a reference j which can be used as an alias for the existing object.

    The output of the program is
    i = 3, j = 3

    We can see that the lvalue reference j can be used just as i can. A change to 
    either i or j will affect the same memory location on the stack.
*/

#include <iostream>

int main()
{
    int i = 1; 
    int &j = i; 
    ++i;
    ++j;

    std::cout << "i = " << i << ", j = " << j << std::endl;

    return 0;
}