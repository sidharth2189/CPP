#include "queue.h"

template <typename T>
void queue::push(T a)
{
    // mtx.lock();   // uncomment if datastructure is not thread safe
    queue_.emplace_back(a);
    // mtx.unlock(); // uncomment if datastructure is not thread safe
}

template <typename T>
void queue::pop()
{
    // mtx.lock();   // uncomment if datastructure is not thread safe
    T a = queue_.begin();
    queue_.erase(a);
    // mtx.unlock(); // uncomment if datastructure is not thread safe

}

template <typename T>
T queue::front()
{
    // mtx.lock();   // uncomment if datastructure is not thread safe
    return queue_.begin();
    // mtx.unlock(); // uncomment if datastructure is not thread safe
}