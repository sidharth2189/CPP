#include <cassert>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
using std::string;
using std::cout;

class Date {
 public:
  Date(int day, int month, int year);
  int Day() const { return day_; }
  void Day(int day);
  int Month() const { return month_; }
  void Month(int month);
  int Year() const { return year_; }
  void Year(int year);
  string String() const;

 private:
  bool LeapYear(int year) const;
  int DaysInMonth(int month, int year) const;
  int day_{1};
  int month_{1};
  int year_{0};
};

Date::Date(int day, int month, int year) {
  Year(year);
  Month(month);
  Day(day);
}

bool Date::LeapYear(int year) const {
  if (year % 4 != 0)
    return false;
  else if (year % 100 != 0)
    return true;
  else if (year % 400 != 0)
    return false;
  else
    return true;
}

int Date::DaysInMonth(int month, int year) const {
  if (month == 2)
    return LeapYear(year) ? 29 : 28;
  else if (month == 4 || month == 6 || month == 9 || month == 11)
    return 30;
  else
    return 31;
}

void Date::Day(int day) {
  if (day >= 1 && day <= DaysInMonth(Month(), Year())) day_ = day;
}

void Date::Month(int month) {
  if (month >= 1 && month <= 12) month_ = month;
}

void Date::Year(int year) {
  year_ = year;
}

string Date::String() const {
    string str;
    switch (Month())
    {
        case 1: str = "January";
            break;
        case 2: str = "February";
            break;
        case 3: str = "March";
            break;
        case 4: str = "April";
            break;
        case 5: str = "May";
            break;
        case 6: str = "June";
            break;
        case 7: str = "July";
            break;
        case 8: str = "August";
            break;
        case 9: str = "September";
            break;
        case 10: str = "October";
            break;
        case 11: str = "November";
            break;
        case 12: str = "December";
            break;
    }
    
    return str + " " + to_string(Day()) + ", " + to_string(Year());
}
// Test
int main() {
  Date date(29, 8, 1981);
  assert(date.String() == "August 29, 1981");
  cout << date.String() << '\n';
}