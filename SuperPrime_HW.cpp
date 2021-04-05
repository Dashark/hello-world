#include<iostream>
using namespace std;
int shup(int a)
{
	
	int i,judge=1;
	for(i=2;i<a;i++)
	{
		if(a%i==0)
		judge=0;
	}
	return judge;
}
int main()
{
	int w1,w2,w3,judge1,judge2,judge3,judge4,count=0,a[900];
	for(int i=100;i<=999;i++)
	{
		judge1=0;judge2=0;judge3=0;judge4=0;
		if(shup(i))
		judge1=1;
		w1=i%10;
		w2=(i%100)/10;
		w3=i/100;
		if(shup(w1+w2+w3))
		judge2=1;
		if(shup(w1*w2*w3))
		judge3=1;
		if(shup(w1*w1+w2*w2+w3*w3))
		judge4=1;
		if(judge1&&judge2&&judge3&&judge4)
		{
		a[count]=i;
		count++;
	    }
	}
	int total=0;
	for(int j=0;j<count;j++)
	{
		total+=a[j];
	}
	cout<<"个数："<<count<<endl;
	cout<<"和:"<<total<<endl;
	cout<<"最大："<<a[count-1];
}
