/*
    1-Constructors/Destructors:
    Unlike malloc( sizeof(MyClass) ), the call new MyClass() calls the constructor. 
    Similarly, delete calls the destructor.

    2-Type safety: malloc returns a void pointer, which needs to be cast into the 
    appropriate data type it points to. This is not type safe, as one can freely 
    vary the pointer type without any warnings or errors from the compiler
*/

#include <stdlib.h>
#include <iostream>

class MyClass
{
private:
    int *_number;

public:
    MyClass()
    {
        std::cout << "Allocate memory\n";
        _number = (int *)malloc(sizeof(int));
    }
    ~MyClass()
    {
        std::cout << "Delete memory\n";
        free(_number);
    }
    void setNumber(int number)
    {
        *_number = number;
        std::cout << "Number: " << _number << "\n";
    }
};


int main()
{
    // allocate memory using malloc
    // comment these lines out to run the example below
    // MyClass *myClass = (MyClass *)malloc(sizeof(MyClass));
    // myClass->setNumber(42); // EXC_BAD_ACCESS
    // free(myClass);
	  
	// allocate memory using new
    MyClass *myClass = new MyClass();
    myClass->setNumber(42); // works as expected
    delete myClass;

    // Separation of memory allocation from object construction
    void *memory = malloc(sizeof(MyClass)); // Allocate memory 
    // "Placement new" constructs object at preallocated memory
    MyClass *object = new (memory) MyClass;
    object->setNumber(42);
    object->~MyClass();
    free(memory);
    return 0;

    return 0;
}

/* 
    The call to new has the following consequences:

    1-Memory is allocated to hold a new object of type MyClass
    2-A new object of type MyClass is constructed within the allocated 
    memory by calling the constructor of MyClass
    
    The call to delete causes the following:

    1-The object of type MyClass is destroyed by calling its destructor
    2-The memory which the object was placed in is deallocated
*/