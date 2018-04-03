#include<iostream>
#include<stdio.h>
#include<time.h>
using namespace std;
class Clock {
  private:
  int hour;
  int minute;
  int second;
  public:
  void tick(){
  	time_t t=time(NULL);
  	struct tm *l=localtime(&t);
  	hour=l->tm_hour;
  	minute=l->tm_min;
  	second=l->tm_sec;
  }
  void show(){
  printf("%02d%02d%02d\n",hour,minute,second);
  }
  void adjust(int a ,int b,int c){
  hour=a;
  minute=b;
  second=c;
  }
};

int main() {
  Clock ck;
  
  ck.tick();
  ck.show();
  ck.adjust(16,45,00);
  ck.show();
  return 0;
}
