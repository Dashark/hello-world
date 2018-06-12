}
#include<stdio.h>
using namespace std;
class Date {
public:
  Date(int y, int m, int d);
  //~Date();

  void nextDay();
  void previousDay();
  bool equal(Date other);
  void show();
private:
  int year;
  int month;
  int day;
  int t;
};

Date::Date(int y,int m,int d){
 year=y;
 month=m;
 day=d;
}

void Date::nextDay(){
 if(year%400==0||year%100!=0&&year%4==0) t=29;
 else t=28; 
 if (month==2) {
   if (day<t) day++; else {
      day=1;month++;
   }
    }  else if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12 ) {
      if (day<31) day++; else{
        day=1;month++;
      }
    } else{
      if (day<30) day++; else{
       day=1;month++;
      }
    }
    if (month>12){
     month=1;year++;
    }
}

void Date::previousDay(){
 if(year%400==0||year%100!=0&&year%4==0) t=29;
 else t=28; 
 if (month==3) {
   if (day>1) day--; else {
      day=t;month--;
   }
    }  else if (month==2 || month==4 || month==6 || month==8 || month==9 || month==11 || month==1 ) {
      if (day>1) day--; else{
        day=31;month--;
      }
    } else{
      if (day>1) day--; else{
       day=30;month--;
      }
    }
    if (month<1){
     month=12;year--;
    }
}

bool Date::equal(Date other)
{
 if (other.day==day&&other.month==month&&other.year==year)
 return true;
 else 
 return false;
} 

void Date::show()
{
 cout<<year<<":"<<month<<":"<<day<<endl;
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
