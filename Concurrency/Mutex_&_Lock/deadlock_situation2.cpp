/*
    A second type of deadlock is a state in which two or more threads are blocked 
    because each thread waits for the resource of the other thread to be released 
    before releasing its resource. The result of the deadlock is a complete standstill. 
    The thread and therefore usually the whole program is blocked forever. The following 
    code illustrates the problem:
    
    When the program is executed, it produces the following output:

    Thread AThread B

    Notice that it does not print the "Finished" statement nor does it return - the 
    program is in a deadlock, which it can never leave.

    Let us take a closer look at this problem:

    ThreadA and ThreadB both require access to the console. Unfortunately, they request 
    this resource which is protected by two mutexes in different order. If the two threads 
    work interlocked so that first ThreadA locks mutex 1, then ThreadB locks mutex 2, the 
    program is in a deadlock: Each thread tries to lock the other mutex and needs to wait 
    for its release, which never comes. The following figure illustrates the problem graphically.

    Image: Refere deadlock2.png
*/

#include <iostream>
#include <thread>
#include <mutex>
 
std::mutex mutex1, mutex2;
 
void ThreadA()
{
    // Creates deadlock problem
    mutex2.lock();
    std::cout << "Thread A" << std::endl;
    mutex1.lock();
    mutex2.unlock();
    mutex1.unlock();
}
 
void ThreadB()
{
    // Creates deadlock problem
    mutex1.lock();
    std::cout << "Thread B" << std::endl;
    mutex2.lock();
    mutex1.unlock();
    mutex2.unlock();
}
 
void ExecuteThreads()
{
    std::thread t1( ThreadA );
    std::thread t2( ThreadB );
 
    t1.join();
    t2.join();
 
    std::cout << "Finished" << std::endl;
}
 
int main()
{
    ExecuteThreads();
 
    return 0;
}