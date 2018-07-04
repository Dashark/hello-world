/*单位转换器大作业： 
组员：刘坤（github名称：ExecutantLK），黄涛（GitHub：ArokHT），陈杰(Github:gitvide)
组员工作量：刘坤：完成面积单位，电流单位，体积单位三个类的设计，并书写了主函数；
黄涛：完成了时间，长度，重量，压力，
陈杰：整合整个代码，并设计了基类函数，实现继承，设计表示温度的单位转换类。
//////////////////////////////////////////////////////////////// 
思路：由于作业规定输入三个量，原数值，原单位，要转换成的单位，那么我们认为设计类的话，就会有三个数据成员，
而成员函数，我们以最基本的思路来看，就只需要一个find函数（用来匹配该单位是哪一类单位），translate函数
（用来转换数值，变成现单位的值），然后再用一个show（）函数把这个值给show出来。而这三个数，如果要设计的话，
在每一个类中都会有，那么我们设计一个基类，其中的三个成员函数全部弄成纯虚函数，由继承出来的类来实现，而数据
成员我们将它弄成protect，从而公有继承后，该数据成员仍然是子类的私有成员，可以通过成员函数来调用，从而实现
功能
//////////////////////////////////////////////////////////////// 
以下是实现的单位转换：
1.长度单位：km, m, dm, cm, mm 
2.重量单位：t, kg, g, mg 
3.时间单位：day, h, min, s, ms 
4.面积单位：mm2,cm2,dm2,m2,ha,km2（mm2等中，2代表的是平方） 
5.电流单位：pa,na,ua,ma,a,ka 
6.压强单位：mpa, kpa, psi, Pa(为不与电流pa冲突，故大写) 
7.温度单位：开尔文温度K，华氏温度 F，摄氏温度C 
8.体积单位： mm3,cm3,dm3,m3,ml,l（分别为立方毫米，立方厘米。。。。。毫升，升） */
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<string.h> 
#include<iomanip>

int which; //全局变量，用来控制调用
using namespace std;
class units
{
public:
	virtual int find(string s1,string s2) = 0;
	virtual void translate() = 0;
	virtual void show() const = 0;
protected:
	long  double num;
	string ori;
	string now;									//这个是用来为后面根据原始单位和现单位在数组中的位置来计算num
	int first,second;
};
class temperature:public units
{
public:
	temperature(long  double x,string s1,string s2);
	int find(string s1,string s2);
	void translate();
	void show() const ;
	
};
temperature::temperature(long  double x,string s1,string s2)
{
	ori = s1;
	now = s2;
	num = x;
}
temperature::find(string s1,string s2)
{
	char temper[3][3]=
	{
		"F",
		"K",
		"C",
	 };
	for(int i = 0;i<3;i++)
	{
		if(temper[i]==s1)
		{
			which = 7;
			first = i;
		}
		if(temper[i]==s2)
		{
			second = i;
		}
	}
	
}
void temperature::translate()
{
	if(first==0&&second==1)
	{
		double t = 5*(num-32)/9;
		num = t+273.16;
	}
	if(first==0&&second==2)
	{
		num = 5*(num-32)/9;
	}
	if(first==1&&second==0)
	{
		double t = num - 273.16;
		num = t*(9/5) + 32;
	}
	if(first==1&&second==2)
	{
		num = num - 273.16;
	}
	if(first==2&&second==0)
	{
		num = num*(9/5) + 32;
	}
	if(first==2&&second==1)
	{
		num = num + 273.16;
	}
}
void temperature::show() const
{
	cout << num << endl;
}
class areaunits:public units
{         //面积单位 
	public:
		areaunits(long double x,string s1,string s2);  //该构造函数不给frist和second赋值 
		int find(string s1,string s2);  //用来判断是否该调用该类 
		void translate();                 //用来计算转变后的值 
		void show() const;       //展示 
};
class vunits:public units
{        //体积单位 
	public:
		vunits(long  double x,string s1,string s2);   //大致同上 
		int find(string s1,string s2);
		void translate();
		void show() const;
}; 

