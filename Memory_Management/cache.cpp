/*
    Cache aware programming!
    
    In algorithm design, programmers can exploit two principles to increase runtime performance:
    Temporal locality means that address ranges that are accessed are likely to be used again in 
    the near future. In the course of time, the same memory address is accessed relatively frequently 
    (e.g. in a loop). This property can be used at all levels of the memory hierarchy to keep memory 
    areas accessible as quickly as possible.
    
    Spatial locality means that after an access to an address range, the next access to an address in 
    the immediate vicinity is highly probable (e.g. in arrays). In the course of time, memory addresses 
    that are very close to each other are accessed again multiple times. This can be exploited by moving 
    the adjacent address areas upwards into the next hierarchy level during a memory access.
*/

#include <chrono>
#include <iostream>

int main()
{
    // create array 
    const int size = 1000;
    static int x[size][size];

    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            x[i][j] = i + j; // instead of x[j][i] since in terms of memory layout, C++ is a row major language
            // std::cout << &x[i][j] << ": i=" << i << ", j=" << j << std::endl;
        }
    }

    // print execution time to console
    auto t2 = std::chrono::high_resolution_clock::now(); // stop time measurement
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "Execution time: " << duration << " microseconds" << std::endl;

    return 0;
}