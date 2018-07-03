#include<stdio.h>
#include<math.h>
struct Date {
  int year;
  int month;
  int day;
};

void next_day(struct Date day){
	
	if(day.month==12){
		if(day.day!=31){
			day.day++;
		}
		else{
			day.day=1;
			day.month=1;
			day.year++;
		}
	}
  else	if(day.month==1||day.month==3||day.month==5||day.month==7||day.month==8||day.month==10){
		if(day.day!=31){
			day.day++;
		}
		else{
			day.day=1;
		    day.month++;
		}
	}
	else if(day.month==4||day.month==6||day.month==9||day.month==11){
		if(day.day!=30){
			day.day++;
		}
		else{
			day.day=1;
		    day.month++;
		}
	}
	else if(day.month==2){
		if((day.year%4==0&&day.year%100!=0)||day.year%400==0){
	    	if(day.day!=29){
			day.day++;
	        	}
	      	else{
			day.day=1;
		    day.month++;
		}
		}
		else{
		  if(day.day!=28){
			day.day++;
	        	}
	      	else{
			day.day=1;
		    day.month++;
		}
			
		}
	}
}

void previous_day(struct Date day){
	if(day.month==1){
		if(day.day!=1){
			day.day--;
		}
		else{
			day.day=31;
			day.month=12;
			day.year--;
		}
	}
	else if(day.month==12||day.month==5||day.month==7||day.month==8||day.month==10){
		if(day.day!=1){
			day.day--;
		}
		else{
			day.day=30;
		    day.month--;
		}
	}
	else if(day.month==4||day.month==6||day.month==9||day.month==11||day.month==2){
		if(day.day!=1){
			day.day--;
		}
		else{
			day.day=31;
		    day.month--;
		}
	}
   else 	if(day.month==3){
		if((day.year%4==0&&day.year%100!=0)||day.year%400==0){
	    	if(day.day!=1){
			day.day--;
	        	}
	      	else{
			day.day=29;
		    day.month--;
		}
		}
		else{
		  if(day.day!=1){
			day.day--;
	        	}
	      	else{
			day.day=28;
		    day.month--;
		}
			
		}
	}
	
}

int equal(struct Date one, struct Date day){
	if(one.year==day.year&&one.day==day.day&&one.month==day.month) {
		return 1;
	}
	else {
		return 0;
	}
}

void show(struct Date day) {

  printf("%d Äê %d ÔÂ %d ÈÕ\n",day.year,day.month,day.day);

}

int main() {

  struct Date today = {2018,3,20};

  struct Date day = {2018,3,20};
  show(day);
  for(int i=0;i<30;i++)
    {next_day(day);}

  show(day);

  for(int i=0;i<30;i++)
    {
	previous_day(day);}

  show(day) ;

  if(equal(today, day))

    printf("Very Good!\n");

  else

    printf("Very Bad!\n");

  return 0;

}
