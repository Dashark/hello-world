#include<stdio.h>
struct Date
{
	int year;
	int month;
	int day;
};
struct Date next_day (struct Date day)
{
	int day_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(day.year%4==0)
	{
		if(day.year%100!=0)
			day_month[2]=29;
		else
			if(day.year%400==0)
				day_month[2]=29;
	}
	day.day += 1;
	if(day.day>day_month[day.month])
		day.day=1,day.month+=1;
	if(day.month>12)
		day.month=1,day.year+=1;
	return day;
}

struct Date previous_day (struct Date day)
{
	int day_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(day.year%4==0)
	{
		if(day.year%100!=0)
			day_month[2]=29;
		else
			if(day.year%400==0)
				day_month[2]=29;
	}
	day.day -= 1;
	if(day.day<=0)
	{
		day.month-=1;
		if(day.month<=0)
			day.year-=1,day.month=12;
		day.day=day_month[day.month];
	}
	return day;
}
int equal (struct Date A, struct Date B)
{
	if(A.year==B.year && A.month==B.month && A.day==B.day)
		return true;
	return false;
}
void show (struct Date day)
{
	printf ("%04d/%02d/%02d\n", day.year, day.month, day.day);
}

int main ()
{
	struct Date today = { 2018, 3, 20 };
	struct Date day = { 2018, 3, 20 };
	show (day);
	for (int i = 0; i < 30; i++)
		day = next_day (day);
	show (day);
	for (int i = 0; i < 30; i++)
		day = previous_day (day);
	show (day);
	if (equal (today, day))
		printf ("Very Good!\n");
	else
		printf ("Very Bad!\n");
	return 0;
}
