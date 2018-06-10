//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......
//还有很多单位转换，有些单位是其它单位组合出来的
#include<iostream> 
using namespace std;

class Unit
{
	public:
		virtual void trans(double)=0;
		virtual bool find(string,string)=0;
};

class Base:public Unit
{
	private:
		int mark,now,next;
		string lenth[9];
		double len_mul[9];
		string time[5];
		double time_mul[5];
		string quality[9];
		double qual_mul[9];
	public:
		Base()
		{
			mark=0;
			now=next=100;
			lenth[0]="in"; lenth[1]="ft"; lenth[2]="yd"; lenth[3]="sm";
			lenth[4]="mm"; lenth[5]="cm"; lenth[6]="km"; lenth[7]="m";
			lenth[8]="nm"; 
			len_mul[0]=0.0254; len_mul[1]=0.3048; len_mul[2]=0.9144; len_mul[3]=1852;
			len_mul[4]=0.001;   len_mul[5]=0.1;    len_mul[6]=1000;   len_mul[7]=1;
			len_mul[8]=0.000000001;
			
			time[0]="ms"; time[1]="s"; time[2]="min"; time[3]="h"; time[4]="d";
			time_mul[0]=0.001; time_mul[1]=1; time_mul[2]=60; time_mul[3]=3600;
			time_mul[4]=216000;
			
			quality[0]="g"; quality[1]="t"; quality[2]="dwt"; quality[3]="cwt";
			quality[4]="oz"; quality[5]="kg"; quality[6]="mg"; quality[7]="lb";
			quality[8]="dr";
			qual_mul[0]=1; qual_mul[1]=0.000001; qual_mul[2]=1.5551738; qual_mul[3]=50802.3454400;
			qual_mul[4]=28.3495231; qual_mul[5]=1000; qual_mul[6]=0.001; qual_mul[7]=453.59237;
			qual_mul[8]=1.7718452;
		}
		virtual bool find(string str1,string str2)
		{
			cout<<sizeof(lenth)<<endl;
			cout<<sizeof(len_mul)<<endl;
			cout<<sizeof(time)<<endl;
			cout<<sizeof(time_mul)<<endl;
			for(int i=0;i<9;i++)
			{
				if(str1==lenth[i])
				{
					for(int j=0;j<9;j++)
					{
						if(str2==lenth[j])
						{
							mark=1;
							now=i;
							next=j;
							return true;
						}
					}
				}
			}
			for(int i=0;i<5;i++)
			{
				if(str1==time[i])
				{
					for(int j=0;j<5;j++)
					{
						if(str2==time[j])
						{
							mark=1;
							now=i;
							next=j;
							return true;
						}
					}
				}
			}
			for(int i=0;i<9;i++)
			{
				if(str1==quality[i])
				{
					for(int j=0;j<9;j++)
					{
						if(str2==quality[j])
						{
							mark=1;
							now=i;
							next=j;
							return true;
						}
					}
				}
			}
			if(!mark) return false;
		}
		virtual void trans(double num)
		{
			if(now==next)
			{
				cout<<num;
				return;
			}
			switch(mark)
			{
				case 1:cout<<num*len_mul[now]/len_mul[next]; break;
				case 2:cout<<num*time_mul[now]/time_mul[next]; break;
				case 3:cout<<num*qual_mul[now]/qual_mul[next]; break;
			}
		}
};

class Mix:public Unit
{
	private:
		int mark,now,next;
	    string area[10];
	    double area_mul[10];
	    
	public:
		Mix()
		{
			mark=0;
			now=next=100;
			area[0]="ha"; area[1]="m2"; area[2]="cm2"; area[3]="sq_mi";
			area[4]="sq_rd"; area[5]="sq_ft"; area[6]="sq in"; area[7]="sq_yd" ;
			area[8]="mm2"; area[9]="km2";
			area_mul[0]=10000; area_mul[1]=1; area_mul[2]=0.0001; area_mul[3]=2589988.1;
			area_mul[4]=25.292853; area_mul[5]=0.09290304; area_mul[6]=0.00064516; area_mul[7]=0.83612736;
			area_mul[8]=0.000001; area_mul[9]=1000000;
		}
		virtual bool find(string str1,string str2)
		{
			for(int i=0;i<10;i++)
			{
				if(area[i]==str1)
				{
					for(int j=0;j<10;j++)
					{
						if(area[j]==str2)
						{
							mark=1;
							now=i;
							next=j;
							return true;
						}
					}
				}
			}
			if(!mark) return false;
		}
		virtual void trans(double num)
		{
			if(now==next)
			{
				cout<<num;
				return;
			}
			switch(mark)
			{
				case 1:cout<<num*area_mul[now]/area_mul[next]; break;
			}
		}
};

int main()
{
	bool win;
	double num;
	string origin,end;
	cout<<"请输入正确的数字与单位，所有单位用相应的英文缩写表示，单位内部不允许有空格与括号，若需空格请用下划线连接"<<endl; 
	while(cin>>num>>origin>>end)
	{
    	Base obj1;
    	win=obj1.find(origin,end);
    	if(win)
    	obj1.trans(num);
	    else
	    {
		    Mix obj2;
		    obj2.find(origin,end);
		    if(!win) cout<<"Error";
		    else obj2.trans(num);
	    }
	}
	return 0;
}
