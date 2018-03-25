#include<cstdio>
class Date {
	public:
		Date(int y, int m, int d)
		{
			year=y;
			month=m;
			day=d;
		}
		
		~Date(){}

		void nextDay()
		{
			int day_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
			if(year%4==0)
			{
				if(year%100!=0)
					day_month[2]=29;
				else
					if(year%400==0)
						day_month[2]=29;
			}
			day += 1;
			if(day>day_month[month])
				day=1,month+=1;
			if(month>12)
				month=1,year+=1;
			return;
		}
		void previousDay()
		{
			int day_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
			if(year%4==0)
			{
				if(year%100!=0)
					day_month[2]=29;
				else
					if(year%400==0)
						day_month[2]=29;
			}
			day -= 1;
			if(day<=0)
			{
				month-=1;
				if(month<=0)
					year-=1,month=12;
				day=day_month[month];
			}
			return;
		}
		bool equal(Date other)
		{
			if(other.year==year && other.month==month && other.day==day)
				return true;
			return false;
		}
		void show()
		{
			printf("%04d/%02d/%02d\n",year,month,day);
		}
	private:
		int year;
		int month;
		int day;
};

int main() {
	Date today(2018,3,20);
	Date day(2018,3,20);
	day.show();
	for(int i=0;i<30;i++)
		day.nextDay();
	day.show();
	for(int i=0;i<30;i++)
		day.previousDay();
	day.show();
	if(day.equal(today))
		printf("Very Good!\n");
	else
		printf("Very Bad!\n");
	return 0;
}
