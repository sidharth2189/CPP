/*
    Overriding
*/

#include <assert.h>
#include <cmath>

// TODO: Define PI
#define PI 3.14159

// TODO: Declare abstract class VehicleModel
class VehicleModel {
    // TODO: Declare virtual function Move()
    virtual void Move(double v, double phi) = 0;
};  

// TODO: Derive class ParticleModel from VehicleModel
class ParticleModel : public VehicleModel {
    // TODO: Override the Move() function
    public:
    void Move(double v, double phi) override {
        theta_ += phi;
        x_ += v * cos(theta_);
        y_ += v * sin(theta_);
    }
  // TODO: Define x, y, and theta
    double x_ = 0;
    double y_ = 0;
    double theta_ = 0;
};
  

// TODO: Derive class BicycleModel from ParticleModel
class BicycleModel : public ParticleModel {
    // TODO: Override the Move() function
    public:
    void Move(double v, double phi) override {
        theta_ += v / L_ * tan(phi);
        x_ += v * cos(theta_);
        y_ += v * sin(theta_);
    }
  // TODO: Define L
    double L_ = 1;
};
  

// TODO: Pass the tests
int main() {
  // Test function overriding
  ParticleModel particle;
  BicycleModel bicycle;
  particle.Move(10, PI / 9);
  bicycle.Move(10, PI / 9);
  assert(particle.x_ != bicycle.x_);
  assert(particle.y_ != bicycle.y_);
  assert(particle.theta_ != bicycle.theta_);
}