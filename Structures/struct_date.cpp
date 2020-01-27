// Include iostream for output
#include <cassert>
#include <iostream>

// Define a simple structure
struct Date {
  // initialize members
  int day {1};
  int month {1};
  int year {0};
};

// Define a main function to instantiate and test 
int main()
{
    Date date;
    
    // TODO: Initialize date to August 29, 1981
    date.day = 29;
    date.month = 8;
    date.year = 1981;
    
    
    // TEST
    assert(date.day == 29);
    assert(date.month == 8);
    assert(date.year == 1981);

    // Print the data in the structure
    std::cout << date.day << "/" << date.month << "/" << date.year << "\n";
}