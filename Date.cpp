#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

//manacher-start
const int NMAX=110010;
char str_raw[NMAX];
char str[NMAX<<1];
int p[NMAX<<1];
int len,mid,ans;

int init()
{
	mid=1;
	ans=0;
	memset(p,0,sizeof(p));
	memset(str,0,sizeof(str));
	return 0;
}

int manacher()
{
	while(~scanf("%s",str_raw+1))
	{
		init();
		len=strlen(str_raw+1);
		for(int i=1;i<=len;i++)
		{
			str[i*2]=str_raw[i];
			str[i*2+1]='#';
		}
		str[0]='@';
		str[1]='#';
		str[len*2+2]='\0';
		p[0]=1;
		for(int i=1;i<=2*len+1;i++)
		{
			if(i>mid+p[mid]-1)
				p[i]=1;
			else
				p[i]=min(p[2*mid-i],mid+p[mid]-i);
			while(str[i+p[i]]==str[i-p[i]])
				p[i]+=1;
			if(i+p[i]-1>mid+p[mid]-1)
				mid=i;
			ans=max(ans,p[i]-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
//manacher-end

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
