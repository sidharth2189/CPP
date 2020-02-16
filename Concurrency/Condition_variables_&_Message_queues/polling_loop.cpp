/*
    Creating an infinite polling loop
    While the pushBack method is used by the threads to add data to the monitor incrementally, the main thread uses printSize at the end to display all the results at once. Our goal is to change the code in a way that the main thread gets notified every time new data becomes available. But how can the main thread know whether new data has become available? The solution is to write a new method that regularly checks for the arrival of new data.

    In the code listed below, a new method dataIsAvailable() has been added while printIDs() 
    has been removed. This method returns true if data is available in the vector and false 
    otherwise. Once the main thread has found out via dataIsAvailable() that new data is in 
    the vector, it can call the method popBack() to retrieve the data from the monitor object. 
    Note that instead of copying the data, it is moved from the vector to the main method.

    In the main thread, we will use an infinite while-loop to frequently poll the monitor object 
    and check whether new data has become available. Contrary to before, we will now perform the 
    read operation before the workers are done - so we have to integrate our loop before wait() 
    is called on the futures at the end of main(). Once a new Vehicle object becomes available, 
    we want to print it within the loop.

    When we execute the code, we get a console output similar to the one listed below:

    From the output it can easily be seen, that adding and removing to and from the monitor object 
    is now interleaved. When executed repeatedly, the order of the vehicles will most probably differ 
    between executions.

    Writing a vehicle counter
    Note that the program in the example above did not terminate - even though no new 
    Vehicles are added to the queue, the infinite while-loop will not exit.

    One possible solution to this problem would be to integrate a vehicle counter into 
    the WaitingVehicles class, that is incremented each time a Vehicle object is added 
    and decremented when it is removed. The while-loop could then be terminated as soon 
    as the counter reaches zero. Please go ahead and implement this functionality - but 
    remember to protect the counter as it will also be accessed by several threads at 
    once. Also, it will be a good idea to introduce a small delay between spawning threads 
    and collecting results. Otherwise, the queue will be empty by default and the program 
    will terminate prematurely. At the end of main(), please also print the number of 
    remaining Vehicle objects in the vector.
*/

#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <mutex>
#include<algorithm>

class Vehicle
{
public:
    Vehicle(int id) : _id(id) {}
    int getID() { return _id; }

private:
    int _id;
};

class WaitingVehicles
{
public:
    WaitingVehicles() {}

    int getNumVehicles() 
    { 
        std::lock_guard<std::mutex> uLock(_mutex);
        return _numVehicles; 
    }

    bool dataIsAvailable()
    {
        std::lock_guard<std::mutex> myLock(_mutex);
        return !_vehicles.empty();
    }

    Vehicle popBack()
    {
        // perform vector modification under the lock
        std::lock_guard<std::mutex> uLock(_mutex);

        // remove last vector element from queue
        Vehicle v = std::move(_vehicles.back());
        _vehicles.pop_back();

        return v; // will not be copied due to return value optimization (RVO) in C++
    }

    void pushBack(Vehicle &&v)
    {
        // simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // perform vector modification under the lock
        std::lock_guard<std::mutex> uLock(_mutex);

        // add vector to queue
        std::cout << "   Vehicle #" << v.getID() << " will be added to the queue" << std::endl;
        _vehicles.emplace_back(std::move(v));
    }

private:
    std::vector<Vehicle> _vehicles; // list of all vehicles waiting to enter this intersection
    std::mutex _mutex;
    int _numVehicles;
};

int main()
{
    // create monitor object as a shared pointer to enable access by multiple threads
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);

    std::cout << "Spawning threads..." << std::endl;
    std::vector<std::future<void>> futures;
    for (int i = 0; i < 10; ++i)
    {
        // create a new Vehicle instance and move it into the queue
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
    }

    std::cout << "Collecting results..." << std::endl;
    while (true)
    {
        if (queue->dataIsAvailable())
        {
            Vehicle v = queue->popBack();
            std::cout << "   Vehicle #" << v.getID() << " has been removed from the queue" << std::endl;
        }
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
        ftr.wait();
    });

    std::cout << "Finished : " << queue->getNumVehicles() << " vehicle(s) left in the queue" << std::endl;

    return 0;
}