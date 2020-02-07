/*
    One of the major advantages of new/delete over free/malloc 
    is the possibility of overloading. While both malloc and 
    ree are function calls and thus can not be changed easily, 
    new and delete are operators and can thus be overloaded to 
    integrate customized functionality, if needed.

    In the code, both the new and the delete operator are overloaded. 
    In new, the size of the class object in bytes is printed to the 
    console. Also, a block of memory of that size is allocated on the 
    heap and the pointer to this block is returned. In delete, the 
    block of memory is freed again.

    As can be seen from the order of text output, memory is instantiated 
    in new before the constructor is called, while the order is reversed 
    for the destructor and the call to delete.
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

    void *operator new(size_t size)
    {
        std::cout << "new: Allocating " << size << " bytes of memory" << std::endl;
        void *p = malloc(size);

        return p;
    }

    void operator delete(void *p)
    {
        std::cout << "delete: Memory is freed again " << std::endl;
        free(p);
    }
};

int main()
{
    MyClass *p = new MyClass();
    delete p;
}