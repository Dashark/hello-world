#include<iostream>
#include<stdio.h>
struct Date {
  int year;
  int month;
  int day;
};
int month1[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int month2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
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
void next_day(struct Date &day);
void previous_day(struct Date &day);
int equal(struct Date one, struct Date day);
void show(struct Date day) {
  printf("%04d%01d%01d\n",day.year,day.month,day.day);
}
void next_day(struct Date &day){
    day.day++;
    if(isrunnian(day.year)){
      if(day.day>month2[day.month]){
        day.day=1;
        day.month++;
      }
    }else{
      if(day.day>month2[day.month]){
      day.day=1;
        day.month++;
    	}   
    }
	if(day.month>12){
        day.month=1;
        day.year++;
    } 
}
void previous_day(struct Date &day){
    day.day--;
    if(day.day==0){
        day.month--;
        if(isrunnian(day.year)){
            day.day=month2[day.month];
        }else{
            day.day=month1[day.month];
        }       
    }
  if(day.month==0){
    day.month=12;
    day.year--;
  }
}
int equal(struct Date one,struct Date day){
    if(one.year==day.year&&one.month==day.month&&one.day==one.day){
        return true;
    }else{
        return false;
    }
}

int main() {
  struct Date today = {2018,3,20};
  struct Date day = {2018,3,20};
  show(day);
  for(int i=0;i<30;i++)
    next_day(day);
  show(day);
  for(int i=0;i<30;i++)
    previous_day(day);
  show(day);
  if(equal(today,day))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
  return 0;
}
