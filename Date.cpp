#include <iostream>
using namespace std;

class Date {
public:
  Date(int y, int m, int d);
  ~Date();

  void nextDay();
  void previousDay();
  bool equal(Date other);
  void show();
private:
  int year;
  int month;
  int day;
};

Date::Date(int y, int m, int d):year(y),month(m),day(d){}

Date::~Date(){}

void Date::nextDay(){
	int d;
	int Feb = 28;
	if((year%400 == 0)||((year%100 != 0)&&year%4 == 0)){
	Feb = 29;
  }
  switch(month){
		case 1: case 3: case 5:
    case 7: case 8: case 10:
    case 12:
    d = 31; break;
    
    case 4: case 6: case 9: case 11:
    d = 30; break;
    case 2: d = Feb;
  }
  if ((day = day + 1) >d){
	 	month += 1;
		day = 1;
	}
	if (month == 13){
		year += 1;
		month = 1;
	}
  return;
}

void Date::previousDay(){
	int Feb = 28;
	if((year%400 == 0)||((year%100 != 0)&&year%4 == 0)){
  	Feb = 29;
	}
	if ((day = day - 1) == 0)
	{
  	month -= 1;
  	if (month == 0){
   	month = 12;
  	year -= 1;
	} 
	  switch(month){
		  case 1: case 3: case 5:
		  case 7: case 8: case 10:
		  case 12:
 		  day = 31; break;

  	  case 4: case 6: case 9: case 11:
		  day = 30; break;
		  case 2: day = Feb;
    }
  } 
  return;
}

bool Date::equal(Date other){
  if((this->day == other.day)&&(this->month == other.month)&&(this->year == other.year)){
    return true;
  }
  else return false;
}

void Date::show(){
  cout<<"The date is "<<year<<"."<<month<<"."<<day<<endl;
}
int main() {
  Date today(2018,3,20);
  Date day(2018,3,20);
  day.show();
  for(int i=0;i<30;i++)
    day.nextDay();
  day.show();
  for(i=0;i<30;i++)
    day.previousDay();
  day.show();
  if(day.equal(today))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
  return 0;
}
