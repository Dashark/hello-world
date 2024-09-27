#include<stdio.h>
#include<iostream>
#include<stdbool.h>
using namespace std;
class judge{
	public:
		bool sushu(int n,bool light)
		{
		    light=0;
			int b=0;
			for(int a=2;a<n;a++)
			{if(n%a==0){b++;}}
			if(b==0){light=1;} 
			return light;
		}
		bool super(int c,bool light)
		{
		   light=1;
		   int ge,shi,bai,he,ji,ping,a,b=0;
		   ge=c%10;shi=((c-ge)%100)/10;bai=(c-ge-shi*10)/100;
		   he=ge+shi+bai;ji=ge*shi*bai;ping=ge*ge+shi*shi+bai*bai; 
		   if(ge!=0&&shi!=0&&bai!=0) 
		   {for(int a=2;a<he;a++){if(he%a==0){b++;}}if(b!=0) {light=0;}
		   if(light==1){for(int a=2;a<ji;a++){if(ji%a==0){b++;}}
		   if(b!=0) {light=0;}}
		   if(light==1){for(int a=2;a<ping;a++){if(ping%a==0){b++;}}
		   if(b!=0) {light=0;}}}
		   else light=0;
		   return light;
		}		
};
int main()
{
	int n,sushu[255]={},super[255]={},num=0,a2=0;
	judge M;bool light;
	for(n=100;n<=999;n++)
	{light=M.sushu(n,light);
	if(light==1){sushu[num]=n;num++;}
	}
	num=0;
	for(n=100;n<=999;n++)
	{light=M.super(n,light);
	if(light==1){super[num]=n;printf("%d %d\n",super[num],num);num++;}
	}
	cout<<"个数="<<num<<endl;
	num--;
	for(n=0;n<=num;n++)
	{a2=a2+super[n];}
	cout<<"和="<<a2<<endl;
	cout<<"最大="<<super[num]<<endl;
	return 0;
} 

