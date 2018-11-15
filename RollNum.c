#include <stdio.h> 
#include <math.h>
int h[100];
int main(void)  
{
	int a,b,c,d,e,f,x;
	scanf("%d",&x);
	b=1;e=1;
	do 
	{
		f=x/pow(10,b);
		d=x/pow(10,b-1);
		h[b]=d%10;
		b+=1;
	}while(f>0);
	for(c=1;c<=b/2;c++)
	{
		if(h[c]==h[b-c])
		e=1;
		else
		{
			e=0;
			break;
		}
	}
	if(e==1)
	printf("该数为回文数。");
	else
	printf("该数不为回文数。");
	return 0;
}
