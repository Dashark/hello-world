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
#include<math.h>  
#include<string.h> 
#define M 100005  
using namespace std;

class date 
{
public:
	date(void){
	};
	~date(void){
	};
	void input();
	void jisuan();
	void show();
	
	
private:
	string yuan;
	string xin;
	double shu;
	int a,b,c;
} ;

void date::input()
{
	int a,b,c,d,m[100];
	cout<<"哪年：";
	cin>>a;
	cout<<"哪月：";
	cin>>b;
	cout<<"哪日：";
	cin>>c;

	if(b<0)b=-b;
	if(c<0)c=-c;
	int s1=0,s2=c,s3;
	for(int i=1900;i<a;i++)
	{
		int a;
		if(i%4==0&&i%100!=0||i%400==0)a=366;
		else a=365;
		s1+=a;//年份的天数 
	}
	if(b%4==0&&b%100!=0||b%400==0) m[2]=29;
	else m[2]=28;
	for(int i=1;i<=12;i++)
	{
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
		m[i]=31;
		else if(i==4||i==6||i==9||i==11)
		m[i]=30;
	}
	for(int i=1;i<b;i++)
	{
		s3+=m[i];//月份的天数 
	}
	int s;
	s=s1+s2+s3-2;//总天数 
	cout<<endl;
	switch(s%7)
	{
		case 0:printf("那天是星期日\n");break;
		case 1:printf("那天是星期一\n");break;
		case 2:printf("那天是星期二\n");break;
		case 3:printf("那天是星期三\n");break;
		case 4:printf("那天是星期四\n");break;
		case 5:printf("那天是星期五\n");break;
		case 6:printf("那天是星期六\n");break;
		default:break;
	}
}

class jiafa 
{
public:
	jiafa(void){
	};
	~jiafa(void){
	};
	void input();
	void jisuan();
	void show();
	
	
private:
	string yuan;
	string xin;
	double shu;
	char s1;
	char s2;
	
} ;
class cheng 
{
public:
	cheng(void){
	};
	~cheng(void){
	};
	void input();
	void jisuan();
	void show();
	
	
private:
	string yuan;
	string xin;
	double shu;
	char s1;
	char s2;
	
} ;
void cheng::input()
{
	char s1[100],s2[100],s[100];  
	int a[100],b[100],X[100]; 
	int i,j,m,n,J;
	cout<<"请输入第一个数的值：";
	cin>>s1;
	cout<<endl;
	cout<<"请输入第二个数的值："; 
	cin>>s2;
	cout<<endl;  
    
    
        memset(X,0,sizeof(X));  
        n=strlen(s1);  
        m=strlen(s2);
		printf("第一个数的长度是 %d \n第二个数的的长度是 %d\n",n,m);  
        J=n+m; 
        for(i=0; i<n; i++)  
        a[i]=s1[n-i-1]-'0';  
        for(i=0; i<m; i++)  
        b[i]=s2[m-1-i]-'0';  
        for(i=0; i<n; i++)  
        for(j=0; j<m; j++)  
        X[i+j]+=a[i]*b[j];  
        for(i=0; i<=J; i++)  
        {  
            if(X[i]>=10)  
            {  
                X[i+1]+=X[i]/10;  
                X[i]%=10;  
            }  
        }  
        i=J;  
        while(X[i]==0) i--;  
        if(i<0) printf("0");  
        else  
        {  	cout<<"2个超大数之积为："; 
            for(; i>=0; i--)  
                printf("%d",X[i]);  
        }  
        printf("\n");  
    
     
}

void jiafa::input()
{
	char s1[M],s2[M];  
int a[M],b[M],c[M];  

    int i,j,k,n,m;
	cout<<"请输入第一个数的值：";
	cin>>s1;
	cout<<endl;
	cout<<"请输入第二个数的值："; 
	cin>>s2;
	cout<<endl;
	  
 
     
        memset(c,0,sizeof(c));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));  
        n=strlen(s1);  
        m=strlen(s2);  
        printf("第一个数的长度是 %d \n第二个数的的长度是 %d\n",n,m);  
 /* 把字符串s1和s2逆序用数字排列*/  
        for(i=0; i<n; i++)  
            a[i]=s1[n-i-1]-'0';  
        for(i=0; i<m; i++)  
            b[i]=s2[m-i-1]-'0';  
        /*加运算*/  
        if(n>m) k=n;  
        else k=m;  
        for(i=0; i<=k; i++)  
        {  
            c[i]+=a[i]+b[i];  
            if(c[i]>9)  
            {  
                c[i+1]++;  
                c[i]%=10;  
            }  
        }  
        /*去除前导0*/  
        i=k;  
        while(c[i]==0) i--;  
  /*判断两个非负数之和是否为0，以及逆序打印c[]*/  
        if(i<0) printf("0");  
        else  
        {  
        	cout<<"2个超大数之和为："; 
            for(; i>=0; i--)  
                printf("%d",c[i]);  
        }  
        printf("\n");  
     
    
 

}



