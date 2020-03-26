#include<stdio.h>
int Sub(int mon,int dat);
void Lunar(int sub);
int main()
{
	printf("请输入2020年的公历，如“1月1日”：");
	int mon,dat,sub;
	scanf("%d月%d日",&mon,&dat);
	sub=Sub(mon,dat);
	Lunar(sub);
	return 0;
}
int Sub(int mon,int dat)
{
	int sub=0;
	switch(mon){
		case 1:break;
		case 2:sub+=31;
		break;
		case 3:sub+=60;
		break;
		case 4:sub+=91;
		break;
		case 5:sub+=121;
		break;
		case 6:sub+=152;
		break;
		case 7:sub+=182;
		break;
		case 8:sub+=213;
		break;
		case 9:sub+=244;
		break;
		case 10:sub+=274;
		break;
		case 11:sub+=305;
		break;
		case 12:sub+=336;
		break;
	}
	sub+=dat;
	return sub;
}

void Lunar(int sub)
{
	char zhong[10][3]={"一","二","三","四","五","六","七","八","九","十"} ;
	if(sub<25){
		printf("腊月");
		sub+=6;
	}
	else if(sub<54){
		printf("一月");
		sub-=24;
	}
	else if(sub<84){
		printf("二月");
		sub-=53;
	}
	else if(sub<114){
		printf("三月");
		sub-=83;
	}
	else if(sub<144){
		printf("四月");
		sub-=113;
	}
	else if(sub<173){
		printf("闰四月");
		sub-=143;
	}
	else if(sub<203){
		printf("五月");
		sub-=172;
	}
	else if(sub<232){
		printf("六月");
		sub-=202;
	}
	else if(sub<261){
		printf("七月");
		sub-=231;
	}
	else if(sub<291){
		printf("八月");
		sub-=260;
	}
	else if(sub<320){
		printf("九月");
		sub-=290;
	}
	else if(sub<350){
		printf("十月");
		sub-=319;
	}
	else {
		printf("十一月");
		sub-=349;
	}
	
	if(sub<=10){
		printf("初");
		printf("%s",zhong[sub-1]);  
	}
	else if(sub<20){
		printf("十");
		sub=sub-10;
		printf("%s",zhong[sub-1]); 
	}
	else if(sub=20)
		printf("二十");
	else if(sub<30){
		printf("廿");
		sub=sub-20;
		printf("%s",zhong[sub-1]); 
	}
	else printf("三十");
}

