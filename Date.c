#include<stdio.h>
struct Date {
    int year;
    int month;
    int day;
};
void next_day(struct Date* day);
void previous_day(struct Date* day);
int equal(struct Date one, struct Date day);
void show(struct Date day) {
    printf("The day is %d.%d.%d\n",day.year,day.month,day.day);
      return;
}

int main() {
    int i;
    struct Date today = {2018,3,20};
    struct Date day = {2018,3,20};
    show(day);
    for(i=0;i<30;i++)
        next_day(&day);
      show(day);
      for(i=0;i<30;i++)
        previous_day(&day);
      show(day);
      if(equal(today, day))
        printf("Very Good!\n");
      else
        printf("Very Bad!\n");
      return 0;
}

void next_day(struct Date* day){
      int d;
      int Feb = 28;
      if((day->year%400 == 0)||((day->year%100 != 0)&&day->year%4 == 0)){
        Feb = 29;
      }
      switch(day->month){
        case 1: case 3: case 5:
        case 7: case 8: case 10:
        case 12:
        d = 31; break;
    
        case 4: case 6: case 9: case 11:
        d = 30; break;
        case 2: d = Feb;
      }
      if ((day->day = day->day + 1) >d){
           day->month += 1;
        day->day = 1;
    }
    if (day->month == 13){
        day->year += 1;
        day->month = 1;
    }
    return;
}

void previous_day(struct Date* day){
      int Feb = 28;
      if((day->year%400 == 0)||((day->year%100 != 0)&&day->year%4 == 0)){
        Feb = 29;
      }
      if ((day->day = day->day - 1) == 0)
      {
        day->month -= 1;
        if (day->month == 0){
        day->month = 12;
        day->year -= 1;
          }
        switch(day->month){
            case 1: case 3: case 5:
            case 7: case 8: case 10:
            case 12:
            day->day = 31; break;
    
            case 4: case 6: case 9: case 11:
            day->day = 30; break;
            case 2: day->day = Feb;
          }
    }
      return;
}

int equal(struct Date a,struct Date b){
      if ((a.day == b.day)&&(a.year == b.year)&&(a.month == b.month)){
        return 1;
    }
      else return 0;
}