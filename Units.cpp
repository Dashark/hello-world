//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......
//还有很多单位转换，有些单位是其它单位组合出来的
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<cstdlib>
using namespace std;


class weight
{
public:
	weight(void){
	};
	~weight(void){
	};
	void input();
	void jisuan();
	void show();
	
	
private:
	string yuan;
	string xin;
	double shu;
	
} ;


void weight::input()
{
	cout<<"可以进行以下4种单位之间的转换："<<endl;
	cout<<"t   kg   g   mg"; 
	cout<<"请选择原单位:";
	cin>>yuan;
	cout<<endl;
	cout<<"请输入数值:";
	cout<<endl ;
	cin>>shu;
	cout<<endl;
	cout<<"请选择新单位:"; 
	cin>>xin; 	
}

void weight::show()
{
	if(yuan=="t"&&xin=="t")
	{
		cout<<shu<<"t="<<shu<<"t"<<endl;
	}
	else if(yuan=="t"&&xin=="kg")
	{
		cout<<shu<<"t="<<1000*shu<<"kg"<<endl;
	}
	else if(yuan=="t"&&xin=="g")
	{
		cout<<shu<<"t="<<1000000*shu<<"g"<<endl;
	}
	else if(yuan=="t"&&xin=="mg")
	{
		cout<<shu<<"t="<<1000000000*shu<<"mg"<<endl;
	}
	else if(yuan=="kg"&&xin=="t")
	{
		cout<<shu<<"kg="<<0.001*shu<<"t"<<endl;
	}
	else if(yuan=="kg"&&xin=="kg")
	{
		cout<<shu<<"kg="<<shu<<"kg"<<endl;
	}
	else if(yuan=="kg"&&xin=="g")
	{
		cout<<shu<<"kg="<<1000*shu<<"g"<<endl;
	}
	else if(yuan=="kg"&&xin=="mg")
	{
		cout<<shu<<"kg="<<1000000*shu<<"mg"<<endl;
	}
	else if(yuan=="g"&&xin=="t")
	{
		cout<<shu<<"g="<<0.000001*shu<<"t"<<endl;
	}
	else if(yuan=="g"&&xin=="kg")
	{
		cout<<shu<<"g="<<0.001*shu<<"kg"<<endl;
	}
	else if(yuan=="g"&&xin=="g")
	{
		cout<<shu<<"g="<<1*shu<<"g"<<endl;
	}
	else if(yuan=="g"&&xin=="mg")
	{
		cout<<shu<<"g="<<1000*shu<<"mg"<<endl;
	}
	else if(yuan=="mg"&&xin=="t")
	{
		cout<<shu<<"mg="<<0.000000001*shu<<"t"<<endl;
	}
	else if(yuan=="mg"&&xin=="kg")
	{
		cout<<shu<<"mg="<<0.000001*shu<<"kg"<<endl;
	}
	else if(yuan=="mg"&&xin=="g")
	{
		cout<<shu<<"mg="<<0.001*shu<<"g"<<endl;
	}
	else if(yuan=="mg"&&xin=="g")
	{
		cout<<shu<<"mg="<<1*shu<<"mg"<<endl;
	}
}

int main()
{
	system("color 27");
	char flag='Y';
	while(toupper(flag)=='Y')
	{
		cout<<"请选择您要换算的单位种类："<<endl;
		cout<<"1:重量单位  2：压力单位  3：长度单位  4 "<<endl;
		
		int n;
		cin>>n;
		
		switch(n)
		{
			case 1:
				{
					weight unit;
					unit.input();
					unit.show();
					break;	
				}
			
			case 2:
				{
					
				}
		 } 
		 
		 cout<<endl<<"是否继续使用转换器？（Y/N）";
		 cin>>flag;
	}
	
return 0;	

}
