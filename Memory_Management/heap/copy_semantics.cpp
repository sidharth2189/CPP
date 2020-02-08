/*
    Resource management is one of the primary responsibilities of a C++ programmer. 
    Among resources such as multi-threaded locks, files, network and database connections 
    this also includes memory. The common denominator in all of these examples is that access 
    to the resource is often managed through a handle such as a pointer. Also, after the 
    resource has been used and is no longer, it must be released again so that it available 
    for re-use by someone else.

    In C++, a common way of safely accessing resources is by wrapping a manager class around 
    the handle, which is initialized when the resource is acquired (in the class constructor) 
    and released when it is deleted (in the class destructor). This concept is often referred 
    to as Resource Acquisition is Initialization (RAII), which we will discuss in greater depth 
    in the next concept. One problem with this approach though is that copying the manager object 
    will also copy the handle of the resource. This allows two objects access to the same resource
     - and this can mean trouble.

    Consider the example below of managing access to a block of heap memory.
    The class MyClass has a private member, which is a pointer to a heap-allocated integer. 
    Allocation is performed in the constructor, deallocation is done in the destructor. 
    This means that the memory block of size sizeof(int) is allocated when the objects 
    myClass1 and myClass2 are created on the stack and deallocated when their scope is left, 
    which happens at the end of the main. The difference between myClass1 and myClass2 is 
    that the latter is instantiated using the copy constructor, which duplicates the members 
    in myClass1 - including the pointer to the heap memory where _myInt resides.

    From the output we can see that the stack address is different for myClass1 and myClass2 
    - as was expected. The address of the managed memory block on the heap however is identical. 
    This means that when the first object goes out of scope, it releases the memory resource by 
    calling free in its destructor. The second object does the same - which causes the program 
    to crash as the pointer is now referencing an invalid area of memory, which has already been 
    freed. 
    
    The default behavior of both copy constructor and assignment operator is to perform 
    a shallow copy.
*/

#include <iostream>

class MyClass
{
private:
    int *_myInt;

public:
    MyClass()
    {
        _myInt = (int *)malloc(sizeof(int));
    };
    ~MyClass()
    {
        free(_myInt);
    };
    void printOwnAddress() { std::cout << "Own address on the stack is " << this << std::endl; }
    void printMemberAddress() { std::cout << "Managing memory block on the heap at " << _myInt << std::endl; }
};

int main()
{
    // instantiate object 1
    MyClass myClass1;
    myClass1.printOwnAddress();
    myClass1.printMemberAddress();

    // copy object 1 into object 2
    MyClass myClass2(myClass1); // copy constructor
    myClass2.printOwnAddress();
    myClass2.printMemberAddress();

    return 0;
}