class wendu 
{
public:
	wendu(void){
	};
	~wendu(void){
	};
	void input();
	void jisuan();
	void show();
	
	
private:
	string yuan;
	string xin;
	double shu;
	
} ;

class sudu 
{
public:
	sudu(void){
	};
	~sudu(void){
	};
	void input();
	void jisuan();
	void show();
	
	
private:
	string yuan;
	string xin;
	double shu;
	
} ;


void wendu::input()
{
	string c1="k";
	string c2=".C";
	string c3="mile/h";
	string c4="dm2";
	cout<<"可以进行以下2种单位之间的转换："<<endl;
	cout<<"k(开尔文)  .C(摄氏度)"; 
	cout<<"请选择原单位:";
	cin>>yuan;
	while(yuan!=c1&&yuan!=c2&&yuan!=c3)
	{
		cout<<"输入的原单位有误，请重新输入(摄氏度字母要求大写)：";
		cin>>yuan; 
	}
	cout<<endl;
	cout<<"请输入数值:";
	cout<<endl ;
	cin>>shu;
	while(shu<0||shu>10000000)
	{
		cout<<"输入的数值有误，请重新输入：";
		cin>>shu; 
	}
	cout<<endl;
	cout<<"请选择新单位:"; 
	cin>>xin;
	while(xin!=c1&&xin!=c2&&xin!=c3&&xin!=c4)
	{
		cout<<"输入的新单位有误，请重新输入(摄氏度字母要求大写)：";
		cin>>xin;
	} 	 	
}

void wendu::show()
{
	if(yuan=="k"&&xin=="k")
	{
		cout<<shu<<" k= "<<shu<<"k"<<endl;
	}
	else if(yuan=="k"&&xin==".C")
	{
		cout<<shu<<" k= "<<shu-273.15<<".C"<<endl;
	}
	if(yuan==".c"&&xin==".C")
	{
		cout<<shu<<" .C= "<<shu<<".C"<<endl;
	}
	if(yuan==".c"&&xin=="k")
	{
		cout<<shu<<" .C= "<<shu+273.15<<"k"<<endl;
	}
	
} 
void sudu::input()
{
	string c1="ft/s";
	string c2="m/s";
	string c3="mile/h";
	string c4="dm2";
	cout<<"可以进行以下4种单位之间的转换："<<endl;
	cout<<"ft/s  m/s  mile/h"; 
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
	while(shu<0||shu>10000000)
	{
		cout<<"输入的数值有误，请重新输入：";
		cin>>shu; 
	}
	cout<<endl;
	cout<<"请选择新单位:"; 
	cin>>xin;
	while(xin!=c1&&xin!=c2&&xin!=c3&&xin!=c4)
	{
		cout<<"输入的新单位有误，请重新输入：";
		cin>>xin;
	} 	 	
}

void sudu::show()
{
	if(yuan=="ft/s"&&xin=="ft/s")
	{
		cout<<shu<<" ft/s= "<<shu<<"ft/s"<<endl;
	}
	else if(yuan=="ft/s"&&xin=="m/s")
	{
		cout<<shu<<" ft/s= "<<shu*0.3048<<"m/s"<<endl;
	}
	else if(yuan=="ft/s"&&xin=="mile/h")
	{
		cout<<shu<<" ft/s= "<<shu*0.3048/0.44704<<"mile/h"<<endl;
	}
	else if(yuan=="m/s"&&xin=="m/s")
	{
		cout<<shu<<" m/s= "<<shu<<"m/s"<<endl;
	}
	else if(yuan=="m/s"&&xin=="ft/s")
	{
		cout<<shu<<" m/s= "<<shu/0.3048<<"ft/s"<<endl;
	}
	else if(yuan=="m/s"&&xin=="mile/h")
	{
		cout<<shu<<" m/s= "<<shu/0.44704<<"mile/h"<<endl;
	}
	else if(yuan=="mile/h"&&xin=="mile/h")
	{
		cout<<shu<<" mile/h "<<shu<<"mile/h"<<endl;
	}
	else if(yuan=="mile/h"&&xin=="m/s")
	{
		cout<<shu<<" mile/h "<<shu*0.44704<<"m/s"<<endl;
	}
	else if(yuan=="mile/h"&&xin=="ft/s")
	{
		cout<<shu<<" mile/h "<<shu*0.44704/0.3048<<"ft/s"<<endl;
	}
	
}

