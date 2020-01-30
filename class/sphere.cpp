/*
    Abstraction refers to the separation of a class's interface 
    from the details of its implementation. The interface provides 
    a way to interact with an object, while hiding the details and 
    implementation of how the class works.
*/

#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>

// TODO: Define class Sphere
class Sphere {
 public:
  // Constructor
    Sphere(int r) : radius(r) {}

  // Accessors
    int Radius() const {
        return radius;
    }
    
  // Volume
    float Volume(){
        return (4 * M_PI * pow(radius, 3) / 3);
    }

 private:
  // Private members
    int radius;
};

// Test
int main(void) {
  Sphere sphere(5);
  assert(sphere.Radius() == 5);
  assert(abs(sphere.Volume() - 523.6) < 1);
  std::cout << abs(sphere.Volume() - 523.6) << '\n';
}