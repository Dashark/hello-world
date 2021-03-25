#include<stdio.h>
int  judge(int x);
int main()
{
	int i;
	int cnt=0;
	int sum=0;
	int max;
	for(i=100;i<=999;i++)
	{
		int t=i;
		int b;
		int a1=1,a2=0,a3=0;
		do
		{
			b=t%10;
			a1*=b;
			a2+=b;
			a3+=b*b;
			t/=10;
		}while(t>0);
		if(judge(i)==0&&judge(a1)==0&&judge(a2)==0&&judge(a3)==0){
		cnt++;
		sum+=i;
		max=i;
	    }
	}
	printf("超级素数的个数为%d\n",cnt);
	printf("所有超级素数之和为%d\n",sum);
	printf("最大的超级素数为%d\n",max); 
}
int  judge(int x)
{
	int i;
	for(i=2;i<=x;i++)
	{
		if(x%i==0&&i!=x)
		break;
		if(x%i==0&&i==x)
		return 0;
	}
	return 1;
}
