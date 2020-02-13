/*
    The std::thread constructor can also be called with instances of classes that 
    implement the function-call operator. In the following code, a class is defined that 
    has an overloaded ()-operator.

    An error is generated while compiling the code.

    The extra parentheses suggested by the compiler avoid what is known as C++'s "most 
    vexing parse", which is a specific form of syntactic ambiguity resolution in the 
    C++ programming language

    The "most vexing parse" comes from a rule in C++ that says that anything that could 
    be considered as a function declaration, the compiler should parse it as a function 
    declaration - even if it could be interpreted as something else.

    The Line that says: std::thread t0(Vehicle()); could possibly have two interpretations
    1- a variable definition for variable t0 of class std::thread, initialized with an anonymous 
    instance of class Vehicle or
    2- a function declaration for a function t0 that returns an object of type std::thread and 
    has a single (unnamed) parameter that is a pointer to function returning an object of type Vehicle

    Most programmers would presumable expect the first case to be true, but the C++ standard requires 
    it to be interpreted as the second - hence the compiler warning

    There are three ways of forcing the compiler to consider the line as the first case, which would 
    create the thread object we want:

    -Add an extra pair of parentheses
    -Use copy initialization
    -Use uniform initialization with braces
*/
#include <iostream>
#include <thread>

class Vehicle
{
public:
    void operator()()
    {
        std::cout << "Vehicle object has been created \n" << std::endl;
    }
};


int main()
{
    // create thread 
    //std::thread t0(Vehicle()); // C++'s most vexing parse
    
    std::thread t1( (Vehicle()) ); // Add an extra pair of parantheses
    
    std::thread t2 = std::thread( Vehicle() ); // Use copy initialization
    
    std::thread t3{ Vehicle() }; // Use uniform initialization with braces

    // do something in main()
    std::cout << "Finished work in main \n";

    // wait for thread to finish
    // t0.join(;)
    t1.join();
    t2.join();
    t3.join();

    return 0;
}