/*
    There is a class Vehicle that has a single data member (int _id). Also, there 
    is a class WaitingVehicles, which is supposed to store a number of vehicles in 
    an internal vector. Note that contrary to the lesson project, a vehicle is moved 
    into the vector using an rvalue reference. Also note that the push_back function 
    is commented out here. The reason for this is that we are trying to provoke a data 
    race - leaving push_back active would cause the program to crash (we will comment 
    it in later). This is also the reason why there is an auxiliary member _tmpVehicles, 
    which will be used to count the number of Vehicles added via calls to pushBack(). 
    This temporary variable will help us expose the data race without crashing the program.

    In main(), a for-loop is used to launch a large number of tasks who all try to add 
    a newly created Vehicle to the queue. Running the program synchronously with launch 
    option std::launch::deferred generates the following output on the console:

    #vehicles = 1000

    Just as one would have expected, each task inserted an element into the queue with 
    the total number of vehicles amounting to 1000.

    Now let us enforce a concurrent behavior and change the launch option to std::launch::async. 
    This generates the following output (with different results each time):

    #vehicles = 992

    It seems that not all the vehicles could be added to the queue. But why is that? Note 
    that in the thread function "pushBack" there is a call to sleep_for, which pauses the 
    thread execution for a short time. This is the position where the data race occurs: 
    First, the current value of _tmpVehicles is stored in a temporary variable oldNum. 
    While the thread is paused, there might (and will) be changes to _tmpVehicles performed 
    by other threads. When the execution resumes, the former value of _tmpVehicles is written 
    back, thus invalidating the contribution of all the threads who had write access in the 
    mean time. Interestingly, when sleep_for is commented out, the output of the program is 
    the same as with std::launch::deferred - at least that will be the case for most of the 
    time when we run the program. But once in a while, there might be a scheduling constellation 
    which causes the bug to expose itself
*/

#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include<algorithm>

class Vehicle
{
public:
    Vehicle(int id) : _id(id) {}

private:
    int _id;
};

class WaitingVehicles
{
public:
    WaitingVehicles() : _tmpVehicles(0) {}

    // getters / setters
    void printSize()
    {
        std::cout << "#vehicles = " << _tmpVehicles << std::endl;
    }

    // typical behaviour methods
    void pushBack(Vehicle &&v)
    {
        // _vehicles.push_back(std::move(v)); // data race would cause an exception
        int oldNum = _tmpVehicles;
        std::this_thread::sleep_for(std::chrono::microseconds(1)); // wait deliberately to expose the data race
        _tmpVehicles = oldNum + 1;
    }

private:
    std::vector<Vehicle> _vehicles; // list of all vehicles waiting to enter this intersection
    int _tmpVehicles; 
};

int main()
{
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles); 
    std::vector<std::future<void>> futures;
    for (int i = 0; i < 1000; ++i)
    {
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
        ftr.wait();
    });

    queue->printSize();

    return 0;
}