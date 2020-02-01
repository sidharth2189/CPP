// This example demonstrates the privacy levels
// between parent and child classes
#include <iostream>
#include <string>
using std::string;
using std::cout;

class Animal {
    public:
    void Talk() const {cout << "Noise\n";}
};

class Human : public Animal {
    public:
    void Talk(string str) {cout << str << '\n';}
};

class Baby : private Human {
    public:
    void Cry() {Talk("Whaa!");}
};

int main()
{
    Human human;
    human.Talk("Hello, World!");
    Baby baby;
    baby.Cry();
    // baby.Talk("The fast fox jumped over the lazy dog!"); // Baby's instance can not access Human's public member
}

