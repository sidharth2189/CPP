/*
    The Rule of Five is especially important in resource management, where unnecessary 
    copying needs to be avoided due to limited resources and performance reasons. Also, 
    all the STL container classes such as std::vector implement the Rule of Five and use 
    move semantics for increased efficiency.

    The Rule of Five states that if you have to write one of the functions listed below 
    then you should consider implementing all of them with a proper resource management 
    policy in place. If you forget to implement one or more, the compiler will usually 
    generate the missing ones (without a warning) but the default versions might not be 
    suitable for the purpose you have in mind. The five functions are:

    The destructor: Responsible for freeing the resource once the object it belongs to 
    goes out of scope.

    The assignment operator: The default assignment operation performs a member-wise shallow 
    copy, which does not copy the content behind the resource handle. If a deep copy is needed, 
    it has be implemented by the programmer.

    The copy constructor: As with the assignment operator, the default copy constructor performs 
    a shallow copy of the data members. If something else is needed, the programmer has to implement 
    it accordingly.

    The move constructor: Because copying objects can be an expensive operation which involves creating, 
    copying and destroying temporary objects, rvalue references are used to bind to an rvalue. Using 
    this mechanism, the move constructor transfers the ownership of a resource from a (temporary) 
    rvalue object to a permanent lvalue object.

    The move assignment operator: With this operator, ownership of a resource can be transferred 
    from one object to another.
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

int main()
{
    MyMovableClass obj1(10); // regular constructor
    MyMovableClass obj2(obj1); // copy constructor
    obj2 = obj1; // copy assignment operator

    return 0;
}