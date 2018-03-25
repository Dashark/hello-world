/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.求[100,9999]之内:(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
#include<stdio.h>
#define NMAX 10000
int is_prime[NMAX];

bool isprime(int num);

int sum_bit(int num) {
	int sum=0;
	while(num!=0)
	{
		sum+=num%10;
		num/=10;
	}
	return sum;
}

int multi_bit(int num) {
	int product=1;
	while(num!=0)
	{
		product*=num%10;
		num/=10;
	}
	return product;
}

int square_sum_bit(int num) {
	int sum=0;
	while(num!=0)
	{
		sum+=(num%10)*(num%10);
		num/=10;
	}
	return sum;
}

bool isprime(int num) {
	return is_prime[num];
}

void init_prime()
{
	is_prime[1]=0;
	for(int i=2;i<NMAX;i++)
	{
		is_prime[i]=!is_prime[i];
		if(is_prime[i])
			for(int j=i+i;j<NMAX;j+=i)
				is_prime[j]=1;
	}
	return ;
}

int main() {
	init_prime();
	for(int i=100;i<=9999;i++)
		if(isprime(i)&&isprime(sum_bit(i))&&isprime(multi_bit(i))&&isprime(square_sum_bit(i)))
			printf("Found Super Prime:%d\n",i);
	return 0;
}
