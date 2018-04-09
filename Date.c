#include <stdio.h>

struct Date {
  int year;
  int month;
  int day;
};

void next_day(struct Date day);
void previous_day(struct Date day);
int equal(struct Date one, struct Date day);
void show(struct Date day) {
  printf("%d-%d-%d\n", day.year, day.month, day.day);
}
int isleapyear(struct Date day);

int main() {
  struct Date today = {2018, 3, 20};
  struct Date day = {2018, 3, 21};
  show(day);
  
  next_day(day);  
  previous_day(day);
  
  if(equal(today, day))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
    
  return 0;
}

int equal(struct Date one, struct Date day) {
	if (one.day == day.day && one.month == day.month && one.year == day.year) {
		return 1;
	}
	else {
		return 0;
	} 
}

int isleapyear(struct Date day) {
	if(day.year % 4 != 0) {
		return 0;
	}
	else if(day.year % 100 != 0) {
		return 1;
	}
	else if(day.year % 400 != 0) {
		return 0;
	}
	else {
		return 1;
	}
}

void next_day(struct Date day) {
	if(day.day >= 1 && day.day <= 27) {
		day.day++;
	}
	else if(day.month == 1 || day.month == 3 || day.month == 5 ||
			 day.month == 7 || day.month == 8 || day.month == 10) {
		if(day.day <= 30) {
			day.day++;
		}
		else if(day.day == 31) {
			day.month++;
			day.day = 1;
		}
	}
	else if(day.month == 4 || day.month == 6 || day.month == 9 || day.month == 11) {
		if(day.day <= 29) {
			day.day++;
		}
		else if(day.day == 30) {
			day.month++;
			day.day = 1;
		}
	}
	else if(day.month == 2) {
		if (isleapyear(day)) {
			if(day.day <= 28) {
				day.day++;
			}
			else if(day.day == 29) {
				day.month++;
				day.day = 1;
			}
		}
		else {
			if(day.day <= 27) {
				day.day++;
			}
			else if(day.day == 28) {
				day.month++;
				day.day = 1;
			}
		}
	}
	else if(day.month == 12) {
		if(day.day <= 30) {
			day.day++;
		}
		if(day.day == 31) {
			day.day = 1;
			day.month = 1;
			day.year++;
		}
	}
	show(day);
}

void previous_day(struct Date day) {
	if(day.day != 1) {
		day.day--;
	}
	else if(day.month == 5 || day.month == 7 || day.month == 8 || day.month == 10 || day.month == 12) {
			day.day = 30;
			day.month--;
		}
	
	else if(day.month == 2 || day.month == 4 || day.month == 6 || day.month == 9 || day.month == 11) {
		day.day = 31;
		day.month--;
	}
	
	else if(day.month == 1) {
		day.day = 31;
		day.month = 12;
		day.year--;
	}
	
	else if(day.month == 3) {
		day.month--;
		if (isleapyear(day)) {
			day.day = 29;
		}
		else {
			day.day = 28;
		}
	}
	show(day);
}
