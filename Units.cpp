#include<iostream>
#include<string.h>
using namespace std;
class Length {
	public:
		int Judge( char* unit_name)								//判断传入的字符是否与该类型单位中的某一个相同							
		{														//若相同则通过 x 定位该单位（字符串）在字符数组中的位置 
			for(i=0;i<13;i++)
			{
				if(strcmp(unit_name,Len_unit[i])==0)
					x=i; 
			}
			return x;	
		}	
		double Operation(int a,int b,double unit_num)
		{																		//通过排列组合的方式  根据 要被换算的单位 和 想要换算出来的单位 结合数学知识，返回它们之间的数值关系 
			if(a==0&&b==0)
				return unit_num;
			if(a==0&&b==1)
				return 1e3*unit_num;
			if(a==0&&b==2)
				return 1e4*unit_num;
			if(a==0&&b==3)
				return 1e5*unit_num;
			if(a==0&&b==4)
				return 1e6*unit_num;
			if(a==0&&b==5)
				return 1e9*unit_num;
			if(a==0&&b==6)
				return 1e12*unit_num;	
			if(a==0&&b==7)
				return 2*unit_num;	
			if(a==0&&b==8)
				return 300.030003*unit_num;	
			if(a==0&&b==9)
				return 3000.30003*unit_num;	
			if(a==0&&b==10)
				return 30003.0003*unit_num;	
			if(a==0&&b==11)
				return 300030.003*unit_num;
			if(a==0&&b==12)
				return 3000300.03*unit_num;	
			
				
				
			if(a==1&&b==0)
				return 1e-3*unit_num;	
			if(a==1&&b==1)
				return unit_num;	
			if(a==1&&b==2)
				return 10*unit_num;	
			if(a==1&&b==3)
				return 1e2*unit_num;	
			if(a==1&&b==4)
				return 1e3*unit_num;	
			if(a==1&&b==5)
				return 1e6*unit_num;
			if(a==1&&b==6)
				return 1e9*unit_num;	
			if(a==1&&b==7)
				return 2e-3*unit_num;	
			if(a==1&&b==8)
				return 0.30003*unit_num;	
			if(a==1&&b==9)
				return 3.00030003*unit_num;	
			if(a==1&&b==10)
				return 30.0030003*unit_num;	
			if(a==1&&b==11)
				return 300.030003*unit_num;	
			if(a==1&&b==12)
				return 3000.30003*unit_num;	
			
				
				
			if(a==2&&b==0)
				return 1e-4*unit_num;	
			if(a==2&&b==1)
				return 0.1*unit_num;	
			if(a==2&&b==2)
				return unit_num;	
			if(a==2&&b==3)
				return 10*unit_num;	
			if(a==2&&b==4)
				return 1e2*unit_num;	
			if(a==2&&b==5)
				return 1e5*unit_num;
			if(a==2&&b==6)
				return 1e8*unit_num;	
			if(a==2&&b==7)
				return 2e-4*unit_num;	
			if(a==2&&b==8)
				return 0.030003*unit_num;	
			if(a==2&&b==9)
				return 0.30003*unit_num;	
			if(a==2&&b==10)
				return 3.00030003*unit_num;	
			if(a==2&&b==11)
				return 30.0030003*unit_num;	
			if(a==2&&b==12)
				return 300.030003*unit_num;
			
				
				
			if(a==3&&b==0)
				return 1e-5*unit_num;	
			if(a==3&&b==1)
				return 1e-2*unit_num;	
			if(a==3&&b==2)
				return 0.1*unit_num;	
			if(a==3&&b==3)
				return unit_num;	
			if(a==3&&b==4)
				return 10*unit_num;	
			if(a==3&&b==5)
				return 1e4*unit_num;	
			if(a==3&&b==6)
				return 1e7*unit_num;	
			if(a==3&&b==7)
				return 2e-5*unit_num;	
			if(a==3&&b==8)
				return 0.0030003*unit_num;	
			if(a==3&&b==9)
				return 0.030003*unit_num;	
			if(a==3&&b==10)
				return 0.30003*unit_num;	
			if(a==3&&b==11)
				return 3.00030003*unit_num;	
			if(a==3&&b==12)
				return 30.0030003*unit_num;
				
				
				
			if(a==4&&b==0)
				return 1e-6*unit_num;	
			if(a==4&&b==1)
				return 1e-3*unit_num;	
			if(a==4&&b==2)
				return 0.01*unit_num;	
			if(a==4&&b==3)
				return 0.1*unit_num;	
			if(a==4&&b==4)
				return unit_num;	
			if(a==4&&b==5)
				return 1e3*unit_num;	
			if(a==4&&b==6)
				return 1e6*unit_num;	
			if(a==4&&b==7)
				return 2e-6*unit_num;	
			if(a==4&&b==8)
				return 0.00030003*unit_num;	
			if(a==4&&b==9)
				return 0.0030003*unit_num;	
			if(a==4&&b==10)
				return 0.030003*unit_num;	
			if(a==4&&b==11)
				return 0.300030003*unit_num;	
			if(a==4&&b==12)
				return 3.00030003*unit_num;
				
				
			if(a==5&&b==0)
				return 1e-9*unit_num;	
			if(a==5&&b==1)
				return 1e-6*unit_num;	
			if(a==5&&b==2)
				return 1e-5*unit_num;	
			if(a==5&&b==3)
				return 1e-4*unit_num;	
			if(a==5&&b==4)
				return 1e-3*unit_num;	
			if(a==5&&b==5)
				return unit_num;	
			if(a==5&&b==6)
				return 1e3*unit_num;	
			if(a==5&&b==7)
				return 2e-9*unit_num;	
			if(a==5&&b==8)
				return 3e-7*unit_num;	
			if(a==5&&b==9)
				return 3e-6*unit_num;	
			if(a==5&&b==10)
				return 3e-5*unit_num;	
			if(a==5&&b==11)
				return 3e-4*unit_num;	
			if(a==5&&b==12)
				return 3e-3*unit_num;
				
				
				
			if(a==6&&b==0)
				return 1e-12*unit_num;	
			if(a==6&&b==1)
				return 1e-9*unit_num;	
			if(a==6&&b==2)
				return 1e-8*unit_num;	
			if(a==6&&b==3)
				return 1e-7*unit_num;	
			if(a==6&&b==4)
				return 1e-6*unit_num;	
			if(a==6&&b==5)
				return 1e-3*unit_num;	
			if(a==6&&b==6)
				return unit_num;	
			if(a==6&&b==7)
				return 2e-9*unit_num;	
			if(a==6&&b==8)
				return 3e-7*unit_num;	
			if(a==6&&b==9)
				return 3e-6*unit_num;	
			if(a==6&&b==10)
				return 3e-5*unit_num;	
			if(a==6&&b==11)
				return 3e-4*unit_num;	
			if(a==6&&b==12)
				return 3e-3*unit_num;
				
				
			if(a==7&&b==0)
				return 0.5*unit_num;
			if(a==7&&b==1)
				return 0.5*1e3*unit_num;
			if(a==7&&b==2)
				return 0.5*1e4*unit_num;
			if(a==7&&b==3)
				return 0.5*1e5*unit_num;
			if(a==7&&b==4)
				return 0.5*1e6*unit_num;
			if(a==7&&b==5)
				return 0.5*1e9*unit_num;
			if(a==7&&b==6)
				return 0.5*1e12*unit_num;	
			if(a==7&&b==7)
				return unit_num;	
			if(a==7&&b==8)
				return 0.5*300.030003*unit_num;	
			if(a==7&&b==9)
				return 0.5*3000.30003*unit_num;	
			if(a==7&&b==10)
				return 0.5*30003.0003*unit_num;	
			if(a==7&&b==11)
				return 0.5*300030.003*unit_num;
			if(a==7&&b==12)
				return 0.5*3000300.03*unit_num;	
			
				
			if(a==8&&b==0)
				return 0.003333*unit_num;	
			if(a==8&&b==1)
				return 3.333*unit_num;	
			if(a==8&&b==2)
				return 33.33*unit_num;	
			if(a==8&&b==3)
				return 333.3*unit_num;	
			if(a==8&&b==4)
				return 3333*unit_num;	
			if(a==8&&b==5)
				return 3333000*unit_num;	
			if(a==8&&b==6)
				return 3.333e6*unit_num;	
			if(a==8&&b==7)
				return 0.006666*unit_num;	
			if(a==8&&b==8)
				return unit_num;	
			if(a==8&&b==9)
				return 10*unit_num;	
			if(a==8&&b==10)
				return 100*unit_num;	
			if(a==8&&b==11)
				return 1e3*unit_num;	
			if(a==8&&b==12)
				return 1e4*unit_num;
				
			if(a==9&&b==0)
				return 0.1*0.003333*unit_num;	
			if(a==9&&b==1)
				return 0.1*3.333*unit_num;	
			if(a==9&&b==2)
				return 0.1*33.33*unit_num;	
			if(a==9&&b==3)
				return 0.1*333.3*unit_num;	
			if(a==9&&b==4)
				return 0.1*3333*unit_num;	
			if(a==9&&b==5)
				return 0.1*3333000*unit_num;	
			if(a==9&&b==6)
				return 0.1*3.333e6*unit_num;	
			if(a==9&&b==7)
				return 0.1*0.006666*unit_num;	
			if(a==9&&b==8)
				return 0.1*unit_num;	
			if(a==9&&b==9)
				return unit_num;	
			if(a==9&&b==10)
				return 10*unit_num;	
			if(a==9&&b==11)
				return 0.1*1e3*unit_num;	
			if(a==9&&b==12)
				return 0.1*1e4*unit_num;
			
			if(a==10&&b==0)
				return 0.1*0.1*0.003333*unit_num;	
			if(a==10&&b==1)
				return 0.1*0.1*3.333*unit_num;	
			if(a==10&&b==2)
				return 0.1*0.1*33.33*unit_num;	
			if(a==10&&b==3)
				return 0.1*0.1*333.3*unit_num;	
			if(a==10&&b==4)
				return 0.1*0.1*3333*unit_num;	
			if(a==10&&b==5)
				return 0.1*0.1*3333000*unit_num;	
			if(a==10&&b==6)
				return 0.1*0.1*3.333e6*unit_num;	
			if(a==10&&b==7)
				return 0.1*0.1*0.006666*unit_num;	
			if(a==10&&b==8)
				return 0.1*0.1*unit_num;	
			if(a==10&&b==9)
				return 0.1*unit_num;	
			if(a==10&&b==10)
				return unit_num;	
			if(a==10&&b==11)
				return 0.1*0.1*1e3*unit_num;	
			if(a==10&&b==12)
				return 0.1*0.1*1e4*unit_num;
					
			if(a==11&&b==0)
				return 0.1*0.1*0.1*0.003333*unit_num;	
			if(a==11&&b==1)
				return 0.1*0.1*0.1*3.333*unit_num;	
			if(a==11&&b==2)
				return 0.1*0.1*0.1*33.33*unit_num;	
			if(a==11&&b==3)
				return 0.1*0.1*0.1*333.3*unit_num;	
			if(a==11&&b==4)
				return 0.1*0.1*0.1*3333*unit_num;	
			if(a==11&&b==5)
				return 0.1*0.1*0.1*3333000*unit_num;	
			if(a==11&&b==6)
				return 0.1*0.1*0.1*3.333e6*unit_num;	
			if(a==11&&b==7)
				return 0.1*0.1*0.1*0.006666*unit_num;	
			if(a==11&&b==8)
				return 0.1*0.1*0.1*unit_num;	
			if(a==11&&b==9)
				return 0.1*0.1*unit_num;	
			if(a==11&&b==10)
				return 0.1*unit_num;	
			if(a==11&&b==11)
				return unit_num;	
			if(a==11&&b==12)
				return 0.1*0.1*0.1*1e4*unit_num;	
				
			if(a==12&&b==0)
				return 0.1*0.1*0.1*0.1*0.003333*unit_num;	
			if(a==12&&b==1)
				return 0.1*0.1*0.1*0.1*3.333*unit_num;	
			if(a==12&&b==2)
				return 0.1*0.1*0.1*0.1*33.33*unit_num;	
			if(a==12&&b==3)
				return 0.1*0.1*0.1*0.1*333.3*unit_num;	
			if(a==12&&b==4)
				return 0.1*0.1*0.1*0.1*3333*unit_num;	
			if(a==12&&b==5)
				return 0.1*0.1*0.1*0.1*3333000*unit_num;	
			if(a==12&&b==6)
				return 0.1*0.1*0.1*0.1*3.333e6*unit_num;	
			if(a==12&&b==7)
				return 0.1*0.1*0.1*0.1*0.006666*unit_num;	
			if(a==12&&b==8)
				return 0.1*0.1*0.1*0.1*unit_num;	
			if(a==12&&b==9)
				return 0.1*0.1*0.1*unit_num;	
			if(a==12&&b==10)
				return 0.1*0.1*unit_num;	
			if(a==12&&b==11)
				return 0.1*unit_num;	
			if(a==12&&b==12)
				return unit_num;	
						
		}	
	private:
		char Len_unit[13][5]={"km","m","dm","cm","mm","um","nm","里","丈","尺","寸","分","厘"};
		int i,x;
};