class eleunits:public units
{          //电流单位 
	public:
		eleunits(long  double x,string s1,string s2);   //大致同上 
		int find(string s1,string s2);
		void translate();
		void show() const;
};
areaunits::areaunits(long double x,string s1,string s2)
{   //构造函数 
	num=x;
	ori=s1;
	now=s2;
}
void areaunits::translate()
{ 
	                             //cout<<first<<"  "<<second<<endl;用于调试 
	if(first<=3&&second<=3)
	{    //由面积单位的关系和他在相应数组中的位置，来给定他应该获得的值，以及改变关系 
		int temp=first-second;
		if(first>second)
		{
			num=num*(pow(100,temp));
		}
		else if(first<second)
		{
			temp=fabs(temp);
			num=num/(pow(100,temp));
	    }
	}
	else if(first>3&&second<=3)
	{
		int temp=3-second;
		int temp1=first-3;
		if(temp!=0)
		{
		num=num*(pow(100,temp));
		}
		
		if(temp1==1)
		{
			num=num*10000;
		} 
		else
		{
			num=num*1000000;
		}
	}
	else if(first<=3&&second>3)
	{
		int temp=3-first;
		int temp1=second-1;
		if(temp!=0)
		{
		num=num/(pow(100,temp));
		}
		
		if(temp1==1)
		{
			num=num/10000;
		} 
		else
		{
			num=num/1000000;
		}
	}
	else{
		if(first>second)
		{
			num=num*100;
		}
		else
		{
			num=num/100;
		}
	}
}
areaunits::find(string s1,string s2)
{    //用来找到匹配的使用 
	char units[10][100]=
	{
		"mm2",
		"cm2",
		"dm2",
		"m2",
		"ha",   //公顷 
		"km2",  		
	};
	for(int i=0;i<6;i++)
	{
	     if(units[i]==s1)
		{
			which=4;
			first=i;
		}
			
	}
	for(int i=0;i<6;i++)
	{
	     if(units[i]==s2)
	        { 
				second=i;
			}
	}		

}
void areaunits::show() const
{
	cout<<setiosflags(ios::fixed)<<num<<endl;//此处用于使结果以小数形式输出 
}     //以上为面积单位的实现
vunits::vunits(long double x,string s1,string s2)
{   //构造函数 
	num=x;
	ori=s1;
	now=s2;
}
int vunits::find(string s1,string s2)
{    //用来找到匹配的使用 
	char units[10][100]=
	{
		"mm3",
		"cm3",
		"dm3",
		"m3",
		"ml",
		"l",
	};
	for(int i=0;i<7;i++)
	{
	     if(units[i]==s1)
		{
			which=8;
			first=i;
		}
			
	}
	for(int i=0;i<7;i++)
	{
	     if(units[i]==s2)
	        { 
				second=i;
			}
	}		
	

}
void vunits::translate()
{  //具体的计算体积单位之间的关系的函数 
	if(first==4)
	{
		first=1;	
	}
	else if(first==5)
	{
		first=2;
	}
	if(second==4)
	{
		second=1;	
	}
	else if(second==5)
	{
		second=2;
	}
	int temp=first-second;
	if(temp>0)
	{
		num=num*(pow(1000,temp));
	}
	else if(temp<0)
	{
		temp=fabs(temp);
		num=num/(pow(1000,temp));
	}
	
}   
void vunits::show() const
{
	cout<<setiosflags(ios::fixed)<<num<<endl;//此处用于使结果以小数形式输出 
}    
 
 
 
 
 
 
eleunits::eleunits(long double x,string s1,string s2)
{
	num=x;
	ori=s1;
	now=s2;
}
int eleunits::find(string s1,string s2)
{
	char units[10][100]=
	{
	    "pa", 
		"na",
		"ua",
		"ma",
		"a",
		"ka",	
	};
	for(int i=0;i<6;i++)
	{
	     if(units[i]==s1)
		 {
	     	 first=i;
			 which=5;
		 }
	}	
	for(int i=0;i<6;i++)
	{
	     if(units[i]==s2)
		 {
	     	 second=i;
		 }
	}		
}   
void eleunits::translate()
{
	int temp=first-second;
	
	if(temp>0){
		num=num*(pow(1000,temp));
		
	}
	else if(temp<0)
	{
		temp=fabs(temp);
		num=num/(pow(1000,temp));
	}
}

void eleunits::show() const
{
	cout<<num<<endl;//此处用于使结果以小数形式输出 
}


