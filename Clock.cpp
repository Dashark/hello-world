#include <iostream>
#include <windows.h>
using namespace std;
class Clock{
	public:
		Clock(short h=0,short m =0,short s=0):h(h),m(m),s(s)
		{
			
		}
		void displayTime();
		void set_time();
		private:
			short h;
			short m;
			short s;
};
void Clock::set_time()
{
	cin>>h;
	cin>>m;
	cin>>s;
}
void Clock::displayTime()
{
	while(true)
	{
			cout<<"时间："<<h<<':'<<m<<':'<<s<<" ";
			Sleep(1000);
			cout<<'\r';
			if(!(s=++s%60))
				if(!(m=++m%60))
				h=++h%24;
	}
}
int main()
{
	Clock clock;
	clock.set_time();
	
	clock.displayTime();
	return 0;
}
