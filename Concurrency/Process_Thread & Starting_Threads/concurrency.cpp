/*
    The concurrency support in C++ makes it possible for a program to execute multiple 
    threads in parallel. Concurrency was first introduced into the standard with C++11. 
    Since then, new concurrency features have been added with each new standard update, 
    such as in C++14 and C++17.

    The standardization of concurrency in C++ now makes it possible to develop cross-platform 
    concurrent programs, which is as significant improvement that saves time and reduces error 
    proneness. Concurrency in C++ is provided by the thread support library, which can be 
    accessed by including the header.

    A running program consists of at least one thread. When the main function is executed, we 
    refer to it as the "main thread". Threads are uniquely identified by their thread ID, which 
    can be particularly useful for debugging a program.
*/

#include <iostream>
#include <thread>

int main()
{
    // prints the thread identifier of the main thread to the console    
    std::cout << "Hello concurrent world from main! Thread id = " << std::this_thread::get_id() << std::endl;

    // Retrieves the number of available CPU cores of a system
    unsigned int nCores = std::thread::hardware_concurrency();
    std::cout << "This machine supports concurrency with " << nCores << " cores available" << std::endl;

    return 0;
}