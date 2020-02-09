/*
    The circular reference lines produce a circular reference. 
    When myClass1 goes out of scope at the end of main, its 
    destructor can’t clean up memory as there is still a 
    reference count of 1 in the smart pointer, which is 
    caused by the shared pointer _member in myClass2. 
    The same holds true for myClass2, which can not be 
    properly deleted as there is still a shared pointer 
    to it in myClass1. This deadlock situation prevents 
    the destructors from being called and causes a memory leak.
*/

#include <iostream>
#include <memory>

class MyClass
{
public:
    std::shared_ptr<MyClass> _member;
    ~MyClass() { std::cout << "Destructor of MyClass called" << std::endl; }
};

int main()
{
    std::shared_ptr<MyClass> myClass1(new MyClass);
    std::shared_ptr<MyClass> myClass2(new MyClass);
    
    // Circular reference
    myClass1->_member = myClass2;
    myClass2->_member = myClass1;
    
    std::cout << "shared pointer count = " << myClass1.use_count() << std::endl;
    std::cout << "shared pointer count = " << myClass2.use_count() << std::endl;

    return 0;
}