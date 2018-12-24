//被4整除的年份是闰年，但是00结尾的年份被400整除才是闰年。
//2018/11/14 更新
#include<stdio.h>
#include<stdlib.h>
int main() 
{
    //to do sth
	int year;		
	scanf("%d", &year);
	if (year % 4 == 0)
	{
		if (year % 100 != 0 || year % 400 == 0)
		{
			printf("闰年")；
		}
	}
	system("pause");
	return 0;
}
