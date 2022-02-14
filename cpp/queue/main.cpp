#include <iostream>
#include "queue.h"

void print(T q)
{
    for (auto &itr: q) {std::cout << itr << std::endl;}
    std::cout << "-----end-----" << std::endl;
}

int main()
{
    // Create a queue
    queue q;

    // Add elements to queue
    q.push(1);
    q.push(2);
    q.push(3);

    // print queue
    print(q);
    
    // Remove an first item from queue
    q.pop();

    // print queue
    print(q);

}