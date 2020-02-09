#include <iostream>
using std::cout;

void AddOne(int* j)
{
    // Dereference the pointer and increment the int being pointed to.
    // (*j)++;
    int a = 0;
    j = &a;
    cout << "value inside function is " << *j << '\n';
}

int main() 
{
    int i = 1;
    cout << "The value of i is: " << i << "\n";
    
    // Declare a pointer to i:
    int* pi = &i;
    cout << "address is " << pi << '\n';
    AddOne(pi);
    cout << "The value of i is now: " << i << "\n";
    cout << "address now is " << pi << '\n';
    cout << "value now is " << *pi << '\n';
}