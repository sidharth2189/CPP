// Rectangle and Square friend classes
#include <assert.h>

// Declare class Rectangle
class Rectangle;

// Define class Square as friend of Rectangle
class Square {
    public:
    // Add public constructor to Square, initialize side
    Square(int side) : side_(side) {}
    private:
    // Add private attribute side
    int side_;
    // Add friend class Rectangle
    friend class Rectangle;
};

// Define class Rectangle
class Rectangle {
    public:
    // Define a Rectangle constructor that takes a Square
    Rectangle(Square square) : width_(square.side_), height_(square.side_) {}
    // Define Area() to compute area of Rectangle
    int Area() {return width_*height_;} 
    private:
    // Add private attributes width, height;
    int width_;
    int height_;
};

// Update main() to pass the tests
int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16); 
}