#include <iostream>
using std::cout;

int AddOne(int j) 
{
    int &k = j;
    k++;
    return k;
}

int main() 
{
    int i = 1;
    cout << "The value of i is: " << i << "\n";
    int x = AddOne(i);
    cout << "The value of x is : " << x << "\n";
}