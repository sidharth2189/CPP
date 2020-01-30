/*
    Abstraction is used to expose only relevant information to the user. 
    By hiding implementation details, we give ourselves flexibility to modify how the program works.
*/

#include <cassert>
#include <cmath>
#include <stdexcept>

class Sphere {
 public:
  Sphere(int radius) : radius_(radius), volume_(pi_ * 4 / 3 * pow(radius, 3)) {}

  int Radius() const { return radius_; }
  float Volume() const { return volume_; }

  // TODO: mutators
  void Radius(int r) {
      if (r <= 0) throw std::invalid_argument("radius must be positive");
      radius_ = r;
      volume_ = pi_ * 4 / 3 * pow(radius_, 3);
  }
  

 private:
  float const pi_{3.14159};
  int radius_;
  float volume_;
};

// Test
int main(void) {
  Sphere sphere(5);
  assert(sphere.Radius() == 5);
  assert(abs(sphere.Volume() - 523.6) < 1);

  sphere.Radius(3);
  assert(sphere.Radius() == 3);
  assert(abs(sphere.Volume() - 113.1) < 1);

  bool caught{false};
  try {
    sphere.Radius(-1);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}