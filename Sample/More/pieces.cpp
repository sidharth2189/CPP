/*
    Input: Two vectors for e.g. original {1, 2, 4, 3} and desired {1, 4, 3, 2}
    Output: Integer that indicates the minimum number of pieces to be made of original 
    vector to make it look like the desired one.
*/

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

int minPieces(const std::vector<int>& original, const std::vector<int>& desired)
{
    int index; // position in original for a given element in desired
    int piece = original.size(); // initialize no. of pieces of original vector
    int vect_size = piece; // no. of elements in the vectors

    // Loop through the desired vector loop
    for (int i = 0 ; i < vect_size ; ++i)
    {
        // Find location in original for the ith element in desired
        auto loc = std::find(original.begin(), original.end(), desired[i]);
        index = std::distance(original.begin(), loc);

        // Check if elements ahead of current element in desired vector matches sequence in original
        while (original[index + 1] == desired[i + 1] && i < vect_size && index < vect_size)
        {
            // Reduce assessment of number of pieces
            piece--;

            // increment indices
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
    return 0;
}
#endif
