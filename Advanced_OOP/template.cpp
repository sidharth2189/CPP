/*
    Generic code is the term for code that is independent of types
    
    Templates enable generic programming by generalizing a function to apply to any class. 
    Specifically, templates use types as parameters so that the same implementation can operate 
    on different data types.
    
    For example, you might need a function to accept many different data types. The function 
    acts on those arguments, perhaps dividing them or sorting them or something else. Rather 
    than writing and maintaining the multiple function declarations, each accepting slightly 
    different arguments, you can write one function and pass the argument types as parameters. 
    At compile time, the compiler then expands the code using the types that are passed as parameters.
*/
# include <iostream>
# include <assert.h>

// Create a generic, templatized function Max()
template <typename Type> Type Max(Type a, Type b) { return a > b ? a : b; }

// Create a generic function Sum that adds two parameters
template <typename Type> Type Sum(Type a, Type b) { return a + b; }

// Create a generic function Product that multiplies two parameters
template <typename Type> Type Product (Type a, Type b) {return a*b; }

// TODO: Declare a generic, templatized average function
template <typename T> T average(T a, T b) { return (a+b)/2;}

int main() { 
    std::cout << Sum<double>(20.0, 13.7) << "\n";
    assert(Product<int>(10, 2) == 20);
    assert(Max(10, 50) == 50);
    assert(Max(5.7, 1.436246) == 5.7);

    // Not required to specify data type. Compiler deduces type of template in C++17
    assert(average(2.0,5.0) == 3.5);  
}