// C: 约数的个数
// 题目描述
// 输入n个整数,依次输出每个数的约数的个数
// 输入描述:
// 输入的第一行为N，即数组的个数(N<=1000)
// 接下来的1行包括N个整数，其中每个数的范围为(1<=Num<=1000000000)
// 当N=0时输入结束。

// 输出描述:
// 可能有多组输入数据，对于每组输入数据，
// 输出N行，其中每一行对应上面的一个数的约数的个数。

// 输入

// 5
// 1 3 4 6 12

// 输出

// 1
// 2
// 3
// 4
// 6

#include <iostream>

using namespace std;

int number(long long n)
{
	int count = 0;
	for(int i = 1;i*i <= n;i++)
	{
		if(n%i == 0&&i*i != n)  count+=2;
		if(i*i == n) count++;
	}

	return count;
}

int main()
{
	int n; cin >> n;
	while(n--)
	{
		long long a; cin >> a;
		cout << number(a) << endl;
	}
	return 0;
}