class transform
{
	public:
		transform(long  double x, string s1, string s2);
		void inputfind(string s1, string s2);
		double calculate(long  double x);
		double digit;
		string str1, str2, oringe, now; 
		
};
transform::transform(long double x, string s1, string s2)
{
	digit=x;
	str1=s1;
	str2=s2;
}
void transform::inputfind(string s1, string s2)
{
	string length[5]={"km", "m", "dm", "cm", "mm"};//???? 
	for(int i=0; i<5; i++)
	{
		if(s1==length[i])
		{
			which=1;
			switch(i)
			{
				case 0: oringe="0"; break;
				case 1: oringe="1"; break;
				case 2: oringe="2"; break;
				case 3: oringe="3"; break;
				case 4: oringe="4"; break;
			}
			//oringe=i;
			for(int j=0; j<5; j++)
			{
				if(s2==length[j])
				{
					switch(j)
					{
					case 0: now="0"; break;
					case 1: now="1"; break;
					case 2: now="2"; break;
					case 3: now="3"; break;
					case 4: now="4"; break;
					}
				
					break; 
				}
			}
			break; 
		}
	}
	string weight[4]={"t", "kg", "g", "mg"};//???? 
	for(int i=0; i<4; i++)
	{
		if(s1==weight[i])
		{
			which=2;
			switch(i)
			{
				case 0: oringe="0"; break;
				case 1: oringe="1"; break;
				case 2: oringe="2"; break;
				case 3: oringe="3"; break;
			}
			for(int j=0; j<4; j++)
			{
				if(s2==weight[j])
				{
					switch(j)
					{
					case 0: now="0"; break;
					case 1: now="1"; break;
					case 2: now="2"; break;
					case 3: now="3"; break;
					}
					break; 
				}
			}
			break; 
		}
	}
	string time[5]={"day", "h", "min", "s", "ms"};//???? 
	for(int i=0; i<5; i++)
	{
		if(s1==time[i])
		{
			which=3;
			switch(i)
			{
				case 0: oringe="0"; break;
				case 1: oringe="1"; break;
				case 2: oringe="2"; break;
				case 3: oringe="3"; break;
				case 4: oringe="4"; break;
			}
			//oringe=i;
			for(int j=0; j<5; j++)
			{
				if(s2==time[j])
				{
					switch(j)
					{
					case 0: now="0"; break;
					case 1: now="1"; break;
					case 2: now="2"; break;
					case 3: now="3"; break;
					case 4: now="4"; break;
					}
					//now=j;
					break; 
				}
			}
			break; 
		}
	}
	string pressure[4]={"mpa", "kpa", "psi", "Pa"};//???? 
	for(int i=0; i<4; i++)
	{
		if(s1==pressure[i])
		{
			which=6;
			switch(i)
			{
				case 0: oringe="0"; break;
				case 1: oringe="1"; break;
				case 2: oringe="2"; break;
				case 3: oringe="3"; break;
			}
			for(int j=0; j<4; j++)
			{
				if(s2==pressure[j])
				{
					switch(j)
					{
					case 0: now="0"; break;
					case 1: now="1"; break;
					case 2: now="2"; break;
					case 3: now="3"; break;
					}
					break; 
				}
			}
			break; 
		}
	}
}
//double transform::calculate(double x)
double transform::calculate(long double x)
{
	if(which==1)
	{
	string s=oringe+now;
	//switch(s)
	//{
		if(s=="01") return x*1000; //break;
		if(s=="02") return x*10000; //break;
		if(s=="03") return x*100000;// break;
		if(s=="04") return x*1000000;// break;
		if(s=="10") return x/1000;// break;
		if(s=="12") return x*10; //break;
		if(s=="13") return x*100; //break;
		if(s=="14") return x*1000; //break;
		if(s=="20") return x/10000; //break;
		if(s=="21") return x/10;// break;
		if(s=="23") return x*10;// break;
		if(s=="24") return x*100;// break;
		if(s=="30") return x/100000; //break;
		if(s=="31") return x/100; //break;
		if(s=="32") return x/10; //break;
		if(s=="34") return x*10; //break;
		if(s=="40") return x/1000000; //break;
		if(s=="41") return x/1000; //break;
		if(s=="42") return x/100; //break;
		if(s=="43") return x/10; //break;*/
	}
	if(which==2)
	{
	string s=oringe+now;
	//switch(s)
	//{
	if(s=="01") return x*1000; //break;
	if(s=="02") return x*1000000; //break;
	if(s=="03") return x*1000000000;// break;
	//if(s=="04") return x*100000;// break;
	if(s=="10") return x/1000;// break;
	if(s=="12") return x*1000; //break;
	if(s=="13") return x*1000000; //break;
		//	if(s=="14") return x*1000; //break;
	if(s=="20") return x/1000000; //break;
	if(s=="21") return x/1000;// break;
	if(s=="23") return x*1000;// break;
		//	if(s=="24") return x*100;// break;
	if(s=="30") return x/1000000000; //break;
	if(s=="31") return x/1000000; //break;
	if(s=="32") return x/1000; //break;
		//	if(s=="34") return x*10; //break;
		//	if(s=="40") return x/1000000; //break;
		//	if(s=="41") return x/1000; //break;
		//	if(s=="42") return x/100; //break;
		//	if(s=="43") return x/10; //break;*/
		//}
	}
	if(which==3)
	{
	string s=oringe+now;
	
	if(s=="01") return x*24; //break;
	if(s=="02") return x*24*60; //break;
	if(s=="03") return x*24*60*60;// break;
	if(s=="04") return x*24*60*60*1000;// break;
	if(s=="10") return x/24;// break;
	if(s=="12") return x*60; //break;
	if(s=="13") return x*60*60; //break;
	if(s=="14") return x*60*60*1000; //break;
	if(s=="20") return x/(24*60); //break;
	if(s=="21") return x/60;// break;
	if(s=="23") return x*60;// break;
	if(s=="24") return x*60*100;// break;
	if(s=="30") return x/(60*60*24); //break;
	if(s=="31") return x/(60*60); //break;
	if(s=="32") return x/60; //break;
	if(s=="34") return x*1000; //break;
	if(s=="40") return x/(24*60*60*1000); //break;
	if(s=="41") return x/(60*60*1000); //break;
	if(s=="42") return x/(60*1000); //break;
	if(s=="43") return x/1000; //break;*/
		//}
	}
	if(which==6) 
	{
	string s=oringe+now;
	if(s=="01") return x*1000; //break;
	if(s=="02") return x*145.037744; //break;
	if(s=="03") return x*1000000;// break;
	if(s=="10") return x/1000;// break;
	if(s=="12") return x/1000*145.037744; //break;
	if(s=="13") return x*1000; //break;
	if(s=="20") return x/145.037744; //break;
	if(s=="21") return x/145.037744*1000;// break;
	if(s=="23") return x/145.037744*1000*1000;// break;
	if(s=="30") return x/1000000; //break;
	if(s=="31") return x/1000; //break;
	if(s=="32") return x/145.037744; //break;
	}
}

