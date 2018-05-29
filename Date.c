#include <stdio.h>
struct Date {
  int year;
  int month;
  int day;
};
void next_day(struct Date day)
{
	if(day.year%4==0&&day.year%100!=0||day.year%400==0)
	{
		if(day.month==2)
		{
			if(day.day<29)
			{
				day.day=day.day+1;
				
			}
			else
			{
				day.day=1;
				day.month=day.month+1;
			}
		}
		else if(day.month==1||day.month==3||day.month==5||day.month==7||day.month==8||day.month==10||day.month==12)
		{
			if(day.day<30)
			{
				day.day=day.day+1;
			}
			else
			{
				day.day=1;
				day.month=day.month+1;
			}
		}
		else
		{
			if(day.day<29)
			{
				day.day=day.day+1;
			}
			else
			{
				day.day=1;
				day.month=day.month+1;
			}
		}
	}
	if(day.day==1&&day.month==1)
	{
		day.year=day.year+1;
	}	
}
void previous_day(struct Date day)
{
		if(day.year%4==0&&day.year%100!=0||day.year%400==0)
	{
		if(day.month==3)
		{
			if(day.day==1)
			{
				day.day=29;
				day.month=2;
			}
			else
			{
				day.day=day.day-1;
				
			}
		}
		else if(day.month==1||day.month==3||day.month==5||day.month==7||day.month==8||day.month==10||day.month==12)
		{
			if(day.day==1)
			{
				day.day=30;
				day.month=day.month-1;
			}
			else
			{
				day.day=day.day-1;
			
			}
		}
		else
		{
			if(day.day==1)
			{
				day.day=31;
				day.month=day.month-1;
			}
			else
			{
				day.day=day.day-1;
			
			}
		}
	}
	if(day.day==31&&day.month==12)
	{
		day.year=day.year-1;
	}
}
int equal(struct Date one, struct Date day)
{
	if(one.year==day.year&&one.month==day.month&&one.day==day.day)
	{
		return 1;
	}
	else
	{
		return 0;
	}
} 
void show(struct Date day) 
{
  printf("%d %d %d",day.year,day.month,day.day\n);
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
