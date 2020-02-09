/*
    In some cases, it can make sense to treat lvalues like rvalues. 
    At some point in your code, you might want to transfer ownership 
    of a resource to another part of your program as it is not needed 
    anymore in the current scope. But instead of copying it, you want 
    to just move it as we have seen before. The "problem" with our 
    implementation of MyMovableClass is that the call useObject(obj1) 
    will trigger the copy constructor as we have seen in one of the last 
    examples. But in order to move it, we would have to pretend to the 
    compiler that obj1 was an rvalue instead of an lvalue so that we can 
    make an efficient move operation instead of an expensive copy.

    There is a solution to this problem in C++, which is std::move. 
    This function accepts an lvalue argument and returns it as an 
    rvalue without triggering copy construction. So by passing an 
    object to std::move we can force the compiler to use move semantics, 
    either in the form of move constructor or the move assignment operator.
*/

#include <stdlib.h>
#include <iostream>

class MyMovableClass
{
private:
    int _size;
    int *_data;

public:
    MyMovableClass(size_t size) // constructor
    {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size*sizeof(int)  << " bytes" << std::endl;
    }

    ~MyMovableClass() // 1 : destructor
    {
        std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
        delete[] _data;
    }
    
    MyMovableClass(const MyMovableClass &source) // 2 : copy constructor
    {
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
    }
    
    MyMovableClass &operator=(const MyMovableClass &source) // 3 : copy assignment operator
    {
        std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
        if (this == &source)
            return *this;
        delete[] _data;
        _data = new int[source._size];
        *_data = *source._data;
        _size = source._size;
        return *this;
    }
    
    MyMovableClass(MyMovableClass &&source) // 4 : move constructor
    {
        std::cout << "MOVING (c’tor) instance " << &source << " to instance " << this << std::endl;
        _data = source._data;
        _size = source._size;
        source._data = nullptr;
        source._size = 0;
    }
    
    MyMovableClass &operator=(MyMovableClass &&source) // 5 : move assignment operator
    {
        std::cout << "MOVING (assign) instance " << &source << " to instance " << this << std::endl;
        if (this == &source)
            return *this;

        delete[] _data;

        _data = source._data;
        _size = source._size;

        source._data = nullptr;
        source._size = 0;

        return *this;
    }
};

void useObject(MyMovableClass obj)
{
    std::cout << "using object " << &obj << std::endl;
}

int main()
{
    MyMovableClass obj1(100); // constructor
    // MyMovableClass obj2 = MyMovableClass(100);

    // useObject(obj2);
    useObject(std::move(obj1));

    return 0;
}