class area
{
public:
	area(void){
	};
	~area(void){
	};
	void input();
	void jisuan();
	void show();
	
	
private:
	string yuan;
	string xin;
	double shu;
	
} ;


void area::input()
{
	string c1="km2";
	string c2="ha";
	string c3="m2";
	string c4="dm2";
	cout<<"可以进行以下4种单位之间的转换："<<endl;
	cout<<"km2  ha  m2  dm2"; 
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
	while(shu<0||shu>10000000)
	{
		cout<<"输入的数值有误，请重新输入：";
		cin>>shu; 
	}
	cout<<endl;
	cout<<"请选择新单位:"; 
	cin>>xin;
	while(xin!=c1&&xin!=c2&&xin!=c3&&xin!=c4)
	{
		cout<<"输入的新单位有误，请重新输入：";
		cin>>xin;
	} 	 	
}


void area::show()
{
	if(yuan=="km2"&&xin=="km2")
	{
		cout<<shu<<" km2= "<<shu<<"km2"<<endl;
	}
	else if(yuan=="km2"&&xin=="ha")
	{
		cout<<shu<<" km2= "<<100*shu<<"ha"<<endl;
	}
	else if(yuan=="km2"&&xin=="m2")
	{
		cout<<shu<<" km2= "<<10000*100*shu<<"m2"<<endl;
	}
	else if(yuan=="km2"&&xin=="dm2")
	{
		cout<<shu<<" km2= "<<10000*100*100*shu<<"dm2"<<endl;
	}
	else if(yuan=="ha"&&xin=="km2")
	{
		cout<<shu<<" ha= "<<shu/100<<"km2"<<endl;
	}
	else if(yuan=="ha"&&xin=="ha")
	{
		cout<<shu<<" ha= "<<shu<<"ha"<<endl;
	}
	else if(yuan=="ha"&&xin=="m2")
	{
		cout<<shu<<" ha= "<<shu*10000<<"m2"<<endl;
	}
	else if(yuan=="ha"&&xin=="dm2")
	{
		cout<<shu<<" ha= "<<shu*1000000<<"dm2"<<endl;
	}
	else if(yuan=="m2"&&xin=="dm2")
	{
		cout<<shu<<" m2= "<<shu*100<<"dm2"<<endl;
	}
	else if(yuan=="m2"&&xin=="km2")
	{
		cout<<shu<<" m2= "<<shu/1000000<<"km2"<<endl;
	}
	else if(yuan=="m2"&&xin=="ha")
	{
		cout<<shu<<" m2= "<<shu/10000<<"ha"<<endl;
	}
	else if(yuan=="m2"&&xin=="m2")
	{
		cout<<shu<<" m2= "<<shu<<"m2"<<endl;
	}
	else if(yuan=="dm2"&&xin=="dm2")
	{
		cout<<shu<<" dm2= "<<shu<<"dm2"<<endl;
	}
	else if(yuan=="dm2"&&xin=="m2")
	{
		cout<<shu<<" dm2= "<<shu/100<<"m2"<<endl;
	}
	else if(yuan=="dm2"&&xin=="ha")
	{
		cout<<shu<<" dm2= "<<shu/1000000<<"ha"<<endl;
	}
	else if(yuan=="dm2"&&xin=="km2")
	{
		cout<<shu<<" dm2= "<<shu/100000000<<"km2"<<endl;
	}
	
}
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
	while(shu<0||shu>10000000)
	{
		cout<<"输入的数值有误，请重新输入：";
		cin>>shu; 
	}
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
	while(shu<0||shu>10000000)
	{
		cout<<"输入的数值有误，请重新输入：";
		cin>>shu; 
	}
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
	while(shu<0||shu>10000000)
	{
		cout<<"输入的数值有误，请重新输入：";
		cin>>shu; 
	}
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

