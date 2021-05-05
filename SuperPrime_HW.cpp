#include <stdio.h>
#include <stdbool.h>
bool prime(int n)
{

	int m;
	if(n<1)
	return false;
	for(m=2;m*m<=n;m++)
	if(n%m==0)
	return false;
	return true;
 } 

 int main()
 {
 	int a,b,c,j,k,l;
 	int i,n,max;
 	int sum=0,num=0;
 	for(i=100;i<999;i++)
 	{
 		a=i/100;b=(i-a*100)/10;c=i%10;
		 j=a+b+c;
		 k=a*b*c;
		 l=a*a+b*b+c*c;
		 if(prime(i)&&prime(j)&&prime(k)&&prime(l))
		 {sum+=i;num++;max=i;
		 }
	 }
	 printf("%d\n%d\n%d",num,sum,max);
	 return 0;
 }
