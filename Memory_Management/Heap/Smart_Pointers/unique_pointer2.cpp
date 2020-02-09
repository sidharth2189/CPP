/*
    Note that the custom class MyClass has two constructors, one without arguments 
    and one with a string to be passed, which initializes a member variable _text 
    that lives on the stack. Also, once an object of this class gets destroyed, a0
    message to the console is printed, along with the value of _text. In main, two 
    unique pointers are created with the address of a MyClass object on the heap as 
    arguments. With myClass2, we can see that constructor arguments can be passed 
    just as we would with raw pointers. After both pointers have been created, we 
    can use the -> operator to access members of the class, such as calling the 
    function setText. From looking at the function call alone you would not be able 
    to tell that myClass1 is in fact a smart pointer. Also, we can use the dereference 
    operator * to access the value of myClass1 and myClass2 and assign the one to the 
    other. Finally, the . operator gives us access to proprietary functions of the smart 
    pointer, such as retrieving the internal raw pointer with get().
*/

#include <iostream>
#include <memory>
#include <string>

class MyClass
{
private:
    std::string _text;

public:
    MyClass() {}
    MyClass(std::string text) { _text = text; }
    ~MyClass() { std::cout << _text << " destroyed" << std::endl; }
    void setText(std::string text) { _text = text; }
};

int main()
{
    // create unique pointer to proprietary class
    std::unique_ptr<MyClass> myClass1(new MyClass());
    std::unique_ptr<MyClass> myClass2(new MyClass("String 2"));

    // call member function using ->
    myClass1->setText("String 1");

    // use the dereference operator * 
    *myClass1 = *myClass2;

    // use the .get() function to retrieve a raw pointer to the object
    std::cout << "Objects have stack addresses " << myClass1.get() << " and " << myClass2.get() << std::endl;

    return 0;
}