void yonghu()
{
	
}

int main()
{
	
	system("color 27");
	cout << "请输入管理员使用权限密码(权限密码：admin)：" << endl;
	string str;
	str = "admin";
	string str1;
	cin >> str1;
	if (str1 == str)
	{
		cout << "通过认证！！！" << endl << endl;
		system("pause");
	}
	else
	{
		cout << endl << "密码错误，对不起，您没有使用权限！！！" << endl;
		cout<<"\t\t感谢使用，再见！！！";
			cout << "\t\t\t                                " << endl
				<< "\t\t版权所有@SCU计算机学院 " << endl
				<< "\t\t\t                              " << endl
				<< "\t\t如果想用该软件，请找开发者索要。"<<endl
				<< "\t\t如有技术问题请发电邮至：448407561@qq.com" << endl; 
		
		return 0;
	}
	 
	char flag='Y';
	while(toupper(flag)=='Y')
	{
		system("cls");
		cout<<"\t\t\t\t\t###########################################"<<endl; 
		cout<<"\t\t\t\t\t##请选择您要换算的单位种类或者小功能:    ##"<<endl;
		cout<<"\t\t\t\t\t##1:重量单位              2：压力单位    ##"<<endl;
		cout<<"\t\t\t\t\t##3:长度单位              4: 面积单位    ##"<<endl;
		cout<<"\t\t\t\t\t##5:速度单位              6: 温度单位    ##"<<endl;
		cout<<"\t\t\t\t\t##7:别的小功能            8: 赞助开发者  ##"<<endl;
		cout<<"\t\t\t\t\t###########################################"<<endl; 
		
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
			
			case 4:
				{
					system("cls");
					area unit;
					unit.input();
					unit.show();
					break;	
				}
				
			case 5:
				{
					system("cls");
					sudu unit;
					unit.input();
					unit.show();
					break;	
				}
				
			case 6:
				{
					system("cls");
					wendu unit;
					unit.input();
					unit.show();
					break;
			 	}
			 	
			 	case 8:
			{
				system("cls");
				cout<<"谢谢你的好心，我只是开个玩笑 XD"<<endl;
				cout<<"本程序免费使用"<<endl;
				
				break; 
			 } 
				 
			case 7:
				{
					system("cls");
					cout<<"\t\t\t\t\t#########################################"<<endl;
					cout<<"\t\t\t\t\t##请选择您要的功能：                   ##"<<endl;
					cout<<"\t\t\t\t\t##1:大数加法             2：大数乘法   ##"<<endl;
					cout<<"\t\t\t\t\t##3:查看今天星期几                     ##"<<endl;
					cout<<"\t\t\t\t\t#########################################"<<endl;
					int i;
					cin>>i;
					switch(i)
					{
						case 1:
							{
								system("cls");
								jiafa unit;
								unit.input();								
								break;	
							}
							
						case 2:
							{
								system("cls");
								cheng unit;
								unit.input();								
								break;	
							}
							
						case 3:
						{
							system("cls");
								date unit;
								unit.input();								
								break;
						 }
						 
						 default:
						 {
						 	cout<<"选择不合法，我问你到底用不用？";
							break;
						  } 
						 
					}
					break;
				 } 
				
				default:
					{
						cout<<"选择不合法，我问你到底用不用？";
						break;
					}
			
		 } 
		 
		 cout<<endl<<"是否继续使用多功能单位转换器？（Y/N）";
		 cin>>flag;
		 cout<<endl<<endl;
		 
		 if(toupper(flag)=='N')
		 {
		 	system("cls");
			cout<<"\t\t感谢使用，再见！！！";
			cout << "\t\t\t                                " << endl;
			cout<<"\t\t虽然这个程序功能不多，"<<endl
			<<"\t\t而且为了凑代码行数所以用的算法也很垃圾，但！是！重点来了："<<endl
				<< "\t\t版权所有@SCU计算机学院 " << endl
				<< "\t\t再一次感谢你使用该软件！"<<endl
				<< "\t\t\t                              " << endl
				<< "\t\t如有技术问题请发电邮至：448407561@qq.com" << endl; 
			return 0;
		 }
	}

	
}
