#include <iostream>
#include <cmath>
#include <assert.h>

// Define pi
# define PI 3.14;

// Define LineSegment Class
class LineSegment {
   // Define protected attribute length
    public:
    LineSegment(float line) : length_(line) {}
    // protected:
    float length_;
};   
    
// Define Circle subclass
class Circle {
   // Define public setRadius() and getArea()
    public:
    Circle(LineSegment rad) : radius_(rad) {}
    LineSegment radius_;
    void setRadius(LineSegment rad) {radius_ = rad;}
    LineSegment getRadius() {return radius_;}
    float Area() {return pow(radius_.length_, 2) * PI;}
};   
    
// Test in main()
int main() 
{
    LineSegment linesegment(3);
    Circle circle(linesegment.length_);
    std::cout << circle.Area() << "\n";
    assert(abs(float(circle.Area()) - 28.26) < 0.01);
}