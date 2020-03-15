#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string firstUniqueProduct(const std::vector<std::string>& products)
{
    // throw std::logic_error("Waiting to be implemented");
    int val_count, index;
    for(index = 0; index < products.size(); index++)
    {
        val_count = std::count(products.begin(), products.end(), products[index]);
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