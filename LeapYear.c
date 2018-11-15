#include <stdio.h> 
int main() 
{
	int a,b,c,d;
	scanf("%d",&a);
	b=a%10;
	c=(a/10)%10;
	d=a/100;
	if(b==0 && c==0)
	{
		if(d%4==0)
		printf("这年是闰年。");
		else
		printf("这年不是闰年。"); 
	} 
	else
	{
		if(a%4==0)
		printf("这年是闰年。");
		else
		printf("这年不是闰年。");
	}
	return 0;
}
