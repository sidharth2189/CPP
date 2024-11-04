/*
    Compute sum
*/

#include <iostream>
#include "../include/sum.h"

int main() 
{
    // Initialize vector with elements
    vector<int> v{1, 2, 3, 5};

    // Compute sum of elements in vector
    auto total_vec = ComputeSum(v);
    // Print sum
    std::cout << "The total is: " << total_vec << "\n";
    
    // Compute sum of elements
    double x = 3.2, y = 5.1;
    auto total_elem = ComputeSum(x, y);
    // Print sum
    std::cout << "The total is: " << total_elem << "\n";
}
