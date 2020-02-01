// Define base class Animal
#include<iostream>
#include<string>
using std::string;
using std::cout;

class Animal {
    public:
    string name = "Tiger";
    string color = "Stripes";
    int age = 5;
    
    void Print() {
        cout << "I am a " << name << ", " << color << " in color " << \
            "and " << age << " years old." << "\n";
    }
};

// Declare derived class Snake
class Snake : public Animal {
    public:
    float length = 0;
    void MakeSound() {cout << "Hiss.." << "\n";}
    void Info() {cout << "I am " << length << " feet long" << "\n";}
};

// Declare derived class Cat
class Cat : public Animal {
    public:
    float height = 0;
    void MakeSound() {cout << "Mew" << "\n";}
    void Info() {cout << "I am " << height << " feet tall" << "\n";}
};

// Test in main()
int main(){
    Snake snake;
    snake.name = "snake";
    snake.color = "black";
    snake.age = 1;
    snake.length = 2;
    snake.Print();
    snake.Info();
    snake.MakeSound();
        
    Cat cat;
    cat.name = "cat";
    cat.color = "white";
    cat.age = 2;
    cat.height = 1;
    cat.Print();
    cat.Info();
    cat.MakeSound();
}