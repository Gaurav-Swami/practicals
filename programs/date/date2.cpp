#include <iostream>
#include <conio.h>

using namespace std;

class Calender
{
  int day, month, year;

public:
  Calender(int day, int month, int year)
  {
    this->day = day;
    this->month = month;
    this->year = year;
  }

  void display()
  {
    cout << day << "/" << month << "/" << year;
  }
  void addDay()
  {

    int noofdays, arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cout << "\nEnter the number of days you want to add: ";
    cin >> noofdays;

    day += noofdays;
    while (day > arr[month])
    {

      day = day - arr[month];
      month++;
      if (month > 12)
      {
        month -= 12;
        year++;
      }
      if ((year % 4 == 0 && (year % 100 != 0)) || year % 400 == 0)
      {
        arr[2] = 29;
      }
      else
      {
        arr[2] = 28;
      }
    }
  }
};

int main()
{
  Calender date(10, 12, 2005);
  date.display();
  date.addDay();
  date.display();

  getch();
  return 0;
}