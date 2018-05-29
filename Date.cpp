#include<iostream>

using namespace std;

int Month[13] = {-1,31,-1,31,30,31,30,31,31,30,31,30,31};

int JudgeYear(int n)
{
	if(n%4==0 && n%100!=0 || n%400==0) return true;
	else return false;
}


class Date {
public:
  Date(int y, int m, int d):year(y),month(m),day(d){}
  ~Date(){};

  void nextDay();
  void previousDay();
  bool equal(Date);
  void show();
private:
  int year;
  int month;
  int day;
};

void Date::nextDay()
{
	if(month == 2) if(JudgeYear(year)) Month[2] = 29;
	else Month[2] = 28;
	if(day == Month[month])
	{
		if(month == 12)
		{
			day = 1;
			month = 1;
			year++;
		}
		else
		{
			day = 1;
			month++;
		}
	}
	else day++;
}

void Date::previousDay()
{
	if(month == 2) if(JudgeYear(year)) Month[2] = 29;
	else Month[2] = 28;
	if(day==1)
	{
		if(month == 1)
		{
			day = Month[12];
			month = 12;
			year--;
		}
		else
		{
			month--;
			day = Month[month];
		}
	}
	else day--;
}

bool Date::equal(Date other)
{
	if(other.month == month && other.day == day && other.year == year) return true;
	else return false;
}

void Date::show()
{
	std::cout << "year : " << year <<"  month :" << month << "  day :"<<day<<'\n';
}

int main() {
  Date today(2018,3,20);
  Date day(2018,3,20);
  day.show();
  for(int i=0;i<30;i++) day.nextDay();
  day.show();
  for(int i=0;i<30;i++) day.previousDay();
  day.show();
  if(day.equal(today))
   	std::cout << ("Very Good!\n");
  else
    std::cout << ("Very Bad!\n");
  return 0;
}
