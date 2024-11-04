#ifndef SUM_H
#define SUM_H

#include <vector>
using std::vector;

// Compute Sum method declaration.
template<typename T> T ComputeSum(vector<T> v);
template<typename T> T ComputeSum(T x, T y);

#include "../src/sum.cpp" // Let compiler see definition when template instantiated

#endif // SUM_H
