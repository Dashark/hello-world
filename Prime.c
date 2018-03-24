#include<math.h>
/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.求[100,9999]之内:(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
int sum_bit(int num) {
	if (num >= 1000) {
		int q = num / 1000;
		int b = (num % 1000) / 100;
		int s = (num % 100) / 10;
		int g = num % 10;
		return g + s + b + q;
	}
}

int multi_bit(int num) {
	int q = num / 1000;
	int b = (num % 1000) / 100;
	int s = (num % 100) / 10;
	int g = num % 10;
	return g * s*b*q;
}

int square_sum_bit(int num) {
	int q = num / 1000;
	int b = (num % 1000) / 100;
	int s = (num % 100) / 10;
	int g = num % 10;
	return g * g + s * s + b * b + q * q;
}

bool isprime(long number)
{
	if (number == 1)
	{
		return false;
	}
	for (int j = 2; j <= sqrt(double(number)); j++)
	{
		if (number%j == 0)
		{
			return false;
		}
	}
	return true;
}

int main() {
	int count = 0, sum = 0, max = -1;
	for (int i = 100; i < 10000; i++) {
		if (isprime(i) && isprime(sum_bit(i)) && isprime(multi_bit(i)) && isprime(square_sum_bit(i)))
		{
			count++;
			sum += i;
			if (i > max)max = i;

		}
	}
	printf("%d %d %d", count, sum, max);
	return 0;
		//to do sth
}