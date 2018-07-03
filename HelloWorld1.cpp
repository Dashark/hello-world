#include<iostream> 

#include<cctype>

using namespace std;

class date{

	public:

		date(){                  //此处为构造函数。 

			year=2000;

			month=1;

			day=1;

		} 

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



	d1.print();

	

	return 0; 

}
