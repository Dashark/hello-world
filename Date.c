#include<stdio.h> 
struct Date {
  int year;
  int month;
  int day;
};
int a[100]={365,31,28,31,30,31,30,31,31,30,31,30,31};
void next_day(struct Date day);
void previous_day(struct Date day);
int equal(struct Date one, struct Date day);
void show(struct Date day) {
  printf("%dÄê%dÔÂ%dÈÕ\n",day.year,day.month,day.day);
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
  if(equal(today, day))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
  return 0;
}
int equal(struct Date one, struct Date day){
	if(day.year==one.year&&day.month==one.month&&day.day==one.day) return 1;
	else return 0;
	
}


void next_day(struct Date day){
	if(day.year%400==0||(day.year%4==0&&day.year%100!=0))a[2]=29;
	else a[2]=28;
	if(day.day<a[day.month]) {day.day++;
	}
	else if(day.day==a[day.month]&&day.month==12) {day.year++;day.month=1;day.day=1;
	}
	else {day.day=1;day.month++;
	}
	
}

void previous_day(struct Date day){
	if(day.year%400==0||(day.year%4==0&&day.year%100!=0)){a[2]=29;
	}
	else {a[2]=28;
	}
	if(day.day<=a[day.month]) {day.day--;
	}
	else if(day.day=1&&day.month==1) {day.year--;day.month=12;day.day=31;
	}
	else {day.day=a[day.month-1];day.month--;
	}
}


