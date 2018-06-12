// G: 矩阵旋转
// 题目描述
// 任意输入两个9阶以下矩阵，要求判断第二个是否是第一个的旋转矩阵，如果是，输出旋转角度（0、90、180、270），如果不是，输出-1。 要求先输入矩阵阶数，然后输入两个矩阵，每行两个数之间可以用任意个空格分隔。行之间用回车分隔，两个矩阵间用任意的回车分隔。
// 输入描述:
// 输入有多组数据。
// 每组数据第一行输入n(1<=n<=9)，从第二行开始输入两个n阶矩阵。
//
// 输出描述:
// 判断第二个是否是第一个的旋转矩阵，如果是，输出旋转角度（0、90、180、270），如果不是，输出-1。
// 如果旋转角度的结果有多个，则输出最小的那个。
//
// 输入
// 3
// 1 2 3
// 4 5 6
// 7 8 9
// 7 4 1
// 8 5 2
// 9 6 3
//
// 输出
// 90

#include <iostream>
#include <algorithm>

using namespace std;

void transform(int n,int** a)
{
	int b[n][n];
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++) b[j][n-1-i] = *((int*)a+i*n+j);
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++) *((int*)a+i*n+j) = b[i][j];
	}
}

bool judgeEqual(int** a,int **b,int n)
{
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++) if(*((int*)a+n*i+j) != *((int*)b+n*i+j)) return false;
	}
	return true;
}

int main()
{
	int n; cin >> n;
	int a[n][n],b[n][n];
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++) cin >> a[i][j];
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++) cin >> b[i][j];
	}
	//transform(n,(int**)a);
	for(int i = 0;i < 4;i++)
	{
		if(judgeEqual((int**)a,(int**)b,n)==true)
		{
			cout << 90*i << endl;
			return 0;
		}
		transform(n,(int**)a);
	}
	cout << "-1";
	return 0;
}
