#include <iostream>
using std::cout;

int main() 
{
    // Write your code here.
    auto i = 1;
    
    while (i <= 10)
    {
        if (i%2 == 0)
        {
            cout << i << '\n';
        }
        i++;
    }

}