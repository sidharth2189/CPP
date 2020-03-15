#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include<algorithm> 

int minPieces(const std::vector<int>& original, const std::vector<int>& desired)
{
    //throw std::logic_error("Waiting to be implemented");
    int piece, vect_size, index = 0;
    piece = original.size();
    vect_size = piece;
    for (int i = 0 ; i < vect_size ; ++i)
    {
        if (original[i] == desired[i])
            piece--;
    }
    vector([1:k-1 k+1:end])
    if (std::includes(original[[1:i-1], original.[i+1:end], desired.begin(), desired.end()))
    {
        
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