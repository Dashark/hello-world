//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......
//还有很多单位转换，有些单位是其它单位组合出来的
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
	string c1="t";
	string c2="kg";
	string c3="g";
	string c4="mg";
	cout<<"可以进行以下4种单位之间的转换："<<endl;
	cout<<"t   kg   g   mg"; 
	cout<<"请选择原单位:";
	cin>>yuan;
	while(yuan!=c1&&yuan!=c2&&yuan!=c3&&yuan!=c4)
	{
		cout<<"输入的原单位有误，请重新输入：";
		cin>>yuan; 
	}
	cout<<endl;
	cout<<"请输入数值:";
	cout<<endl ;
	cin>>shu;
	cout<<endl;
	cout<<"请选择新单位:"; 
	cin>>xin;
	while(xin!=c1&&xin!=c2&&xin!=c3&&xin!=c4)
	{
		cout<<"输入的新单位有误，请重新输入：";
		cin>>xin;
	} 	 	
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

class yali 
{
public:
	yali(void){
	};
	~yali(void){
	};
	void input();
	void jisuan();
	void show();
	
	
private:
	string yuan;
	string xin;
	double shu;
	
} ;

class chang 
{
public:
	chang(void){
	};
	~chang(void){
	};
	void input();
	void jisuan();
	void show();
	
	
private:
	string yuan;
	string xin;
	double shu;
	
} ;

void chang::input()
{
	cout<<"可以进行以下4种单位之间的转换："<<endl;
	cout<<"m  km  ft(英尺)  in(英寸)"; 
	cout<<"请选择原单位:";
	string c1="m";
	string c2="km";
	string c3="ft";
	string c4="in";
	
	cin>>yuan;
	while(yuan!=c1&&yuan!=c2&&yuan!=c3&&yuan!=c4)
	{
		cout<<"输入的原单位有误，请重新输入：";
		cin>>yuan; 
	}
	
	cout<<endl;
	cout<<"请输入数值:";
	cout<<endl ;
	cin>>shu;
	cout<<endl;
	cout<<"请选择新单位:"; 
	cin>>xin;
	while(xin!=c1&&xin!=c2&&xin!=c3&&xin!=c4)
	{
		cout<<"输入的新单位有误，请重新输入：";
		cin>>xin;
	} 	
}
void chang::show()
{
	
	
	if(yuan=="m"&&xin=="km")
	{
		cout<<shu<<"m="<<shu/1000<<"km"<<endl;
	}
	else if(yuan=="m"&&xin=="m")
	{
		cout<<shu<<"m="<<shu<<"m"<<endl;
	}
	else if(yuan=="m"&&xin=="in")
	{
		cout<<shu<<"m="<<shu*100/2.54<<"in"<<endl;
	}
	else if(yuan=="m"&&xin=="ft")
	{
		cout<<shu<<"m="<<shu*100/2.54/12<<"ft"<<endl;
	}
	else if(yuan=="km"&&xin=="km")
	{
		cout<<shu<<"mk="<<shu<<"km"<<endl;
	}
	else if(yuan=="km"&&xin=="m")
	{
		cout<<shu<<"km="<<shu*1000<<"m"<<endl;
	}
	else if(yuan=="km"&&xin=="ft")
	{
		cout<<shu<<"mk="<<shu*1000*100/12/2.54<<"ft"<<endl;
	}
	else if(yuan=="km"&&xin=="ft")
	{
		cout<<shu<<"mk="<<shu*1000*100/2.54<<"in"<<endl;
	}
	else if(yuan=="ft"&&xin=="km")
	{
		cout<<shu<<"ft="<<shu*12*2.54/100/1000<<"km"<<endl;
	}
	else if(yuan=="ft"&&xin=="m")
	{
		cout<<shu<<"ft="<<shu*12*2.54/100<<"m"<<endl;
	}
	else if(yuan=="ft"&&xin=="ft")
	{
		cout<<shu<<"ft="<<shu<<"ft"<<endl;
	}
	else if(yuan=="ft"&&xin=="in")
	{
		cout<<shu<<"ft="<<shu*12<<"in"<<endl;
	}
	else if(yuan=="in"&&xin=="km")
	{
		cout<<shu<<"in="<<shu*2.54/100/1000<<"km"<<endl;
	}
	else if(yuan=="in"&&xin=="m")
	{
		cout<<shu<<"in="<<shu*2.54/100<<"m"<<endl;
	}
	else if(yuan=="in"&&xin=="ft")
	{
		cout<<shu<<"in="<<shu/12<<"ft"<<endl;
	}
	else if(yuan=="in"&&xin=="in")
	{
		cout<<shu<<"in="<<shu<<"in"<<endl;
	}

 } 


