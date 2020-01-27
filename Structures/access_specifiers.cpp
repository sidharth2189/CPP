#include <iostream>
#include <cassert>
using std::cout;

class Date {
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
                    day = d;
                    cout << "Invalid day" << d << "\n";
                }
                
            }
            
        }
        else
        {
            day = d;
            cout << "Invalid day " << day << " for the month " << month << "\n";
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


// Test in main
int main()
{
    Date date;
    date.Month(4);
    date.Year(2020);
    date.Day(31);
//     assert(date.Month() == 12);
//     assert(date.Year() == 2000);
//     assert(date.Day() == -1);
    cout << date.Day() << "/" << date.Month() << "/" << date.Year() << "\n";
}
