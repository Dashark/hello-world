#include<iostream>
#include<cstdio>
using namespace std;
class Date {
public:
  Date(int y, int m, int d);
  ~Date();

  void nextDay();
  void previousDay();
  bool equal(Date other);
  void show();
private:
  int year;
  int month;
  int day;
};
Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}
Date::~Date(){}
void Date::show() {
	cout << year << "Äê" << month << "ÔÂ" << day << "ÈÕ" << endl;
}
void Date::nextDay() {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {
		if (day < 31)day++;
		else {
			day = 1; month++;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day < 30)day++;
		else {
			day = 1; month++;
		}
	}
	else if (month == 12) {
		if (day < 31)day++;
		else {
			year++;
			day = month = 1;
		}
	}
	else if (month == 2) {
		if (((year % 4 == 0)&&(year%100!=0))||(year%400==0)) {
			if (day < 29)day++;
			else {
				day = 1;
				month++;
			}
		}
		else {
			if (day < 28)day++;
			else {
				day = 1;
				month++;
			}
		}
	}
}
void Date::previousDay() {
	if ( month == 2 || month == 4 || month == 6 || month == 8 || month == 9||month==11) {
		if (day >1)day--;
		else {
			day = 31; month--;
		}
	}
	else if (month == 5 || month == 7 || month == 10 || month == 12) {
		if (day >1)day--;
		else {
			day =30; month--;
		}
	}
	else if (month == 1) {
		if (day>1)day--;
		else {
			year--;
			day = 31; month = 12;
		}
	}
	else if (month == 3) {
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
			if (day >1)day--;
			else {
				day = 29;
				month--;
			}
		}
		else {
			if (day >1)day--;
			else {
				day = 28;
				month--;
			}
		}
	}
}
bool Date::equal(Date other) {
	if (day == other.day&&year == other.year&&month == other.month)
		return true;
	else return false;
}
int main() {
  Date today(2018,3,20);
  Date day(2018,3,20);
  day.show();
  for(int i=0;i<30;i++)
    day.nextDay();
  day.show();
  for(int i=0;i<30;i++)
    day.previousDay();
  day.show();
  if(day.equal(today))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
  return 0;
}
