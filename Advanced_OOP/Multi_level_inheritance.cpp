#include <cassert>

// TODO: Declare Vehicle as the base class
class Vehicle {
    public:
    int wheels;
};


// TODO: Derive Car from Vehicle
class Car : public Vehicle {
    public:
    int seats;
};

// TODO: Derive Sedan from Car
class Sedan : public Car {
    public:
    bool trunk;
};


// TODO: Update main to pass the tests
int main() {
  Sedan sedan;
  sedan.wheels = 4;
  sedan.seats = 4;
  sedan.trunk = true;
  assert(sedan.trunk == true);
  assert(sedan.seats == 4);
  assert(sedan.wheels == 4);
}