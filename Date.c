#include<stdio.h> 
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

struct Date 
{ 
  int year;
  int month;
  int day;
};
struct Date *dd;
void next_day(struct Date day);
void previous_day(struct Date day);
int equal(struct Date one, struct Date day);
void show(struct Date day) {
  printf("%d年%d月%d日\n",dd->year,dd->month,dd->day);
}
int main() {
  struct Date today = {2018,3,20};
  struct Date day = {2018,3,20};
  dd=&day;
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

void next_day(struct Date day)
{    
	if(dd->year%400==0||dd->year%100!=0&&dd->year%4==0)
	a[2]=29;
	else
	a[2]=28;	
	if(dd->day<a[dd->month])
	dd->day++;
	else if(dd->day==a[dd->month]&&dd->month==12)
	{
		dd->day=1;
		dd->month=1;
		dd->year++;
	}
	else
	{
		dd->day=1;
		dd->month++;
	}
}

void previous_day(struct Date day)
{
	if(dd->year%400==0||dd->year%100!=0&&dd->year%4==0)
	a[2]=29;
	else
	a[2]=28;
	if(dd->day>1)
	dd->day--;
	else if(dd->day==1&&dd->month==1)
	{
		dd->month=12;
		dd->day=31;
		dd->year--;
	}
	else
	{
		dd->month--;
		dd->day=a[dd->month];
	}
}

int equal(struct Date one, struct Date day)
{
	if(one.day==dd->day&&one.month==dd->month&&one.year==dd->year)
	return 1;
	else
	return 0;
}
