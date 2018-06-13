#include<iostream>
#include<stdio.h>
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
int month1[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int month2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
Date::Date(int y, int m, int d){
	year=y;
	month=m;
	day=d;
}
Date::~Date(){
}
bool isrunnian(int year){
  if(year%100==0){
    if(year%4==0){
        return true; 
    }else{
        return false;
    }
  }else{
    if(year%4==0){
        return true; 
    }else{
        return false;
    }
  }
}
void Date::nextDay(){
	day++;
    if(isrunnian(year)){
      if(day>month2[month]){
        day=1;
        month++;
      }
    }else{
      if(day>month2[month]){
      day=1;
        month++;
    	}   
    }
	if(month>12){
        month=1;
        year++;
    } 
}
void Date::previousDay(){
	day--;
    if(day==0){
        month--;
        if(isrunnian(year)){
            day=month2[month];
        }else{
            day=month1[month];
        }       
    }
  if(month==0){
    month=12;
    year--;
  }
}
bool Date::equal(Date other){
	if(other.year==year&&other.month==month&&other.day==day){
        return true;
    }else{
        return false;
    }
}
void Date::show() {
  printf("%04d%01d%01d\n",year,month,day);
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