class Weigth {
	public:
		int Judge( char* unit_name)	
		{
			for(i=0;i<10;i++)
			{
				if(strcmp(unit_name,Wei_unit[i])==0)
					x=i;
			}
			return x;	
		}	
		double Operation(int a,int b,double unit_num)
		{
			if(a==0&&b==0)
				return unit_num;
			if(a==0&&b==1)
				return 1e3*unit_num;
			if(a==0&&b==2)
				return 1e6*unit_num;
			if(a==0&&b==3)
				return 1e9*unit_num;
			if(a==0&&b==4)
				return 2e3*unit_num;
			if(a==0&&b==5)
				return 20*unit_num;
			if(a==0&&b==6)
				return 2e4*unit_num;	
			if(a==0&&b==7)
				return 2e5*unit_num;	
			if(a==0&&b==8)
				return 2204.6226*unit_num;	
			if(a==0&&b==9)
				return 35273.962*unit_num;
			
			if(a==1&&b==0)
				return 1e-3*unit_num;
			if(a==1&&b==1)
				return unit_num;
			if(a==1&&b==2)
				return 1e-3*1e6*unit_num;
			if(a==1&&b==3)
				return 1e-3*1e9*unit_num;
			if(a==1&&b==4)
				return 1e-3*2e3*unit_num;
			if(a==1&&b==5)
				return 1e-3*20*unit_num;
			if(a==1&&b==6)
				return 1e-3*2e4*unit_num;	
			if(a==1&&b==7)
				return 1e-3*2e5*unit_num;	
			if(a==1&&b==8)
				return 1e-3*2204.6226*unit_num;	
			if(a==1&&b==9)
				return 1e-3*35273.962*unit_num;
	
			if(a==2&&b==0)
				return 1e-3*1e-3*unit_num;
			if(a==2&&b==1)
				return 1e-3*unit_num;
			if(a==2&&b==2)
				return unit_num;
			if(a==2&&b==3)
				return 1e-3*1e-3*1e9*unit_num;
			if(a==2&&b==4)
				return 1e-3*1e-3*2e3*unit_num;
			if(a==2&&b==5)
				return 1e-3*1e-3*20*unit_num;
			if(a==2&&b==6)
				return 1e-3*1e-3*2e4*unit_num;	
			if(a==2&&b==7)
				return 1e-3*1e-3*2e5*unit_num;	
			if(a==2&&b==8)
				return 1e-3*1e-3*2204.6226*unit_num;	
			if(a==2&&b==9)
				return 1e-3*1e-3*35273.962*unit_num;
	
			if(a==3&&b==0)
				return 1e-3*1e-3*1e-3*unit_num;
			if(a==3&&b==1)
				return 1e-3*1e-3*unit_num;
			if(a==3&&b==2)
				return 1e-3*unit_num;
			if(a==3&&b==3)
				return unit_num;
			if(a==3&&b==4)
				return 1e-3*1e-3*1e-3*2e3*unit_num;
			if(a==3&&b==5)
				return 1e-3*1e-3*1e-3*20*unit_num;
			if(a==3&&b==6)
				return 1e-3*1e-3*1e-3*2e4*unit_num;	
			if(a==3&&b==7)
				return 1e-3*1e-3*1e-3*2e5*unit_num;	
			if(a==3&&b==8)
				return 1e-3*1e-3*1e-3*2204.6226*unit_num;	
			if(a==3&&b==9)
				return 1e-3*1e-3*1e-3*35273.962*unit_num;
	
			if(a==4&&b==0)
				return 5e-4*unit_num;
			if(a==4&&b==1)
				return 5e-1*unit_num;
			if(a==4&&b==2)
				return 5e2*unit_num;
			if(a==4&&b==3)
				return 5e5*unit_num;
			if(a==4&&b==4)
				return unit_num;
			if(a==4&&b==5)
				return 0.01*unit_num;
			if(a==4&&b==6)
				return 10*unit_num;	
			if(a==4&&b==7)
				return 100*unit_num;	
			if(a==4&&b==8)
				return 1.1023113*unit_num;	
			if(a==4&&b==9)
				return 17.636981*unit_num;
	
			if(a==5&&b==0)
				return 100*5e-4*unit_num;
			if(a==5&&b==1)
				return 100*5e-1*unit_num;
			if(a==5&&b==2)
				return 100*5e2*unit_num;
			if(a==5&&b==3)
				return 100*5e5*unit_num;
			if(a==5&&b==4)
				return 100*unit_num;
			if(a==5&&b==5)
				return unit_num;
			if(a==5&&b==6)
				return 100*10*unit_num;	
			if(a==5&&b==7)
				return 100*100*unit_num;	
			if(a==5&&b==8)
				return 100*1.1023113*unit_num;	
			if(a==5&&b==9)
				return 100*17.636981*unit_num;
	
			if(a==6&&b==0)
				return 1e-3*100*5e-4*unit_num;
			if(a==6&&b==1)
				return 1e-3*100*5e-1*unit_num;
			if(a==6&&b==2)
				return 1e-3*100*5e2*unit_num;
			if(a==6&&b==3)
				return 1e-3*100*5e5*unit_num;
			if(a==6&&b==4)
				return 1e-3*100*unit_num;
			if(a==6&&b==5)
				return 1e-3*unit_num;
			if(a==6&&b==6)
				return unit_num;	
			if(a==6&&b==7)
				return 1e-3*100*100*unit_num;	
			if(a==6&&b==8)
				return 1e-3*100*1.1023113*unit_num;	
			if(a==6&&b==9)
				return 1e-3*100*17.636981*unit_num;
	
			if(a==7&&b==0)
				return 0.1*1e-3*100*5e-4*unit_num;
			if(a==7&&b==1)
				return 0.1*1e-3*100*5e-1*unit_num;
			if(a==7&&b==2)
				return 0.1*1e-3*100*5e2*unit_num;
			if(a==7&&b==3)
				return 0.1*1e-3*100*5e5*unit_num;
			if(a==7&&b==4)
				return 0.1*1e-3*100*unit_num;
			if(a==7&&b==5)
				return 0.1*1e-3*unit_num;
			if(a==7&&b==6)
				return 0.1*unit_num;	
			if(a==7&&b==7)
				return unit_num;	
			if(a==7&&b==8)
				return 0.1*1e-3*100*1.1023113*unit_num;	
			if(a==7&&b==9)
				return 0.1*1e-3*100*17.636981*unit_num;
	
			if(a==8&&b==0)
				return 4.5359237e-4*unit_num;	
			if(a==8&&b==1)
				return 4.5359237e-1*unit_num;	
			if(a==8&&b==2)
				return 4.5359237e2*unit_num;	
			if(a==8&&b==3)
				return 4.5359237e5*unit_num;	
			if(a==8&&b==4)
				return 0.90718474*unit_num;	
			if(a==8&&b==5)
				return 0.90718474e-2*unit_num;	
			if(a==8&&b==6)
				return 9.0718474*unit_num;	
			if(a==8&&b==7)
				return 90.718474*unit_num;	
			if(a==8&&b==8)
				return unit_num;	
			if(a==8&&b==9)
				return 16*unit_num;	
			
			if(a==9&&b==0)
				return 4.5359237e-4*unit_num/16;	
			if(a==9&&b==1)
				return 4.5359237e-1*unit_num/16;	
			if(a==9&&b==2)
				return 4.5359237e2*unit_num/16;	
			if(a==9&&b==3)
				return 4.5359237e5*unit_num/16;	
			if(a==9&&b==4)
				return 0.90718474*unit_num/16;	
			if(a==9&&b==5)
				return 0.90718474e-2*unit_num/16;	
			if(a==9&&b==6)
				return 9.0718474*unit_num/16;	
			if(a==9&&b==7)
				return 90.718474*unit_num/16;	
			if(a==9&&b==8)
				return unit_num/16;	
			if(a==9&&b==9)
				return 16*unit_num/16;
		}
	private:
		char Wei_unit[10][5]={"t","kg","g","mg","斤","担","两","钱","lb","oz"} ; 
		int i,x;
};


