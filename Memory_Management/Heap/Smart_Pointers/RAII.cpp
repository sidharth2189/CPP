/*
    The constructor of class MyInt takes a pointer to a memory resource. 
    When the destructor of a MyInt object is called, the resource is deleted 
    from memory - which makes MyInt an RAII memory management class. Also, 
    the * operator is overloaded which enables us to dereference MyInt objects 
    in the same manner as with raw pointers
*/

# include <iostream>

class MyInt
{
    int *_p; // pointer to heap data
public:
    MyInt(int *p = NULL) { _p = p; }
    ~MyInt() 
    { 
        std::cout << "resource " << *_p << " deallocated" << std::endl;
        delete _p; 
    }
    int &operator*() { return *_p; } // // overload dereferencing operator
};

int main()
{
    double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    for (size_t i = 0; i < 5; ++i)
    {
        // allocate the resource on the stack
        MyInt en(new int(i));

        // use the resource
        std::cout << *en << "/" << den[i] << " = " << *en / den[i] << std::endl;
    }

    return 0;
}

/*
    The part new int(i) creates a new block of memory on the heap and initializes it with the value of i. 
    The returned result is the address of the block of memory.
    The part MyInt en(…)calls the constructor of class MyInt, passing the address of a valid memory block 
    as a parameter.
    After creating an object of class MyInt on the stack, which, internally, created an integer on the heap, 
    we can use the dereference operator in the same manner as before to retrieve the value to which the 
    internal raw pointer is pointing. Because the MyInt object en lives on the stack, it is automatically 
    deallocated after each loop cycle - which automatically calls the destructor to release the heap memory.

    Above is an RAII implementation to create a memory management class that spares us from thinking about 
    calling delete. By creating the MyInt object on the stack, we ensure that the deallocation occurs as 
    soon as the object goes out of scope. 
*/

/* 
int main() // without RAII
{
    double den[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    for (size_t i = 0; i < 5; ++i)
    {
        // allocate the resource on the heap
        double *en = new double(i);

        // use the resource
        std::cout << *en << "/" << den[i] << " = " << *en / den[i] << std::endl;

        // deallocate the resource
        delete en;
    }

    return 0;
}
*/