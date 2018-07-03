#include<iostream>
using namespace std;

class Clock {
  public:
	clock(){
		hour=0;
		minu=0;
		s=0;
	}
	void adjust(int,int ,int);
	void tick();
	void show();
 private:
 	int hour,minu,s;
 	
};
void Clock::adjust(int x,int y,int z){
	hour=x;
	minu=y;
	s=z;
	
}
void Clock::tick(){
	cout<<"I don't know what is this"<<endl;
	
}
void Clock::show(){
	cout<<hour<<"Ð¡Ê±"<<minu<<"·ÖÖÓ"<<s<<"Ãë"<<endl;
	
}



int main() {

  Clock ck;

  ck.tick();

  ck.show();

  ck.adjust(16,45,00);

  ck.show();

  return 0;

}
