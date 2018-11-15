#include <stdio.h>
#include <math.h> 
int main() 
{
	int a,b,c;
	c=1;
	scanf("%d",&a);
	for(b=2;b<sqrt(a);b++)
	{
		if(a%b==0)
		{
			c=0;
			break;
	    }
	}
	if(c==1)
	printf("这个数是素数。");
	else
	printf("这个数不是素数。");
	return 0;
}
