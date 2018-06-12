// D: 上楼楼梯
// 上N阶楼梯，一次可以走两阶或一阶，问有多少种上楼方式。
//
// 输入
// 正整数N,1<=N<=30
//
// 输出
// 上楼方式数
//
// 样例输入
// 6
//
// 样例输出
// 13

#include<iostream>

using namespace std;

int num[35];

int main()
{
	num[0] = 1;
	num[1] = 1;
	for(int i = 2;i <= 30;i++)
	{
		num[i] = num[i-1]+num[i-2];
	}
	int n;
	cin >> n;
	cout << num[n];
	return 0;
}