class Temperature {
	public:
		int Judge( char* unit_name)	
		{
			for(i=0;i<5;i++)
			{
				if(strcmp(unit_name,Temp_unit[i])==0)
					x=i;
			}
			return x;	
		}	
		double Operation(int a,int b,double unit_num)
	 	{
	 		if(a==0&&b==0)
				return unit_num;
			if(a==0&&b==1)
				return 9*unit_num/5+32;
			if(a==0&&b==2)
				return unit_num+273.15;
			if(a==0&&b==3)
				return 5*(273.15+unit_num)/9;
			if(a==0&&b==4)
				return 1.25*unit_num;
				
			if(a==1&&b==0)
				return 5*(unit_num-32)/9;
			if(a==1&&b==1)
				return unit_num;
			if(a==1&&b==2)
				return 5*unit_num/9+255.3722222;
			if(a==1&&b==3)
				return 5*(5*unit_num/9-32+273.15)/9;
			if(a==1&&b==4)
				return 1.25*(5*unit_num/9-32);
	 		
	 		if(a==2&&b==0)
				return unit_num-273.15;
			if(a==2&&b==1)
				return 9*(unit_num-273.15)/5+32;
			if(a==2&&b==2)
				return unit_num;
			if(a==2&&b==3)
				return 5*unit_num/9;
			if(a==2&&b==4)
				return 1.25*(unit_num-273.15);
	 		
	 		if(a==3&&b==0)
				return 9*unit_num/5-273.15;
			if(a==3&&b==1)
				return 9*(9*unit_num/5-273.15)/5+32;
			if(a==3&&b==2)
				return 9*unit_num/5;
			if(a==3&&b==3)
				return unit_num;
			if(a==3&&b==4)
				return 1.25*9*unit_num/5-273.15;
	 		
	 		if(a==4&&b==0)
				return unit_num/1.25;
			if(a==4&&b==1)
				return 9*unit_num/6.25+32;
			if(a==4&&b==2)
				return unit_num/1.25+273.15;
			if(a==4&&b==3)
				return 5*(unit_num/1.25+273.15)/9;
			if(a==4&&b==4)
				return unit_num;		

	 	}
	private:
		char Temp_unit[5][5]={"C","F","K","Ra","Re"} ; 
		int i,x;
};

