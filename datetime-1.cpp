#include <stdio.h>
static char day_code[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},//非闰年月份数据
    {0,31,29,31,30,31,30,31,31,30,31,30,31},//闰年月份数据
};
static int year_code[]={
					 0x09,0x6d,0x46, //1970
					 0x54,0xAe,0xBB, //1971
					 0x04,0xAd,0x4f, //1972
					 0x0A,0x4d,0x43, //1973
					 0x4d,0x26,0xB7, //1974
					 0x0d,0x25,0x4B, //1975
					 0x8d,0x52,0xBf, //1976
					 0x0B,0x54,0x52, //1977
					 0x0B,0x6A,0x47, //1978
					 0x69,0x6d,0x3C, //1979
					 0x09,0x5B,0x50, //1980
					 0x04,0x9B,0x45, //1981
					 0x4A,0x4B,0xB9, //1982
					 0x0A,0x4B,0x4d, //1983
					 0xAB,0x25,0xC2, //1984
					 0x06,0xA5,0x54, //1985
					 0x06,0xd4,0x49, //1986
					 0x6A,0xdA,0x3d, //1987
					 0x0A,0xB6,0x51, //1988
					 0x09,0x37,0x46, //1989
					 0x54,0x97,0xBB, //1990
					 0x04,0x97,0x4f, //1991
					 0x06,0x4B,0x44, //1992
					 0x36,0xA5,0x37, //1993
					 0x0e,0xA5,0x4A, //1994
					 0x86,0xB2,0xBf, //1995
					 0x05,0xAC,0x53, //1996
					 0x0A,0xB6,0x47, //1997
					 0x59,0x36,0xBC, //1998
					 0x09,0x2e,0x50, //1999
					 0x0C,0x96,0x45, //2000
					 0x4d,0x4A,0xB8, //2001
					 0x0d,0x4A,0x4C, //2002
					 0x0d,0xA5,0x41, //2003
					 0x25,0xAA,0xB6, //2004
					 0x05,0x6A,0x49, //2005
					 0x7A,0xAd,0xBd, //2006
					 0x02,0x5d,0x52, //2007
					 0x09,0x2d,0x47, //2008
					 0x5C,0x95,0xBA, //2010
					 0x0B,0x4A,0x43, //2011
					 0x4B,0x55,0x37, //2012
					 0x0A,0xd5,0x4A, //2013
					 0x95,0x5A,0xBf, //2014
					 0x04,0xBA,0x53, //2015
					 0x0A,0x5B,0x48, //2016
					 0x65,0x2B,0xBC, //2017
					 0x05,0x2B,0x50, //2018
					 0x0A,0x93,0x45, //2019
					 0x47,0x4A,0xB9, //2020

	};
int* Conversion(int year,int month,int day);
char get_moon_day(char month_p,int table_addr);
bool isLeap(int year);
int main()
{
	char yue[12][5]={"正","二","三","四","五","六","七","八","九","十","十一","腊"};
	char ri[30][5]={"初一","初二","初三","初四","初五","初六","初七","初八","初九","初十",
	"十一","十二","十三","十四","十五","十六","十七","十八","十九","二十",
	"廿一","廿二","廿三","廿四","廿五","廿六","廿七","廿八","廿九","三十"} ;
	printf("请输入公历，如“2020年1月1日”：");
	int year,mon,dat,totalday;
	scanf("%d年%d月%d日",&year,&mon,&dat);
	int *p=Conversion(year,mon,dat);
	if(*(p+2)==*(p+3)-1)
	printf("阴历:闰%s月%s\n",yue[*p-1],ri[*(p+1)-1]);
	else
	printf("阴历:%s月%s\n",yue[*p-1],ri[*(p+1)-1]);
	return 0;
}


bool isLeap(int year){
	if((year%4==0&&year%100!=0)||(year%400==0))
	return 1;
	else
	return 0;
}

