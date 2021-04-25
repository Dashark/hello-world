#include<stdio.h>
int  judge(int x);

int main()
{
	int i,cnt=0,sum=0,max;
	for(i=100;i<1000;i++)
	{
		int t=i,b,a1=1,a2=0,a3=0;
		do
		{
			b=t%10;a1*=b;a2+=b;
			a3+=b*b;t/=10;
		}
    
    while(t>0);
		if(judge(i)==0&&judge(a1)==0&&judge(a2)==0&&judge(a3)==0)
     {
		cnt++;
		sum+=i;
		max=i;
	    }
	}
	printf("num:%d\n",cnt);
	printf("sum:%d\n",sum);
	printf("max:%d\n",max); 
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