int main(){
	long double x;
	string str1,str2;
	char ch;
	printf("\n");
	printf("\n\t\t               单位转换系统\n");
	do{
	
	cout<<"请输入需要转换的数值：";
	
	cin>>x;
	cout<<"请输入原单位的单位名称：";
	cin>>str1;
	cout<<"请输入需要转换成的单位：" ;
	cin>>str2;
	


	transform T(x,str1,str2);       //此处分别调用类，来匹配应该用哪个类来计算单位转换 
	T.inputfind(str1, str2);
	T.calculate(x);
	temperature temper(x,str1,str2);
	temper.find(str1,str2);
	areaunits area1(x,str1,str2);
	eleunits ele1(x,str1,str2);
	vunits vun1(x,str1,str2);
	area1.find(str1,str2);
	ele1.find(str1,str2);
	vun1.find(str1,str2);

	switch(which)        //根据情况调用 
	{
	    case 1:
	    case 2:
		case 3:
		case 6:cout<<"转换后最终结果为："<<setiosflags(ios::fixed)<<T.calculate(x)<<endl;break;
		case 7: temper.translate();
				cout << "转换后最终结果为：";
				temper.show(); 
				break;
		case 4: area1.translate();
		        cout<<"转换后最终结果为：";
		        area1.show();
		        break;
	    case 5: ele1.translate();
	            cout<<"转换后最终结果为：";
	            ele1.show();
	            break;
	    case 8: vun1.translate();
	            cout<<"转换后最终结果为：";
	            vun1.show();
	            break;
	}
	cout<<endl;
}while (ch=getchar()!=EOF);
	return 0;
}