char get_moon_day(char month_p,int table_addr)
{
 char temp;
 switch (month_p){
	 case 1:{temp=year_code[table_addr]&0x08;
	 if (temp==0)return(0);else return(1);}
	 case 2:{temp=year_code[table_addr]&0x04;
	 if (temp==0)return(0);else return(1);}
	 case 3:{temp=year_code[table_addr]&0x02;
	 if (temp==0)return(0);else return(1);}
	 case 4:{temp=year_code[table_addr]&0x01;
	 if (temp==0)return(0);else return(1);}
	 case 5:{temp=year_code[table_addr+1]&0x80;
	 if (temp==0) return(0);else return(1);}
	 case 6:{temp=year_code[table_addr+1]&0x40;
	 if (temp==0)return(0);else return(1);}
	 case 7:{temp=year_code[table_addr+1]&0x20;
	 if (temp==0)return(0);else return(1);}
	 case 8:{temp=year_code[table_addr+1]&0x10;
	 if (temp==0)return(0);else return(1);}
	 case 9:{temp=year_code[table_addr+1]&0x08;
	 if (temp==0)return(0);else return(1);}
	 case 10:{temp=year_code[table_addr+1]&0x04;
	 if (temp==0)return(0);else return(1);}
	 case 11:{temp=year_code[table_addr+1]&0x02;
	 if (temp==0)return(0);else return(1);}
	 case 12:{temp=year_code[table_addr+1]&0x01;
	 if (temp==0)return(0);else return(1);}
	 case 13:{temp=year_code[table_addr+2]&0x80;
	 if (temp==0)return(0);else return(1);}
 }
}
int* Conversion(int year,int month,int day)
{
/*
month_p作为月份的指向，leap保存是否是闰年的数据，table_addr保存相关年份的year_code中的地址信息。flag_y是在处理闰月时的标志。
*/
 char temp1,temp2,temp3,month_p;
 int leap,temp4,table_addr,c;
 char flag_y;
 //定位year_code数据表地址,也就是找到阴历的数据信息。如输入的是1988年，则找到1988年的阴历数据。
 if(year<=2000)	
 table_addr=(year-1970)*3;
 else
 table_addr=(year-1970-1)*3;
 //定位数据表地址完成，现在table_addr中存放的是阴历数据的第一个字节的地址。

 //取当年春节所在的公历月份
 temp1=year_code[table_addr+2]&0x60; //只获取第三个字节的位6至位5，其他位清零。
 temp1=temp1/32;//右移五位，右移后temp1就是当年春节所在的公历月份
 //取当年春节所在的公历月份完成

 //取当年春节所在的公历日
 temp2=year_code[table_addr+2]&0x1f; //只获取第三个字节的位5至位0
 //取当年春节所在的公历日完成

 // 计算当年春年离当年元旦的天数,春节只会在公历1月或2月
 if(temp1==1){ //春节在一月
 temp3=temp2-1; 
 } 
 else{//春节在二月，需要加上一月的31天
 temp3=temp2+31-1;
 }
 // 计算当年春年离当年元旦的天数完成

 //计算阳历日期离当年元旦的天数
/*
算法示例：假设输入的是1988年3月5日。那么首先判断是否是闰年，然后计算3月之前月份的天数和，最后加上3月的5天减1,(1月份总天数)+(2月份总天数)+(3月份天数)得到 31+29+5=63
*/
//判断是否是闰年，闰年leap=1，非闰年leap=0
leap=isLeap(year);
temp4=0;//保存天数
for(c=1;c<month;++c)
temp4=temp4+day_code[leap][c];
temp4 = temp4+day;
 //计算阳历日期离当年元旦的天数完成

 //判断阳历日期在春节前还是春节后
 if (temp4>temp3) //阳历日期在春节后或就是春节当日使用下面代码进行运算
 {
	 temp4-=temp3;//(阳历日期离元旦的天数)减去(春年离元旦的天数)等于(阳历日期离春节的天数)
	 month=1;//month指示的月份，是真正的阴历月份
	/*
	month_p为月份指向,他的指向和month是有区别的，month_p指向的是year_code中的阴历月份数据，month_p可能是13，因为如果闰月，阴历年就会有13个月。而month指向的是真正的阴历月份，如果闰5月month值就是5，阳历日期在春节后或就是春节当日month_p的初始值为1。
	*/
	 month_p=1; 
	 flag_y=0;//flag_y是为了闰月设置的
	 if(get_moon_day(month_p,table_addr)==0)//判断大小月
	 temp1=29; //小月29天
	 else
	 temp1=30; //大月30天
	 temp2=year_code[table_addr]&0xf0;//year_code的第一个字节的位7至位4为闰月月份
	 temp2=temp2/16; //右移四位，从数据表中取该年的闰月月份,如为0则该年无闰月
	 while(temp4>temp1){//如果阳历日期离春节的天数大于当前阴历月份的天数，temp1初始为正月的天数 
		 temp4-=temp1;
		 month_p+=1;
		/*
		如果月份等于闰月月份，假设闰5月，那么阴历有两个5月，flag_y的作用就是保证第一次循环month的值不变，第二次循环month加1。从而保证计算两个5月。然而month_p的值加1两次，month_p的值可能达到13，既然闰月，这个阴历年就有13个月
		*/
		 if(month==temp2)
		 {
		 	if(flag_y)month+=1;
		 	flag_y=1; 
		 }
		 else
		 month+=1;
		 if(get_moon_day(month_p,table_addr)==0)//判断大小月
		 temp1=29;
		 else
		 temp1=30;
	 }
	 day=temp4;
 }
 else{
 	temp3-=temp4;//(阳历日期离元旦的天数)减去(春年离元旦的天数)等于(阳历日期离春节的天数)
	 month=12;//month指示的月份，是真正的阴历月份
	/*
	month_p为月份指向,他的指向和month是有区别的，month_p指向的是year_code中的阴历月份数据，month_p可能是13，因为如果闰月，阴历年就会有13个月。而month指向的是真正的阴历月份，如果闰5月month值就是5，阳历日期在春节后或就是春节当日month_p的初始值为1。
	*/
	 flag_y=0;//flag_y是为了闰月设置的
	 if(get_moon_day(month_p,table_addr)==0)//判断大小月
	 temp1=29; //小月29天
	 else
	 temp1=30; //大月30天
	 temp2=year_code[table_addr]&0xf0;//year_code的第一个字节的位7至位4为闰月月份
	 temp2=temp2/16; //右移四位，从数据表中取该年的闰月月份,如为0则该年无闰月
	 if(temp2)
	 month_p=13; 
	 else
	 month_p=12;
	 while(temp3>temp1){//如果阳历日期离春节的天数大于当前阴历月份的天数，temp1初始为正月的天数 
		 temp3-=temp1;
		 month_p-=1;
		/*
		如果月份等于闰月月份，假设闰5月，那么阴历有两个5月，flag_y的作用就是保证第一次循环month的值不变，第二次循环month加1。从而保证计算两个5月。然而month_p的值加1两次，month_p的值可能达到13，既然闰月，这个阴历年就有13个月
		*/
		 if(month==temp2)
		 {
		 	if(flag_y)
			 month-=1;
		 	flag_y=1; 
		 }
		 else
		 month-=1;
		 if(get_moon_day(month_p,table_addr)==0)//判断大小月
		 temp1=29;
		 else
		 temp1=30;
	 }
	 day=temp1-temp3;
 } 
//将计算后的数据
int a[]={month,day,temp2,month_p};
int *p=a;
return p;
}
                                
                                          
