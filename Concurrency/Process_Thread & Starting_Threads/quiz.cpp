/*
    In the code, a thread function called threadFunctionEven can be found, which is passed 
    to a thread t. In this example, the thread is immediately detached after creation. To 
    ensure main does not quit before the thread is finished with its work, there is a 
    sleep_for call at the end of main.

    Code creates a new function called threadFunctionOdd that outputs the string "Odd threadn" and
    uses a for-loop that starts 6 threads and immediately detaches them. Based on whether 
    the increment variable is even or odd, loop passes the respective function to the thread.

    Output:
    The order in which even and odd threads are executed changes. Also, some threads are executed 
    after the main function reaches its end. When sleep_for is removed, threads will not finish 
    before the program terminates.
*/
#include <iostream>
#include <thread>

void threadFunctionEven()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
    std::cout << "Even thread\n";
}

/* Task START */
void threadFunctionOdd()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
    std::cout << "Odd thread\n";
}
/* Task END */

int main()
{
    /* Task START */
    for (int index = 0; index < 6; index++)
    {
        // create thread
        if (index%2 == 0)
        {
            std::thread t(threadFunctionEven);

            // detach thread and continue with main
            t.detach();
        }
        else
        {
            std::thread t(threadFunctionOdd);
            
            // detach thread and continue with main
            t.detach();
        }
    }
    /* Task END */

    // ensure that main does not return before the threads are finished
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work

    std::cout << "End of main is reached" << std::endl;
    return 0;
}
