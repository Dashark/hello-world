#include <stdio.h>
#include <math.h> 
int h[10];
int main() 
{
	int a,b,c,d,e;
	c=1;
	scanf("%d",&a);
	do
	{
		e=a/pow(10,c);
		b=a/pow(10,c-1);
		h[c]=b%10;
		c++;
	}while(e>0);
	for(d=c-1;d>0;d--)
	printf("%d ",h[d]);
	return 0;
}
