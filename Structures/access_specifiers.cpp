#include <cassert>
#include <iostream>
using std::cout;

// TODO: Define public accessors and mutators for the private member variables
struct Date {
 public:
    // Set day
    void Day(int d)
    {
        if (month != 2 && month != 4 && month != 6 && month != 9 && month != 11 && d > 0 && d <= 31)
        {
            day = d;
        }
        else if (month != 2 && d > 0 && d <= 30)
        {
            day = d;
        }
        else if (month == 2 && d > 0 && d <= 29)
        {
            if ((year%4 == 0 && year%100 != 0) || (year%400 == 0)) // Leap year
            {
                day = d;
            }
            else // Common year
            {
                if (d > 0 && d <= 28) 
                {
                    day = d;
                }
                else
                {
                    cout << "Invalid date" << "\n";
                    day = 00;
                }
                
            }
            
        }
        else
        {
            cout << "Invalid date " << d << " for the month " << month << "\n";
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
        else
        {
            cout << "Invalid month" << "\n";
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
  date.Year(2020);
  date.Month(4);
  date.Day(31);
  assert(date.Day() == 31);
  assert(date.Month() == 4);
  assert(date.Year() == 2020);
  std::cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
}