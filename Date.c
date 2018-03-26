#include<stdio.h>
struct Date {
  int year;
  int month;
  int day;
};
void show(struct Date day) {
  printf("%dÄê%dÔÂ%dÈÕ",day.year,day.month,day.day);
}
void next_day(struct Date day) {
	if (day.month == 1 || day.month == 3 || day.month == 5 || day.month == 7 || day.month == 8 || day.month == 10) {
		if (day.day < 31)day.day++;
		else {
			day.day = 1; day.month++;
		}
	}
	else if (day.month == 4 || day.month == 6 || day.month == 9 || day.month == 11) {
		if (day.day < 30)day.day++;
		else {
			day.day = 1; day.month++;
		}
	}
	else if (day.month == 12) {
		if (day.day < 31)day.day++;
		else {
			day.year++;
			day.day = day.month = 1;
		}
	}
	else if (day.month == 2) {
		if (((day.year % 4 == 0) && (day.year % 100 != 0)) || (day.year % 400 == 0)) {
			if (day.day < 29)day.day++;
			else {
				day.day = 1;
				day.month++;
			}
		}
		else {
			if (day.day < 28)day.day++;
			else {
				day.day = 1;
				day.month++;
			}
		}
	}
}
int equal(struct Date one, struct Date day) {
	if (day.day == one.day&&day.year ==one.year&&day.month ==one.month)
		return 1;
	else return 0;
}
void previous_day(struct Date day) {
	if (day.month == 2 || day.month == 4 || day.month == 6 || day.month == 8 || day.month == 9 || day.month == 11) {
		if (day.day >1)day.day--;
		else {
			day.day = 31; day.month--;
		}
	}
	else if (day.month == 5 || day.month == 7 || day.month == 10 || day.month == 12) {
		if (day.day >1)day.day--;
		else {
			day.day = 30; day.month--;
		}
	}
	else if (day.month == 1) {
		if (day.day>1)day.day--;
		else {
			day.year--;
			day.day = 31; day.month = 12;
		}
	}
	else if (day.month == 3) {
		if (((day.year % 4 == 0) && (day.year % 100 != 0)) || (day.year % 400 == 0)) {
			if (day.day >1)day.day--;
			else {
				day.day = 29;
				day.month--;
			}
		}
		else {
			if (day.day >1)day.day--;
			else {
				day.day = 28;
				day.month--;
			}
		}
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
  if(equal(today, day))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
  return 0;
}
