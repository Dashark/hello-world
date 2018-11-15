#include <stdio.h>
#include <math.h>
int main(void)
{
	int m,n,a,b,c,d,e,f,g,h,num;
	n=1;
	scanf("%d",&num);
	a=num%10;
	b=(num/10)%10;
	c=(num/100)%10;
	d=(num/1000)%10;
	for(m=2;m<sqrt(num);m++)
	{
		if(num%m==0)
		{
			n=0;
			break;
		}
	}
	e=a+b+c+d;
	for(m=2;m<sqrt(e);m++)
	{
		if(e%m==0)
		{
			n=0;
			break;
		}
	}
	if(d==0)
	f=a*b*c;
	else
	f=a*b*c*d;
	for(m=2;m<sqrt(f);m++)
	{
		if(g%m==0)
		{
			n=0;
			break;
		}
	}
	g=a*a+b*b+c*c+d*d;
	for(m=2;m<sqrt(g);m++)
	{
		if(g%m==0)
		{
			n=0;
			break;
		}
	}
	if(n==0)
	printf("这个数不是超级素数。");
	else
	printf("这个数是超级素数。");
	return 0;
}
