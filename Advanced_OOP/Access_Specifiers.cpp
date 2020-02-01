// This example demonstrates the privacy levels
// between parent and child classes
#include <iostream>
#include <string>
using std::string;



class Vehicle {
public:
    static int wheels;
    string color = "blue";

    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels!\n";
    }
};

int Vehicle::wheels = 0;

class Car : public Vehicle {
public:
    bool sunroof = false;
};

class Bicycle : private Vehicle {
public:
    bool kickstand = true;
    void Wheels(int w) {wheels = w;}
};

class Scooter : protected Vehicle {
public:
    bool electric = false;
    void Wheels(int w) {wheels = w;}
};

int main() 
{
    Vehicle vehicle;
    Car car;
    car.color = "Blue";
    car.wheels = 4;

    // Check static member
    std::cout << vehicle.wheels << "\n";
    std::cout << car.wheels << "\n";

    Bicycle bicycle;
    Scooter scooter;

    // Check access specifier
    // bicycle.wheels = 2 // doesn't work because bicycle inherits from private Vehicle
    // scooter.wheels = 1 // doesn't work because bicycle inherits from protected Vehicle
    bicycle.Wheels(2); // Mutate instead
    scooter.Wheels(1); // Mutate instead
};