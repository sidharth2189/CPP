/*
    Input: A vector of type string
    Output: First element of vector that appears exactly once
*/

#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string firstUniqueProduct(const std::vector<std::string>& products)
{
    int val_count, index;

    // Loop through vector to count appearances of each element
    for(index = 0; index < products.size(); index++)
    {
        val_count = std::count(products.begin(), products.end(), products[index]);

        // Return the very first element that appears once
        if (val_count == 1)
        {
            return products[index];
        }
    }
    return std::string();
}

#ifndef RunTests
int main()
{
    std::vector<std::string> products = { "Apple", "Computer", "Apple", "Bag" };
    std::cout << firstUniqueProduct(products);
}
#endif