/*
    Polymorphism: Overriding
    "Overriding" a function occurs when:

    A base class declares a virtual function.
    A derived class overrides that virtual function by defining its own 
    implementation with an identical function signature 
    (i.e. the same function name and argument types).
*/

#include <assert.h>
#include <string>

class Animal {
public:
  virtual std::string Talk() const = 0;
};

// TODO: Declare a class Dog that inherits from Animal
class Dog : public Animal {
    public:
    Dog() {}
    std::string Talk() const {return "Woof";}
};

int main() {
  Dog dog;
  assert(dog.Talk() == "Woof");
}