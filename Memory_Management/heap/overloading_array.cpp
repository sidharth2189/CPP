/*
    Creating an array of three objects of MyClass. 
    Also, the overloaded new and delete operators 
    have been changed to accept arrays. 

    Interestingly, the memory requirement is larger 
    than expected: With new, the block size was 4 bytes, 
    which is exactly the space required for a single integer. 
    Thus, with three integers, it should now be 12 bytes instead 
    of 16 bytes. The reason for this is the memory allocation 
    overhead that the compiler needs to keep track of the allocated 
    blocks of memory - which in itself consumes memory. 
    
    If we change the above call to e.g. new MyClass[30](), 
    we will see that the overhead of 4 bytes does not change.
*/

#include <iostream>
#include <stdlib.h>

class MyClass
{
    int _mymember;

public:
    MyClass()
    {
        std::cout << "Constructor is called\n";
    }

    ~MyClass()
    {
        std::cout << "Destructor is called\n";
    }

    void *operator new[](size_t size)
    {
        std::cout << "new: Allocating " << size << " bytes of memory" << std::endl;
        void *p = malloc(size);

        return p;
    }

    void operator delete[](void *p)
    {
        std::cout << "delete: Memory is freed again " << std::endl;
        free(p);
    }
};

int main()
{
    MyClass *p = new MyClass[30]();
    delete[] p;
}