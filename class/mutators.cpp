#include <string>
#include <cstring>
#include <iostream>
using std::string;
using std::cout;

class Car {
    // TODO: Declare private attributes
    private:
    int horsepower;
    float weight;
    string brand;
        
    // TODO: Declare getter and setter for brand
    public:
    // Constructor declaration
    // Car (string str, int hp, float wt);
    
    // Mutators
    void set_brand(char*);
    void set_horsepower(int hp);
    void set_weight(float wt);
    
    // Accessors
    string get_brand() const;
    int get_horsepower() const;
    float get_weight() const;
};

// Constructor definition
// Car::Car (string str, int hp, float wt){
//     set_brand(str);
//     set_horsepower(hp);
//     set_weight(wt);
// }

// Define setters
void Car::set_brand(char* brand_name) {brand = brand_name;}
void Car::set_horsepower(int hp) {horsepower = hp;}
void Car::set_weight(float wt) {weight = wt;}

// Define getters
string Car::get_brand() const {return brand;}
int Car::get_horsepower() const {return horsepower;}
float Car::get_weight() const {return weight;}

// Test in main()
int main() 
{
    Car car;
    char brand_name[] = "Peugeot";
    car.set_brand(brand_name);
    cout << car.get_brand() << "\n";   
}