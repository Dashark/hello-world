#include <stdio.h>
#include <stdlib.h>
/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.求[100,9999]之内:
(1)超级素数的个数.
(2)所有超级素数之和.
(3)最大的超级素数.*/

int a,b,c,d,n,sum,multi,square;
int Num[9999];
int bit(int num)
{
	a=num%10;
	b=(num-a)/10%10;
	c=(num-a-b*10)%10;
	d=num/1000;
	
}
int sum_bit(int num) 
{
	bit(num);
	sum=a+b+c+d;
	return sum;
}
int multi_bit(int num)
{
	bit(num);
	if(d!=0)
	{
		multi=a*b*c*d;
	}
	else
	{
		multi=a*b*c;
	}
	return multi;
}
int square_bit(int num)
{
	bit(num);
	square=a*a+b*b+c*c+d*d;
	return square;
}
bool isprime(int num)
{
	int i;
	for(i=2;i<num;i++)
	{
		if(num%i==0)
		return false;break;
	}
	return true;
}
int main()
{
	int i,j,k=0;
	n=0;
	for(j=100;j<=9999;j++)
	{
		if(isprime(j)&&isprime(sum_bit(j))&&isprime(multi_bit(j))&&isprime(square_bit(j))) 
		Num[n]=j;n++;
	}
	for(i=0;i<n;i++)
	k=k+Num[i];
	printf("有%d个超级素数\n"，n);
	printf("最大的超级素数为%d\n",Num[n-1]);
	printf("和是%d",k);
	return 0;
}
