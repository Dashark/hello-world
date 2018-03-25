#include<ctime>
#include<cstdio>
class Clock {
	public:
		Clock(){}
		~Clock(){}
		
		void tick()
		{
			time_t t=time(0);
			tm* tt=localtime(&t);
			hour=tt->tm_hour;
			minute=tt->tm_min;
			second=tt->tm_sec;
		}
		
		void show()
		{
			printf("%02d:%02d:%02d\n",hour,minute,second);
			return;
		}
		
		void adjust(int h,int m,int s)
		{
			hour=h,minute=m,second=s;
			return;
		}
	private:
		int hour,minute,second;
};

int main() {
  Clock ck;
  ck.tick();
  ck.show();
  ck.adjust(16,45,00);
  ck.show();
  return 0;
}