void yali::input()
{
	string c1="psi";
	string c2="kpa";
	string c3="pa";
	
	cout<<"可以进行以下3种单位之间的转换："<<endl;
	cout<<"psi(磅力)  kpa  pa"; 
	cout<<"请选择原单位:";
	cin>>yuan;
	while(yuan!=c1&&yuan!=c2&&yuan!=c3)
	{
		cout<<"输入的原单位有误，请重新输入：";
		cin>>yuan; 
	}
	cout<<endl;
	cout<<"请输入数值:";
	cout<<endl ;
	cin>>shu;
	cout<<endl;
	cout<<"请选择新单位:"; 
	cin>>xin; 
	while(xin!=c1&&xin!=c2&&xin!=c3)
	{
		cout<<"输入的新单位有误，请重新输入：";
		cin>>xin;
	} 		
}

void yali::show()
{
	if(yuan=="psi"&&xin=="psi")
	{
		cout<<shu<<"psi="<<shu<<"psi"<<endl;
	}
	else if(yuan=="psi"&&xin=="kpa")
	{
		cout<<shu<<"psi="<<6.85*shu<<"kpa"<<endl;
	}
	else if(yuan=="psi"&&xin=="pa")
	{
		cout<<shu<<"psi="<<1000*6.85*shu<<"pa"<<endl;
	}
	else if(yuan=="kpa"&&xin=="psi")
	{
		cout<<shu<<"kpa="<<shu/6.85<<"psi"<<endl;
	}
	else if(yuan=="kpa"&&xin=="kpa")
	{
		cout<<shu<<"kpa="<<shu<<"kpa"<<endl;
	}
	else if(yuan=="kpa"&&xin=="pa")
	{
		cout<<shu<<"kpa="<<1000*shu<<"kpa"<<endl;
	}
	else if(yuan=="pa"&&xin=="psi")
	{
		cout<<shu<<"pa="<<shu/6.85/1000<<"psi"<<endl;
	}
	else if(yuan=="pa"&&xin=="kpa")
	{
		cout<<shu<<"pa="<<shu/1000<<"kpa"<<endl;
	}
	else if(yuan=="pa"&&xin=="kpa")
	{
		cout<<shu<<"pa="<<shu<<"pa"<<endl;
	}
}



int main()
{
	system("color 27");
	char flag='Y';
	while(toupper(flag)=='Y')
	{
		system("cls");
		cout<<"\t\t\t\t\t########################################"<<endl; 
		cout<<"\t\t\t\t\t##请选择您要换算的单位种类：          ##"<<endl;
		cout<<"\t\t\t\t\t##1:重量单位              2：压力单位 ##"<<endl;
		cout<<"\t\t\t\t\t##3:长度单位              4:          ##"<<endl;
		cout<<"\t\t\t\t\t########################################"<<endl; 
		
		int n;
		cin>>n;
		
		switch(n)
		{
			
			case 1:
				{
					system("cls");
					weight unit;
					unit.input();
					unit.show();
					break;	
				}
			
			case 2:
				{
					system("cls");
					yali unit;
					unit.input();
					unit.show();
					break;	
				}
				
			case 3:
				{
					system("cls");
					chang unit;
					unit.input();
					unit.show();
					break;	
				}
		 } 
		 
		 cout<<endl<<"是否继续使用单位转换器？（Y/N）";
		 cin>>flag;
		 cout<<endl<<endl;
		 
		 if(toupper(flag)=='N')
		 {
		 	system("cls");
			cout<<"\t\t感谢使用，再见！！！";
			cout << "\t\t\t                                " << endl;
			cout<<"\t\t虽然这个程序功能不多，"<<endl
			<<"\t\t而且为了凑代码行数所以用的算法很垃圾，但！是！："<<endl
				<< "\t\t版权所有@SCU计算机学院 " << endl
				<< "\t\t\t                              " << endl
				<< "\t\t如有技术问题请发电邮至：448407561@qq.com" << endl; 
			return 0;
		 }
	}

	
	
	

}
