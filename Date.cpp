#include<iostream> 
using namespace std;

int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
class Date {
public:
  Date(int y, int m, int d);
//  ~Date();

  void nextDay();
  void previousDay();
  bool equal(Date other);
  void show();
private:
  int year;
  int month;
  int day;
};

Date::Date(int y,int m,int d)
{
	year=y;
	month=m;
	day=d;
}

void Date::nextDay()
{
	if(year%400==0||year%100!=0&&year%4==0)
	a[2]=29;
	else
	a[2]=28;	
	if(day<a[month])
	day++;
	else if(day==a[month]&&month==12)
	{
		day=1;
	    month=1;
	    year++;
	}
	else
	{
		day=1;
		month++;
	}
}

void Date::previousDay()
{
	if(year%400==0||year%100!=0&&year%4==0)
	a[2]=29;
	else
	a[2]=28;
	if(day>1)
	day--;
	else if(day==1&&month==1)
	{
		month=12;
		day=31;
		year--;
	}
	else
	{
		month--;
		day=a[month];
	}
}

void Date::show()
{
	cout<<year<<"Äê"<<month<<"ÔÂ" <<day<<"ÈÕ"<<endl;
}

bool Date::equal(Date other)
{
	if(other.day==day&&other.month==month&&other.year)
	return true;
	else
	return false;
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
