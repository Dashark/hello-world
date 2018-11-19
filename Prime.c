/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.求[100,9999]之内:(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
//2018/11/14 更新
#include<stdio.h>
int sum_bit(int num)
{
	int sum = 0;
	while (num / 10 > 0)
	{
		sum += num % 10;
		num = num / 10;

	}
	sum += num;

	return sum;
}

int multi_bit(int num) {
	int multi = 1;
	while (num / 10 > 0)
	{
		multi *= num % 10;
		num = num / 10;

	}
	multi *= num;

	return multi;
}

int square_sum_bit(int num) {
	int square = 0;
	while (num / 10 > 0)
	{
		square += (num % 10)*(num % 10);
		num = num / 10;

	}
	square += (num)*(num);

	return square;
}

bool isprime(int num) {
	int FLAG = 1;
	for (int i = 2; i*i <= num; i++)
	{
		if (num%i == 0 || num == 1)
		{

			FLAG = 0;
			break;

		}
	}
	if (FLAG)return 1;
	else return 0;
}

int main(void) {
	int num = 0;
	long long sum = 0;
	int max = -100;
	for (int a = 100; a <= 9999; a++)
	{

		if (isprime(a) && isprime(sum_bit(a)) && isprime(multi_bit(a)) && isprime(square_sum_bit(a)))
		{
			num++;
			sum += a;
			if (max < a)max = a;
		}
	}
	printf("%d,%lld,%d", num, sum, max);
	return 0;
}