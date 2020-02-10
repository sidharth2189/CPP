/*
    When passing a shared pointer by value, move semantics are not needed. 
    As with unique pointers, there is an underlying rule for transferring 
    the ownership of a shared pointer to a function:

    R.34: Take a shared_ptr parameter to express that a function is part owner

    Consider the example below. The main difference in this example is 
    that the MyClass instance is managed by a shared pointer. After creation 
    in main(), the address of the pointer object as well as the current reference 
    count are printed to the console. Then, sharedPtr is passed to the function f() 
    by value, i.e. a copy is made. After returning to main, pointer address and 
    reference counter are printed again.

    Throughout the program, the address of the managed object does not change. 
    When passed to f() , the reference count changes to 2. After the function 
    returns and the local shared_ptr is destroyed, the reference count changes 
    back to 1. In summary, move semantics are usually not needed when using 
    shared pointers. Shared pointers can be passed by value safely and the main 
    thing to remember is that with each pass, the internal reference counter is 
    increased while the managed object stays the same.

    A weak_ptr can be passed by value as well, just like the shared pointer. 
    The only difference is that the pass does not increase the reference counter.
*/

#include <iostream>
#include <memory>

class MyClass
{
private:
    int _member;

public:
    MyClass(int val) : _member{val} {}
    void printVal() { std::cout << ", managed object " << this << " with val = " << _member << std::endl; }
};

void f(std::shared_ptr<MyClass> ptr)
{
    std::cout << "shared_ptr (ref_cnt= " << ptr.use_count() << ") " << &ptr;
    ptr->printVal();
}

int main()
{
    std::shared_ptr<MyClass> sharedPtr = std::make_shared<MyClass>(23);
    std::cout << "shared_ptr (ref_cnt= " << sharedPtr.use_count() << ") " << &sharedPtr;
    sharedPtr->printVal();

    f(sharedPtr);

    std::cout << "shared_ptr (ref_cnt= " << sharedPtr.use_count() << ") " << &sharedPtr;
    sharedPtr->printVal();

    return 0;
}