/*
    Inherit from a class
*/

#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    int wheels = 0;
    string color = "blue";
    int seats = 0;
    
    void Print() const
    {
        std::cout << "This " << color << " vehicle has " << wheels << " wheels and " << seats << " seats!" << "\n";
    }
};

class Car : public Vehicle {
public:
    bool sunroof = false;
};

class Bicycle : public Vehicle {
public:
    bool kickstand = true;
};

int main() 
{
    Car car;
    car.wheels = 4;
    car.seats = 2;
    car.sunroof = true;
    car.Print();
    if(car.sunroof)
        std::cout << "And a sunroof!\n";
};