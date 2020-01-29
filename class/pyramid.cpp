#include <cassert>
#include <iostream>
#include <math.h>
using std::cout;

class Pyramid{
    public:
    Pyramid(int length, int width, int height) {
        Length(length);
        Width(width);
        Height(height);
    }

    // Get functions
    int Length() const { return length_;}
    int Width() const { return width_;}
    int Height() const { return height_;}

    // Set functions
    void Length(int length) {
        if (length > 0)
        {
            length_ = length;
        }
    }
    void Width(int width) {
        if (width > 0)
        {
            width_ = width;
        }
    }
    void Height(int height) {
        if (height > 0)
        {
            height_ = height;
        }
    }
    float Volume(){
        return (float(length_ * width_ * height_)/3);
    }
    
    private:
        int length_;
        int width_;
        int height_;
};

int main() {
    // Initialize pyramid object with length, width and height
    Pyramid pyramid(1,2,5);
    assert(pyramid.Length() == 1);
    assert(pyramid.Width() == 2);
    assert(pyramid.Height() == 5);
    // assert(pyramid.Volume() == 3.33);
    cout << pyramid.Volume() << "\n";
}