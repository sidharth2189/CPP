/*
    Running Multiple Threads
    Fork-Join Parallelism
    Using threads follows a basic concept called "fork-join-parallelism". The basic mechanism of this 
    concept follows a simple three-step pattern:

    Split the flow of execution into a parallel thread ("fork")
    Perform some work in both the main thread and the parallel thread
    Wait for the parallel thread to finish and unite the split flow of execution again ("join")
    The following diagram "fork_join_parallelism.jpg" in the folder illustrates the idea of forking.

    In the main thread, the program flow is forked into three parallel branches. In both worker 
    branches, some work is performed - which is why threads are often referred to as "worker 
    threads". Once the work is completed, the flow of execution is united again in the main 
    function using the join() command. In code below, join acts as a barrier where all 
    threads are united. The execution of main is in fact halted, until both worker threads 
    have succesfully executed.
*/

#include <iostream>
#include <thread>
#include <vector>

void printHello()
{
    // perform work
    std::cout << "Hello from Worker thread #" << std::this_thread::get_id() << std::endl;
}

int main()
{
    // create threads
    std::vector<std::thread> threads;
    for (size_t i = 0; i < 5; ++i)
    {
        // copying thread objects causes a compile error
        /*
        std::thread t(printHello);
        threads.push_back(t); 
        */

        // moving thread objects will work
        threads.emplace_back(std::thread(printHello));
    }

    // do something in main()
    std::cout << "Hello from Main thread #" << std::this_thread::get_id() << std::endl;

    // call join on all thread objects using a range-based loop
    for (auto &t : threads)
        t.join();

    // // do something in main()
    // std::cout << "Hello from Main thread #" << std::this_thread::get_id() << std::endl;

    return 0;
}
