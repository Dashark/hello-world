#include<iostream>
using namespace std;
int months[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
int isleapyear(int year) {
	if(year%400==0||(year%4==0&&year%100!=0))
		return 366;
	else
		return 365;
}
void rili(int d) {
	int a=2000;
	while(d>=0) {
		d-=isleapyear(a);
		a++;
	}
	d+=isleapyear(a-1);
	cout<<a-1<<'-';
	if(isleapyear(a-1)==366)
		months[1]=29;
	else months[1]=28;
	int n=0;
	while(d>months[n]) {
		d-=months[n];
		n++;
	}
	if(n<9)
		cout<<'0';
	cout<<n+1<<'-';
	if(d<10)
		cout<<'0';
	cout<<d+1<<' ';
}
int main() {
	int d;
	while(cin>>d&&d!=-1) {
		rili(d);
		switch(d%7) {
			case 0:
				cout<<"Saturday"<<endl;
				break;
			case 1:
				cout<<"Sunday"<<endl;
				break;
			case 2:
				cout<<"Monday"<<endl;
				break;
			case 3:
				cout<<"Tuesday"<<endl;
				break;
			case 4:
				cout<<"Wednesday"<<endl;
				break;
			case 5:
				cout<<"Thursday"<<endl;
				break;
			case 6:
				cout<<"Friday"<<endl;
				break;
		}
	}
	return 0;
}
