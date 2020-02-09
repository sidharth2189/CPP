/*
    The function RawPointer contains the familiar steps of (1) allocating memory on 
    the heap with new and storing the address in a pointer variable, (2) assigning a 
    value to the memory block using the dereferencing operator * and (3) finally 
    deleting the resource on the heap. As we already know, forgetting to call delete 
    will result in a memory leak.

    The function UniquePointer shows how to achieve the same goal using a smart pointer 
    from the standard library. As can be seen, a smart pointer is a class template that 
    is declared on the stack and then initialized by a raw pointer (returned by new ) to 
    a heap-allocated object. The smart pointer is now responsible for deleting the memory 
    that the raw pointer specifies - which happens as soon as the smart pointer goes out 
    of scope. Note that smart pointers always need to be declared on the stack, otherwise 
    the scoping mechanism would not work.

    The smart pointer destructor contains the call to delete, and because the smart pointer 
    is declared on the stack, its destructor is invoked when the smart pointer goes out of 
    scope, even if an exception is thrown.
*/

#include <memory>

void RawPointer()
{
    int *raw = new int; // create a raw pointer on the heap
    *raw = 1; // assign a value
    delete raw; // delete the resource again
}

void UniquePointer()
{
    std::unique_ptr<int> unique(new int); // create a unique pointer on the stack
    *unique = 2; // assign a value
    // delete is not neccessary
}