#include <cassert>

class Date {
public:
  Date(int day, int month, int year);
  int Day() const { return day_; }
  void Day(int day);
  int Month() const { return month_; }
  void Month(int month);
  int Year() const { return year_; }
  void Year(int year);

private:
  int day_{1};
  int month_{1};
  int year_{0};
  int calc_day(int month_, int year_)
  {
      if (month_ != 2 && month_ != 4 && month_ != 6 && month_ != 9 && month_ != 11)
        {
            return 31;
        }
        else if (month_ != 2)
        {
            return 30;
        }
        else // February
        {
            if ((year_%4 == 0 && year_%100 != 0) || (year_%400 == 0)) // Leap year
            {
                return 29;
            }
            else // Common year
            {
                return 28;  
            }
        }
      return 31;
  }
};

Date::Date(int day, int month, int year) {
  Year(year);
  Month(month);
  Day(day);
}

void Date::Day(int day) {
  if (day >= 1 && day <= calc_day(month_, year_))
    day_ = day;
}

void Date::Month(int month) {
  if (month >= 1 && month <= 12)
    month_ = month;
}

void Date::Year(int year) { year_ = year; }

// Test
int main() {
  Date date(29, 2, 1981);
  assert(date.Day() == 29);
  assert(date.Month() == 8);
  assert(date.Year() == 1981);
}