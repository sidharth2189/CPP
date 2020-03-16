#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

int minPieces(const std::vector<int>& original, const std::vector<int>& desired)
{
    //throw std::logic_error("Waiting to be implemented");
    int piece, vect_size, index;
    piece = original.size();
    vect_size = piece;
    for (int i = 0 ; i < vect_size ; ++i)
    {
        auto loc = std::find(original.begin(), original.end(), desired[i]);
        index = std::distance(original.begin(), loc);
        while (original[index + 1] == desired[i + 1])
        {
            piece--;
            i++;
            index++;
        }   
    }
    return piece;
}

#ifndef RunTests
int main()
{
    std::vector<int> original = { 1, 4, 3, 2 };
    std::vector<int> desired = { 1, 2, 4, 3 };
    std::cout << minPieces(original, desired) << std::endl;
}
#endif
