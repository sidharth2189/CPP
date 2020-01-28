#include <assert.h>
#include <string>
#include <iostream>
using std::string;
using std::cout;

// TODO: Define class Person
class Person {
    // TODO: Define a public member variable: name
    public:
        string name;
        // Constructor declaration
        Person (string nm);
};
  // TODO: Define a public constructor with an initialization list
Person::Person (string nm): name(nm) {}

// Test
int main() {
  Person alice("Alice");
  Person bob("Bob");
  assert(alice.name != bob.name);
}