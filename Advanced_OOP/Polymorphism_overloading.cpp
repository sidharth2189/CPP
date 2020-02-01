/*
    In the context of object-oriented programming, polymorphism) 
    describes a paradigm in which a function may behave differently 
    depending on how it is called. In particular, the function will 
    perform differently based on its inputs.Polymorphism can be achieved 
    in two ways in C++: overloading and overriding.

    In C++, you can write two (or more) versions of a function with the same name.
    This is called "overloading". Overloading requires that we leave the function 
    name the same, but we modify the function signature. For example, we might define 
    the same function name with multiple different configurations of input arguments.
*/

// TODO: Write hello() function
#include <iostream>
void hello(){std::cout << "Hello, Human!" << '\n';}

// TODO: Overload hello() three times
class Human {};
class Animal {};
class Bird {};

void hello (Human human) {std::cout << "Hello, Human!" << '\n';}
void hello (Animal animal) {std::cout << "Hello, Animal!" << '\n';}
void hello (Bird bird) {std::cout << "Hello, Bird!" << '\n';}

// TODO: Call hello() from main()
int main() {
    Human human;
    Animal animal;
    Bird bird;
    hello(human);
    hello(animal);
    hello(bird);
}