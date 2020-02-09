/*
    We can see that shared pointers are constructed just as unique pointers are. 
    Also, we can access the internal reference count by using the method use_count(). 
    In the inner block, a second shared pointer shared2 is created and shared1 is 
    assigned to it. In the copy constructor, the internal resource pointer is copied 
    to shared2 and the resource counter is incremented in both shared1 and shared2

    The lifetime of shared2 is limited to the scope denoted by the enclosing curly brackets. 
    Thus, once this scope is left and shared2 is destroyed, the reference counter in shared1 
    is decremented by one.
*/

#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> shared1(new int);
    std::cout << "shared pointer count = " << shared1.use_count() << std::endl;

    {
        std::shared_ptr<int> shared2 = shared1;
        std::cout << "shared pointer count = " << shared2.use_count() << std::endl;
    }
    
    std::cout << "shared pointer count = " << shared1.use_count() << std::endl;

    return 0;
}