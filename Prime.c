/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积
以及所有数字的平方和都是素数.例如113就是一个超级素数.
求[100,9999]之内:
(1)超级素数的个数.
(2)所有超级素数之和.
(3)最大的超级素数.*/
#include <stdio.h>
#include <math.h>

int sum_bit(int a, int b, int c, int d) { //和 
	return (a + b + c + d);
}

int multi_bit(int a, int b, int c, int d) { //积 
	if (a != 0)
	return a * b * c * d;
	else 
	return b * c * d;
}

int square_sum_bit(int a, int b, int c, int d) {
	return (a * a + b * b + c * c + d * d);
}

int isprime(int number) {
	if (number == 1 || number == 0) {
		return 0;
	}
	else if (number == 2 || number == 3) {
		return 1;
	}
	else {
		int flag = 0;
		int i;
		for (i = 2; i <= sqrt(number); i++) {
			if (number % i != 0) {
				continue;
			}
			else {
				flag = 1;
				break;
			}
		} 
		if (flag) {
			return 0;
		}
		else {
			return 1;
		}
	}

}

int main() {
	int count = 0;
	long long int ss = 0;
	int max = 0;
	int num;
	for (num = 101; num < 9999; num++) {
		int a = num / 1000;
		int b = (num % 1000) / 100;
		int c = (num % 100) / 10;
		int d = (num % 10);
			
		if(isprime(num)&&isprime(sum_bit(a,b,c,d))&&isprime(multi_bit(a,b,c,d))&&isprime(square_sum_bit(a,b,c,d))) {
			count++;
			ss += num;
			max = num;
		}
	}
	printf("%d %d %d", count, ss, max);
	
	return 0;
}
