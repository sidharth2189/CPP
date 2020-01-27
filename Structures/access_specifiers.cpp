#include <cassert>
#include <iostream>

// TODO: Define public accessors and mutators for the private member variables
struct Date {
 public:
    // Set day
    void Day(int d)
    {
        if (d > 0 && d <= 31)
        {
            day = d;
        }
    }
    
    // Get day
    int Day()
    {
        return day;
    }
    
    // Set month
    void Month(int m)
    {
        if (m > 0 && m <= 12)
        {
            month = m;
        }
    }
    
    // Get month
    int Month()
    {
        return month;
    }
    
    // Set year
    void Year(int y)
    {
        year = y;
    }
    
    // Get year
    int Year()
    {
        return year;
    }
    
 private:
  int day{1};
  int month{1};
  int year{0};
};

int main() {
  Date date;
  date.Day(29);
  date.Month(8);
  date.Year(1981);
  assert(date.Day() == 29);
  assert(date.Month() == 8);
  assert(date.Year() == 1981);
  std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
}