#include <vector>
using std::vector;

// Compute Sum method definition with input as vector.
template<typename T>
T ComputeSum(vector<T> v) {
    // Initiate total sum
    T total = 0;

    // Add elements
    for (auto i: v) {
        total += i;
    }
    
    // Return total sum
    return total;
}

// Compute Sum method definition with input as two elements.
template<typename T>
T ComputeSum(T x, T y) {    
    // Return total sum
    return (x+y);
}
