#include <stdio.h>
#include <iostream>
using namespace std;
int monthday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int monthday2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};


class Date {
public:
	Date(int y, int m, int d):year(y),month(m),day(d){}
	int gety(){return year;}
	int getm(){return month;}
	int getd(){return day;}
  void nextDay();
  void previousDay();
  bool equal(Date other);
  void show();
private:
  int year;
  int month;
  int day;
};
void Date::nextDay(){
	int run = ((year%4==0 && year%100!=0) || (year%400==0)) ? 1 : 0;
	day++;
	if(run==1){
		if(day>monthday2[month]){
			day=1;
			month++;
			if(month >12){
				year++;
				month=1;
			}
		}
	}
	else{
		if(day>monthday[month]){
			day=1;
			month++;
			if(month >12){
				year++;
				month=1;
			}
		}
	}
}

void Date::previousDay(){
	day--;
	if(day==1){
		if(day==0){
			month--;
			if(month==0){
				month=12;
				year--;
			}
			day = monthday2[month];
		}
	}
	else{
		if(day==0){
			month--;
			if(month==0){
				month=12;
				year--;
			}
			day = monthday[month];
		}
	}
}

bool Date::equal(Date other){
	if((this->getd() == other.getd()) &&(this->gety() == other.gety()) && (this->getm() == other.getm()))
		return 1;
	return 0;
}
void Date::show(){
	cout<<year<<'-'<<month<<'-'<<day<<endl;
}



int main() {
	int i;
  Date today(2018,3,20);
  Date day(2018,3,20);
  day.show();
  for(i=0;i<30;i++)
    day.nextDay();
  day.show();
  for(i=0;i<30;i++)
    day.previousDay();
  day.show();
  if(day.equal(today))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
  return 0;
}
