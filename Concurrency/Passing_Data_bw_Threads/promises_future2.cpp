/*
    In addition to promises_future.cpp:
    There are some situations where it might be interesting to separate the waiting 
    for the content from the actual retrieving. Futures allow us to do that using the 
    wait() function. This method will block until the future is ready. Once it returns, 
    it is guaranteed that data is available and we can use get() to retrieve it without 
    delay.

    In addition to wait, the C++ standard also offers the method wait_for, which takes 
    a time duration as an input and also waits for a result to become available. The 
    method wait_for() will block either until the specified timeout duration has elapsed 
    or the result becomes available - whichever comes first. The return value identifies 
    the state of the result.

    In the following code, the wait_for method is used to wait for the availability 
    of a result for one second. After the time has passed (or the result is available) 
    the result is printed to the console. If the time gets over without the result being 
    available, an error message to the console is printed instead.
*/

#include <iostream>
#include <thread>
#include <future>
#include <cmath>

void computeSqrt(std::promise<double> &&prms, double input)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // simulate work
    double output = sqrt(input);
    prms.set_value(output);
}

int main()
{
    // define input data
    double inputData = 42.0;

    // create promise and future
    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();

    // start thread and pass promise as argument
    std::thread t(computeSqrt, std::move(prms), inputData);

// Student task STARTS here
    // wait for result to become available
    // ftr.wait();
    // std::cout << "Result = " << ftr.get() << std::endl;
    auto status = ftr.wait_for(std::chrono::milliseconds(1000));
    if (status == std::future_status::ready) // result is ready
    {
        std::cout << "Result = " << ftr.get() << std::endl;
    }

    //  timeout has expired or function has not yet been started
    else if (status == std::future_status::timeout || status == std::future_status::deferred)
    {
        std::cout << "Result unavailable" << std::endl;
    }
// Student task ENDS here    

    // thread barrier
    t.join();

    return 0;
}