class Time {
	public:
		int Judge( char* unit_name)	
		{
			for(i=0;i<6;i++)
			{
				if(strcmp(unit_name,Time_unit[i])==0)
					x=i;
			}
			return x;	
		}	
		double Operation(int a,int b,double unit_num)
		{
			if(a==0&&b==0)
				return unit_num;
			if(a==0&&b==1)
				return 12*unit_num;
			if(a==0&&b==2)
				return 360*unit_num;
			if(a==0&&b==3)
				return 360*24*unit_num;
			if(a==0&&b==4)
				return 360*24*60*unit_num;
			if(a==0&&b==5)
				return 360*24*60*60*unit_num;
			
			if(a==1&&b==0)
				return unit_num/12;
			if(a==1&&b==1)
				return unit_num;
			if(a==1&&b==2)
				return 30*unit_num;
			if(a==1&&b==3)
				return 30*24*unit_num;
			if(a==1&&b==4)
				return 30*24*60*unit_num;
			if(a==1&&b==5)
				return 30*24*60*60*unit_num;
			
			if(a==2&&b==0)
				return unit_num/12/30;
			if(a==2&&b==1)
				return unit_num/30;
			if(a==2&&b==2)
				return unit_num;
			if(a==2&&b==3)
				return 24*unit_num;
			if(a==2&&b==4)
				return 24*60*unit_num;
			if(a==2&&b==5)
				return 24*60*60*unit_num;
			
			if(a==3&&b==0)
				return unit_num/12/30/24;
			if(a==3&&b==1)
				return unit_num/30/24;
			if(a==3&&b==2)
				return unit_num/24;
			if(a==3&&b==3)
				return unit_num;
			if(a==3&&b==4)
				return 60*unit_num;
			if(a==3&&b==5)
				return 60*60*unit_num;
			
			if(a==4&&b==0)
				return unit_num/12/30/24/60;
			if(a==4&&b==1)
				return unit_num/30/24/60;
			if(a==4&&b==2)
				return unit_num/24/60;
			if(a==4&&b==3)
				return unit_num/60;
			if(a==4&&b==4)
				return unit_num;
			if(a==4&&b==5)
				return 60*unit_num;
			
			if(a==5&&b==0)
				return unit_num/12/30/24/60/60;
			if(a==5&&b==1)
				return unit_num/30/24/60/60;
			if(a==5&&b==2)
				return unit_num/24/60/60;
			if(a==5&&b==3)
				return unit_num/60/60;
			if(a==5&&b==4)
				return unit_num/60;
			if(a==5&&b==5)
				return unit_num;	
		}
	private:
		char Time_unit[6][5]={"年","月","日","时","分","秒"} ; 
		int i,x;
};

