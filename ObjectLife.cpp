#include<iostream> 
#include<cctype>
using namespace std;
class date{
	public:
		void setdate(int y,int m,int d){
			year=y;
			month=m;
			day=d;
		}
		int isleapyear(){
			if((year%4==0&&year%100!=0)||(year%400==0)){
				return 1;
			}}
		void print(){
			cout <<year<<"年"<<month<<"月"<<day<<"日";
		}
	private:
		int year;
		int month;
		int day;
}; 

int main(void){
	date d1;
	d1.setdate(2012,11,11);
	d1.print();
	cout<<"这一年是闰年吗"<<d1.isleapyear()<<endl;
	return 0; 
}
