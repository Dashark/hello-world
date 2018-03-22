/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.
求[100,9999]之内:
(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
#include<stdio.h> 

int a,b,c,d,count,sum,multi,square;
int super[1105];
void devide(int num)
{
	a=num%10;//个位 
	b=(num-a)/10%10;//十位 
	c=(num-a-b*10)/10/10%10;//百位 
	d=num/1000;//千位 
}

int sum_bit(int num)
{
	devide(num);
	sum=a+b+c+d;
    return sum;
}//和 

int multi_bit(int num) 
{
	devide(num);
	if(d!=0)
	multi=a*b*c*d;
	else 
	multi=a*b*c;
    return multi;
}//积 

int square_sum_bit(int num)
{
	devide(num);
	square=a*a+b*b+c*c+d*d;
    return square;
}//平方和

bool isprime(int num) 
{
	int i;
	if(num<2) return false;
	else if(num==2) return true;
	else
	{
		for(i=2;i<num;i++)
    	{
    		if(num%i==0)
            {
            	return false;
            	break;
	        }
    	}
    	return true;
	}
}//素数 

int main() 
{
	count=0;
	for(int i=100;i<=9999;i++)
	if(isprime(i)&&isprime(sum_bit(i))&&isprime(multi_bit(i))&&isprime(square_sum_bit(i)))
	{
		super[count]=i;
		count++;
	}
   if(isprime(113)&&isprime(sum_bit(113))&&isprime(multi_bit(113))&&isprime(square_sum_bit(113))) {};
   printf("超级素数有%d个\n",count);
   printf("最大的超级素数为%d\n",super[count-1]);
   int SUM=0;
   for(int j=0;j<count;j++)
   SUM+=super[j];
   printf("超级素数之和为%d\n",SUM);
   return 0;
    
}