class Data_storage {
	public:
		int Judge( char* unit_name)	
		{
			for(i=0;i<8;i++)
			{
				if(strcmp(unit_name,Datastg_unit[i])==0)
					x=i;
			}
			return x;	
		}	
		double Operation(int a,int b,double unit_num)
		{
			if(a==0&&b==0)
				return unit_num;
			if(a==0&&b==1)
				return 1024*unit_num;
			if(a==0&&b==2)
				return 9.09e-13*unit_num;
			if(a==0&&b==3)
				return 9.31e-10*unit_num;
			if(a==0&&b==4)
				return 9.54e-7*unit_num;
			if(a==0&&b==5)
				return 0.00098*unit_num;
			if(a==0&&b==6)
				return 1024*1024*unit_num;	
			if(a==0&&b==7)
				return 1024*1024*8*unit_num;
			
			if(a==1&&b==0)
				return unit_num/1024;
			if(a==1&&b==1)
				return unit_num;
			if(a==1&&b==2)
				return 9.09e-13*unit_num/1024;
			if(a==1&&b==3)
				return 9.31e-10*unit_num/1024;
			if(a==1&&b==4)
				return 9.54e-7*unit_num/1024;
			if(a==1&&b==5)
				return 0.00098*unit_num/1024;
			if(a==1&&b==6)
				return 1024*1024*unit_num/1024;	
			if(a==1&&b==7)
				return 1024*1024*8*unit_num/1024;
			
			if(a==2&&b==0)
				return 1.1e12*unit_num;
			if(a==2&&b==1)
				return 1.13e15*unit_num;
			if(a==2&&b==2)
				return unit_num;
			if(a==2&&b==3)
				return 1024*unit_num;
			if(a==2&&b==4)
				return 1024*1024*unit_num;
			if(a==2&&b==5)
				return 1.07e9*unit_num;
			if(a==2&&b==6)
				return 1.15e18*unit_num;	
			if(a==2&&b==7)
				return 9.22e18*unit_num;
			
			if(a==3&&b==0)
				return 1.1e12*unit_num/1024;
			if(a==3&&b==1)
				return 1.13e15*unit_num/1024;
			if(a==3&&b==2)
				return unit_num/1024;
			if(a==3&&b==3)
				return unit_num;
			if(a==3&&b==4)
				return 1024*1024*unit_num/1024;
			if(a==3&&b==5)
				return 1.07e9*unit_num/1024;
			if(a==3&&b==6)
				return 1.15e18*unit_num/1024;	
			if(a==3&&b==7)
				return 9.22e18*unit_num/1024;
			
			if(a==4&&b==0)
				return 1.1e12*unit_num/1024/1024;
			if(a==4&&b==1)
				return 1.13e15*unit_num/1024/1024;
			if(a==4&&b==2)
				return unit_num/1024/1024;
			if(a==4&&b==3)
				return unit_num/1024;
			if(a==4&&b==4)
				return unit_num;
			if(a==4&&b==5)
				return 1.07e9*unit_num/1024/1024;
			if(a==4&&b==6)
				return 1.15e18*unit_num/1024/1024;	
			if(a==4&&b==7)
				return 9.22e18*unit_num/1024/1024;
			
			if(a==5&&b==0)
				return 1.1e12*unit_num/1024/1024/1024;
			if(a==5&&b==1)
				return 1.13e15*unit_num/1024/1024/1024;
			if(a==5&&b==2)
				return unit_num/1024/1024/1024;
			if(a==5&&b==3)
				return unit_num/1024/1024;
			if(a==5&&b==4)
				return unit_num/1024;
			if(a==5&&b==5)
				return unit_num;
			if(a==5&&b==6)
				return 1.15e18*unit_num/1024/1024/1024;	
			if(a==5&&b==7)
				return 9.22e18*unit_num/1024/1024/1024;
			
			if(a==6&&b==0)
				return 1.1e12*unit_num/1024/1024/1024/1.07e9;
			if(a==6&&b==1)
				return 1.13e15*unit_num/1024/1024/1024/1.07e9;
			if(a==6&&b==2)
				return unit_num/1024/1024/1024/1.07e9;
			if(a==6&&b==3)
				return unit_num/1024/1024/1.07e9;
			if(a==6&&b==4)
				return unit_num/1024/1.07e9;
			if(a==6&&b==5)
				return unit_num/1.07e9;
			if(a==6&&b==6)
				return unit_num;	
			if(a==6&&b==7)
				return 8*unit_num;
			
			if(a==6&&b==0)
				return 1.1e12*unit_num/1024/1024/1024/1.07e9/8;
			if(a==6&&b==1)
				return 1.13e15*unit_num/1024/1024/1024/1.07e9/8;
			if(a==6&&b==2)
				return unit_num/1024/1024/1024/1.07e9/8;
			if(a==6&&b==3)
				return unit_num/1024/1024/1.07e9/8;
			if(a==6&&b==4)
				return unit_num/1024/1.07e9/8;
			if(a==6&&b==5)
				return unit_num/1.07e9/8;
			if(a==6&&b==6)
				return unit_num/8;	
			if(a==6&&b==7)
				return unit_num;	
		}
	private:
		char Datastg_unit[8][5]={"MB","KB","EB","PB","TB","GB","B","bit"} ; 
		int i,x;
};




