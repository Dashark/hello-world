// Description:
// 已知有n个矩阵,第i个矩阵的行数为a[i], 列数为a[i+1]。
// 试求把n个矩阵乘起来所需要的执行乘法的次数的最小值。
//
// Input:
// 第一行是一个正整数n，表示矩阵的个数。
// 第二行有n+1个整数，第i个整数表示a[i]。
//
// Output:
// 输出第一行有一个整数，将n个矩阵乘起来所要执行的乘法次数的最小值。
// Sample Input:
// 4
// 1 2 3 4 5
//
// Sample Output:
// 38
//
// Hint:
// 对于80%的数据 n <= 100
// 对于100%的数据 n <= 2000, a[i] <= 100


#include<iostream>

using namespace std;

struct Juzhen
{
	int row;
	int col;
};

int multiplicationNumber();

int main()
{
	int n;
	while(cin >> n)
	{
		int number[n];
		Juzhen juzhens[n];
		for(int i = 0;i <= n;i++) cin >> number[i];
		for(int i = 0;i < n;i++)
		{
			juzhens[i].row = number[i];
			juzhens[i].col = number[i+1];
		}
		int Thesmall[n+1][n+1];
		for(int i = 0;i <= n;i++)
			for(int j = 0;j <= n;j++) Thesmall[i][j] = 0; //i->j的最小值
		for(int r = 2;r <= n;r++)   //计算r个每组的最小值
		{
			for(int i = 0;i <= n-r;i++) //从 0 开始往后循环 计算从 i到i+r的最小值 ，r最小就是2，所以后面算的都是最小
			{
				int j = i+r-1;; //i->j j-r = r-1
				Thesmall[i][j] = Thesmall[i+1][j] + juzhens[i].row*juzhens[i].col*juzhens[j].col; //分成两段求
				for(int k = i+1;k < j;k++) //以K为分界点
				{
					int mid = Thesmall[i][k] + Thesmall[k+1][j] + juzhens[i].row* juzhens[k].col*juzhens[j].col;
					if(mid < Thesmall[i][j])  Thesmall[i][j] = mid;
				}
			}
		}
		cout << Thesmall[0][n-1] << endl;
	}
    return 0;
 }
