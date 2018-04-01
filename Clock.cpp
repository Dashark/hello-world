//程序仍然有问题
#include<iostream> 
using namespace std;

class Clock 
{
	public:
		Clock()
		{
			hour=0;
			minute=0;
			second=0;
		}
//		~Clock();
		
		void adjust(int h,int m,int s);
		void show();
		void tick();
	private:
		int second,minute,hour;
};

void Clock::adjust(int h,int m,int s)
{
	if(h>=0&&h<24&&m>=0&&m<60&&s>=0&&s<60)
	{
		second=s;
    	minute=m;
    	hour=h;
	}
	else
	cout<<"???????24???"<<endl; 
}

void Clock::show()
{
	if(hour<10) cout<<'0'<<hour;
	else cout<<hour;
	cout<<':';
	if(minute<10) cout<<'0'<<minute;
	else cout<<minute;
	cout<<':';
	if(second<10) cout<<'0'<<second;
	else cout<<second;
	cout<<endl;
}

void Clock::tick()
{
	//86400=24h
	int i,j=0;
	while(j<200)
	{
		second++;
		if(second==60)
		{ 
		    second=0;
			minute++;
		}
		if(minute==60) 
		{
		    minute=0;
		    hour++;
	    } 
	    if(hour==24)
	    hour=0;
	    for(i=0;i<=900000000;i++){};
	    show();
	    j++;
	}
}

int main()
{
    Clock ck;
    ck.tick();
    ck.show();
    ck.adjust(16,45,00);
    ck.show();
    return 0;
}
