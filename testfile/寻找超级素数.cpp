#include<stdio.h>
int main()
{
	int prime[1000];
	int o=0;
	for(int i=100;i<1000;i++)  //100~999
	{
		if(i%2==0 || i%3==0 || i%5==0)
		{
			continue;
		}
		
		int q=0;
		for(int j=2;j<i;j++)
		{
			if(i%j==0)
			{
				q=1;
				break;
			}
		}
		if(q==1)
		{
			continue;
		}
		else if(q==0)
		{
			prime[o]=i;
			o++;
		}
		
	}
/*	for(int v=0;v<o;v++)
	{
		printf("%d ",prime[v]);
	}
	printf("\n");*/
	int superprime[50],t=0;
	for(int u=0;u<o;u++)
	{
		int a,b,c;
		a=prime[u]/100;
		c=prime[u]%10;
		b=(prime[u]-100*a-c)/10;
		int x=a+b+c,y=a*b*c,z=a*a+b*b+c*c;//构造出三个数 
		
		if(y==0)
		{
			continue;
		}
		int p1=0;
		for(int j=2;j<x;j++)
		{
			if(x%j==0)
			{
				p1=1;
				break;
			}
		}
		if(p1==1)
		{
			continue;
		}
		else if(p1==0)
		{
			      int p2=0;
		         for(int j=2;j<y;j++)
		        {
			        if(y%j==0)
			          {
				         p2=1;
				         break;
			          }
		        }
		     if(p2==1)
		          {
			           continue;
		          }
		     else if(p2==0)
		          {
			           int p3=0;
		               for(int j=2;j<z;j++)
		               {
			              if(z%j==0)
			                {
				                p3=1;
				                break;
			                }
		               }
		               if(p3==1)
		                 { 
			               continue;
		                 }
		               else if(p3==0)
		                 {
			                superprime[t]=prime[u];
		                    	t++;
		                 }
			            
		          } 
		}
		
	}
	for(int u1=0;u1<t;u1++)
	{
		printf("%d ",superprime[u1]);
		
	}
	
	return 0;
}