int main ()
{
	int a,b;				//用于接收 要被换算单位（字符串）在字符数组中位置对应的 x 和接收想换算出来的单位（字符串）在字符数组中位置对应的 x  
	char index[20];			//用于接收填入的单位类型 
	double num1,num2;		//num1 用于接收 要被换算的数值    num2 用于储存 换算出来的数值 
	char unit1[8],unit2[8];		//分别用于接收  要被换算的单位名称（字符串） 和 换算出来的单位名称（字符串） 
	cout<<"(可供换算单位类型(请选一个填入)：length、weigth、temperature、time、data_storage ): ";   
	cin>>index;				//接收填入的单位类型过程 
	cout<<endl;
	
	if(strcmp(index,"length")==0)
		cout<<"(注：只提供 km、m、dm、cm、mm、um、nm、里、丈、尺、寸、分、厘  之间的换算; 区分大小写，有英文的只能填英文。)"<<endl;    //提示输入范围 
	if(strcmp(index,"weigth")==0)
		cout<<"(注：只提供 t、kg、g、mg、斤、担、两、钱、lb(磅)、oz(盎司)  之间的换算；区分大小写，有英文的只能填英文。)"<<endl; 
	if(strcmp(index,"temperature")==0)
		cout<<"(注：只提供 C(摄氏度)、F(华氏度)、K(开氏度)、Ra(兰氏度)、Re(列氏度)  之间的换算；区分大小写，有英文的只能填英文。)"<<endl; 
	if(strcmp(index,"time")==0)
		cout<<"(注：只提供 年(按360天算)、月(按30天算)、日、时、分、秒  之间的换算；只能填汉字。)"<<endl;	
	if(strcmp(index,"data_storage")==0)
		cout<<"(注：只提供 MB、KB、EB、PB、TB、GB、B、bit  之间的换算；区分大小写)"<<endl; 
		
		
			
	cout<<endl;		
	cout<<"请输入 要被换算 的数值和单位名称（用空格隔开）: ";
	cin>>num1>>unit1;          //接收 要被换算单位的数值和名称的过程 
	cout<<endl;
	cout<<"请输入 想换算出来 的单位名称: ";
	cin>>unit2;            // 接收 换算出来单位名称过程 
	
	if(strcmp(index,"length")==0)              //判断想换算那种单位类型，并分别调用该类的成员函数 
	{
		Length l;
		a=l.Judge(unit1);            //接收 要被换算单位（字符串）在字符数组中位置过程 
		b=l.Judge(unit2);            //接收 想换算出来的单位（字符串）在字符数组中位置过程 
		
		num2=l.Operation(a,b,num1);     //根据单位关系得出换算出来的数值 
	}
	
	
	else if(strcmp(index,"weigth")==0)
	{
		Weigth m;
		a=m.Judge(unit1);
		b=m.Judge(unit2);
		
		num2=m.Operation(a,b,num1);
	}
	
	else if(strcmp(index,"temperature")==0)
	{
		Temperature T;
		a=T.Judge(unit1);
		b=T.Judge(unit2);
		
		num2=T.Operation(a,b,num1);
	}
	
	else if(strcmp(index,"time")==0)
	{
		Time t;
		a=t.Judge(unit1);
		b=t.Judge(unit2);
		
		num2=t.Operation(a,b,num1);
	}
	
	else if(strcmp(index,"data_storage")==0)
	{
		Data_storage d;
		a=d.Judge(unit1);
		b=d.Judge(unit2);
		
		num2=d.Operation(a,b,num1);
	}
	
	else
	{
		cout<<"SORRY! 本程序未录入这种单位类型。"<<endl;
	}
	cout<<endl;
	cout<<"换算结果: "<<num1<<" "<<unit1<<" = "<<num2<<" "<<unit2<<endl;      //输出换算结果 
	return 0;
}
