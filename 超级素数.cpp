#include<stdio.h> 
f(int n)
{
	int z=1;
	int i;
	for(i=2;i<=n-1;i++)
	{
		if(n%i==0)
		{
			z=0;
			break;
		}
	}
	return (z);
}
int main()
{
	int a,b,c,m;
	int num,sum,max;
	num=0,sum=0,max=0;
	
	for(m=100;m<=999;m++)
	{
			a=m/100;
			b=m%100/10;
			c=m%10;
			int x,y,z;
	        x=a+b+c;
	        y=a*b*c;
	        z=a*a+b*b+c*c;
			if((m<1000)&&(f(m)==1)&&(f(x)==1)&&(f(y)==1)&&(f(z)==1))
			{
				num+=1;
				sum+=m;
				max=m;
			}
	}
	printf("[100,999]之内超级素数的个数为%d\n",num);
	printf("[100,999]之内所有超级素数之和为%d\n",sum);
	printf("[100,999]之内最大的超级素数为%d\n",max);
	return 0;
 } 
