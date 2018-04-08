//程序仍有问题
#include<iostream>
using namespace std;
class Clock {
	public:
	void tick();
    void show();
    int adjust(int s,int m,int h);
    
    private:
    	int sec;
    	int min;
    	int hour;
};

void Clock::tick(){
	
	
	for(int i=0;i<=1000000;i++)
	{
		sec++;
		if(sec==60){
		sec=0;
		min++;
		}
	if(min==60){
		min=0;
		hour++;
		}
	if(hour==24){
		hour=0;
		
		}
		show();
	}
}

void Clock::show(){
	if(hour<=9){cout<<"0"<<hour<<":";
	}
	else cout<<hour<<":";
	if(min<=9){
		cout<<"0"<<min<<":";
	}
	else cout<<min<<":";
	if(sec<=9){
		cout<<"0"<<sec;
	}
	else cout<<sec<<endl;
}

int Clock::adjust(int s,int m,int h)
{
	if(0<=s&&s<=60&&m>=0&&m<=60&&h>=0&&h<=24){
		sec=s;
		min=m;
		hour=h;
	}
	else cout<<"ÇëÊäÈë·ûºÏÕýÈ·Ê±¼ä¸ñÊ½µÄÊ±¼äµã"<<endl; 
}


int main() {
  Clock ck;
  ck.tick();
  ck.show();
  ck.adjust(16,45,00);
  ck.show();
  return 0;
}
