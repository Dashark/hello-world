#include <iostream>
//判断一个数是不是素数
int isPrime(int x) {
	int state = 1;
	if (x <= 0) {
		state = 0;
	}
	if (x > 2) {
		for (int i = 2; i < x && state == 1; i++) {
			if (x % i == 0) {
				state = 0;
				break;
			}
		}
	}
	return state;
} //返回1则是素数
int main() {
	//超级素数：该数本身，所有数字之和，所有数字之积以及所有数字的平方和都是素数，
	//例如113，求[100,999]之内：
	//超级素数的个数；所有超级素数之和；最大的超级素数
	int num[900];
	for (int i = 0; i < 900; i++) {
		num[i] = i + 100;
	}
	int flag[900] = {0};
	for (int i = 0; i < 900; i++) {
		int a = num[i] / 100;
		int b = (num[i] % 100) / 10;
		int c = (num[i] % 100) % 10;
		if (isPrime(num[i]) == 1 && isPrime(a + b + c) == 1 && isPrime(a * b * c) == 1 && isPrime(a * a + b * b + c * c) == 1) {
			flag[i] = 1;
		} else {
			flag[i] = 0;
		}
	}
	int count=0; //超级素数的个数
	int sum=0; //超级素数之和
	int max=0;
	for (int i = 0; i < 900; i++) {
		if (flag[i] == 1) {
			count++;
			sum=sum+num[i];
			max=(max>num[i]?max:num[i]);
		}
	}
	std::cout<<"超级素数个数："<<count<<std::endl;
	std::cout<<"超级素数的和："<<sum<<std::endl;
	std::cout<<"最大的超级素数："<<max<<std::endl;
	return 0;
}
