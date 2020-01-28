/*
    Initializer lists exist for a number of reasons. 
    First, the compiler can optimize initialization faster from an initialization list 
    than from within the constructor.

    A second reason is a bit of a technical paradox. 
    If you have a const class attribute, you can only initialize it using an initialization list.
    Otherwise, you would violate the const keyword simply by initializing the member in the constructor!

    The third reason is that attributes defined as references must use initialization lists.
*/

#include <assert.h>
#include <string>

struct Person {
public:
  // TODO: Add an initialization list
  Person(std::string name) : name(name){}
  std::string const name;
};

// Test
int main() {
  Person alice("Alice");
  Person bob("Bob");
  assert(alice.name != bob.name);
}