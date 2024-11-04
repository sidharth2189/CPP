/*
    Compute sum
*/

#include <iostream>
#include "sum.h"

int main() 
{
    // Initialize vector with elements
    vector<int> v{1, 2, 3, 5};

    // Compute sum of elements in vector
    auto total = ComputeSum(v);
    // Print sum
    std::cout << "The total is: " << total << "\n";
    
    // Compute sum of elements
    float x = 3.2, y = 5.1;
    total = ComputeSum(x, y);
    // Print sum
    std::cout << "The total is: " << total << "\n";
}
